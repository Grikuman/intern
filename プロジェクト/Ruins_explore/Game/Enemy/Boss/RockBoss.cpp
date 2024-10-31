/*
    �t�@�C��: RockBoss.cpp
    �N���X  : ��{�X�N���X
*/
#pragma once
#include "pch.h"
#include "RockBoss.h"
#include "Game/Player/Player.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/MyLib/InputManager.h"
#include "Libraries/MyLib/DebugString.h"
#include <cassert>
#include "WorkTool/Graphics.h"
#include "WorkTool/Collision.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

RockBoss::RockBoss(Player* player)
    :
    m_player{player},
    m_model{},
    m_ball{},
    m_RockBossSearch{},
    m_RockBossAttack{},
    m_RockBossDown{},
    m_position{},
    m_velocity{},
    m_angle{},
    m_isHit(false),
    m_isAlive(true)
{
    m_hp = MAXHP;
}

RockBoss::~RockBoss() {}

void RockBoss::Initialize(Vector3 position)
{
    // �R���e�L�X�g���擾����
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    // D3D�f�o�C�X���擾����
    auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();
    // �{�[����ǂݍ���
    m_ball = DirectX::GeometricPrimitive::CreateSphere(context, 2.f);
    // �ʒu��ݒ肷��
    m_position = position;

    // ���C�g��؂�ݒ�
    //m_model->UpdateEffects([](DirectX::IEffect* effect)
    //{
    //    // ���C�g������
    //    auto lights = dynamic_cast<DirectX::IEffectLights*>(effect);
    //    if (lights)
    //    {
    //        lights->SetLightEnabled(0, false);
    //        lights->SetLightEnabled(1, false);
    //        lights->SetLightEnabled(2, false);
    //        // ����������
    //        lights->SetAmbientLightColor(DirectX::Colors::Black);
    //    }
    //    // ���Ȕ���������
    //    auto basicEffect = dynamic_cast<DirectX::BasicEffect*>(effect);
    //    if (basicEffect)
    //    {
    //        basicEffect->SetEmissiveColor(DirectX::Colors::White);
    //    }
    //});

    //* �X�e�[�g���쐬���� *
    // �T�[�`���
    m_RockBossSearch = std::make_unique<RockBossSearch>(this);
    m_RockBossSearch->Initialize();
    // �A�^�b�N���
    m_RockBossAttack = std::make_unique<RockBossAttack>(this);
    m_RockBossAttack->Initialize();
    // �_�E�����
    m_RockBossDown = std::make_unique<RockBossDown>(this);
    m_RockBossDown->Initialize();

    // �X�e�[�g��ݒ肷��
    m_currentState = m_RockBossSearch.get();
}

void RockBoss::Update()
{
    m_isHit = false; 

    //�������Ă��邩�m�F����
    CheckAlive(); 
    if (m_isAlive)
    {
        //���݂̃X�e�[�g���X�V����
        m_currentState->Update();
    }

    // �v���C���[�Ƃ̓����蔻��
    Collision::GetInstance()->CheckHitRockBoss(this);
}

void RockBoss::Render()
{
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    auto view = Graphics::GetInstance()->GetViewMatrix();
    auto proj = Graphics::GetInstance()->GetProjectionMatrix();
    // ���݂̃X�e�[�g��`�悷��
    m_currentState->Render();
}

void RockBoss::Finalize()
{
    
}

// �o�E���f�B���O�X�t�B�A���擾����
BoundingSphere RockBoss::GetBoundingSphere() const
{
    Vector3 center = m_position;
    float radius = 3.f;
    return BoundingSphere(center, radius);
}
// �������Ă��邩���肷��
void RockBoss::CheckAlive()
{
    if (m_hp <= 0)
    {
        m_isAlive = false;
        m_hp = 0.0f;
    }
}
