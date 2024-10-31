/*
    �t�@�C��: Tunomaru.cpp
    �N���X  : �̂܂�N���X
*/
#pragma once
#include "pch.h"
#include "Tunomaru.h"
#include "Game/Player/Player.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/MyLib/InputManager.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Collision.h"
#include "WorkTool/Resources.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Tunomaru::Tunomaru(Player* player)
    : 
    m_player{player},
    m_model{},
    m_ball{},
    m_tunomaruSearch{},
    m_tunomaruAttack{},
    m_position{},
    m_velocity{},
    m_angle{},
    m_isHit(false),
    m_isAlive(true)
{
    m_hp = MAXHP;
}

Tunomaru::~Tunomaru() {}

void Tunomaru::Initialize(Vector3 position)
{
    // �R���e�L�X�g���擾����
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    // D3D�f�o�C�X���擾����
    auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();
    // �{�[����ǂݍ���
    m_ball = DirectX::GeometricPrimitive::CreateSphere(context, 2.f);
    // �ʒu��ݒ肷��
    m_position = position;

    m_model = Resources::GetInstance()->GetModel(L"Tunomaru");

    //HPUI���쐬����
    m_hpUI = std::make_unique<HPUI>(Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice());
    m_hpUI->SetScale(1.f);
    m_hpUI->SetPosition(m_position);

    //* �X�e�[�g���쐬���� *
    // �T�[�`���
    m_tunomaruSearch = std::make_unique<TunomaruSearch>(this);
    m_tunomaruSearch->Initialize();
    // �A�^�b�N���
    m_tunomaruAttack = std::make_unique<TunomaruAttack>(this);
    m_tunomaruAttack->Initialize();
    // �_�E�����
    m_tunomaruDown = std::make_unique<TunomaruDown>(this);
    m_tunomaruDown->Initialize();

    // �X�e�[�g��ݒ肷��
    m_currentState = m_tunomaruSearch.get();
}

void Tunomaru::Update()
{
    m_isHit = false; 

    //�������Ă��邩�m�F����
    CheckAlive(); 

    //���݂̃X�e�[�g���X�V����
    m_currentState->Update();

    // HPUI�𓮂���
    m_hpUI->SetPosition(DirectX::SimpleMath::Vector3(m_position.x, m_position.y + 1.6f, m_position.z));
    // HPUI��HP�����X�V
    m_hpUI->SetHP(m_hp, MAXHP);

    // �v���C���[�Ƃ̓����蔻��
    Collision::GetInstance()->CheckHitTunomaru(this);
}

void Tunomaru::Render()
{
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    auto view = Graphics::GetInstance()->GetViewMatrix();
    auto proj = Graphics::GetInstance()->GetProjectionMatrix();
    // ���݂̃X�e�[�g��`�悷��
    m_currentState->Render();
    // �������Ă�����
    if (m_isAlive == true)
    {
        // HPUI��`�悷��
        m_hpUI->Render(context, view, proj);
    }
}

void Tunomaru::Finalize()
{
    
}

// �o�E���f�B���O�X�t�B�A���擾����
BoundingSphere Tunomaru::GetBoundingSphere() const
{
    Vector3 center = m_position;
    float radius = 1.f;
    return BoundingSphere(center, radius);
}
// �������Ă��邩���肷��
void Tunomaru::CheckAlive()
{
    if (m_hp <= 0)
    {
        m_isAlive = false;
        m_hp = 0.0f;
    }
}

void Tunomaru::ChangeState(IEnemyState* newState)
{
    m_currentState = newState;
}
