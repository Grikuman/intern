/*
    �t�@�C��: PlayerAttack.cpp
    �N���X  : �v���C���[�A�^�b�N�N���X
*/
#include "pch.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "WorkTool/DeviceResources.h"
#include "Game/Effect/SwordEffect.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
PlayerAttack::PlayerAttack(Player* player)
	:
    m_player(player),
	m_model{},
    m_swordEffect{},
    m_cnt{}
{

}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
PlayerAttack::~PlayerAttack()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void PlayerAttack::Initialize()
{
    // �f�o�C�X���擾����
    auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();

    // ���f�����擾����
    m_model = Resources::GetInstance()->GetModel(L"Player");

    // �a���G�t�F�N�g���쐬
    m_swordEffect = std::make_unique<SwordEffect>(device);
    // �ʒu��ݒ肷��
    m_swordEffect->SetPosition(m_player->GetPosition());
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void PlayerAttack::Update(const float& elapsedTime)
{
    UNREFERENCED_PARAMETER(elapsedTime);

    // �G�t�F�N�g���X�V����
    m_swordEffect->SetPosition(m_player->GetPosition());
    m_swordEffect->Update();

    // �J�E���g
    m_cnt++;
    if (m_cnt >= 30)
    {
        m_cnt = 0;
        m_player->ChangeState(m_player->GetPlayerIdling());
    }
}



//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void PlayerAttack::Render()
{
    // �R���e�L�X�g�E�X�e�[�g���擾����
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    auto states = Graphics::GetInstance()->GetCommonStates();
    // �r���[�E�v���W�F�N�V�������擾����
    DirectX::SimpleMath::Matrix view, proj;
    view = Graphics::GetInstance()->GetViewMatrix();
    proj = Graphics::GetInstance()->GetProjectionMatrix();

    // �v���C���[�̕`��
    Matrix world = Matrix::CreateScale(1.f);
    world *= Matrix::CreateRotationY(XMConvertToRadians(m_player->GetAngle()));
    world *= Matrix::CreateTranslation(m_player->GetPosition());
    m_model->Draw(context, *states, world, view, proj); // ���f����`�悷��

    world = Matrix::Identity;
    // �G�t�F�N�g��`�悷��
    m_swordEffect->Render(context,view,proj);
}


//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void PlayerAttack::Finalize()
{
    
}

DirectX::BoundingSphere PlayerAttack::GetAttackRange()
{
    Vector3 center = m_player->GetPosition(); // �����蔻�苅�̒��S
    float radius = 2.f;                       // �͈͂ɉ����Ē���
    return DirectX::BoundingSphere(center, radius);
}
