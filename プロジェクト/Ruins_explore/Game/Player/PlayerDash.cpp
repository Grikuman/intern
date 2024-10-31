/*
    �t�@�C��: PlayerDash.cpp
    �N���X  : �v���C���[�_�b�V���N���X
*/
#include "pch.h"
#include "Player.h"
#include "PlayerDash.h"
#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"
#include "WorkTool/InputDevice.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
PlayerDash::PlayerDash(Player* player)
	:
    m_player(player),
	m_model{},
    m_dashTime{}
{
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
PlayerDash::~PlayerDash()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void PlayerDash::Initialize()
{
    // ���f�����擾����
    m_model = Resources::GetInstance()->GetModel(L"Player");
    // �_�b�V�����Ԃ�ݒ�
    m_dashTime = DASHTIME;
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void PlayerDash::Update(const float& elapsedTime)
{
    UNREFERENCED_PARAMETER(elapsedTime);

    auto kb = InputDevice::GetInstance()->GetKeyboardState();

    // �^�������i��
    m_player->SetVelocity(Vector3::Forward * 4.f);
    // �_�b�V�����Ԃ�����������
    m_dashTime--;
    // �_�b�V�����Ԃ��I�������ꍇ
    if (m_dashTime <= 0.f)
    {
        // �_�b�V�����Ԃ����Z�b�g����
        m_dashTime = DASHTIME;
        // �A�C�h�����O��Ԃֈڍs����
        m_player->ChangeState(m_player->GetPlayerIdling());
    }
    if (kb->A)
    {
        m_player->SetAngle(m_player->GetAngle() + 3.0f); // ��]
    }
    if (kb->D)
    {
        m_player->SetAngle(m_player->GetAngle() - 3.0f); // ��]
    }
}



//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void PlayerDash::Render()
{
    DirectX::SimpleMath::Matrix view, proj;
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
    auto states = Graphics::GetInstance()->GetCommonStates();
    view = Graphics::GetInstance()->GetViewMatrix();
    proj = Graphics::GetInstance()->GetProjectionMatrix();

    // �v���C���[�̕`��
    Matrix world = Matrix::CreateScale(1.f);
    world *= Matrix::CreateRotationY(XMConvertToRadians(m_player->GetAngle()));
    world *= Matrix::CreateTranslation(m_player->GetPosition());
    m_model->Draw(context, *states, world, view, proj); // ���f����`�悷��
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void PlayerDash::Finalize()
{
    
}
