/*
	�t�@�C��: RockBossDown.cpp
	�N���X  : ��{�X�_�E���N���X
*/
#include "pch.h"
#include "Game/Enemy/Boss/RockBoss.h"
#include "RockBossDown.h"
#include "Game/Player/Player.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/NRLib/TPS_Camera.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
RockBossDown::RockBossDown(RockBoss* RockBoss)
	:
    m_rockBoss(RockBoss),
	m_model{}
{
	// �_�E�����Ԃ�ݒ肷��
	m_downTime = MAX_DOWNTIME;
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
RockBossDown::~RockBossDown()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void RockBossDown::Initialize()
{
	m_model = Resources::GetInstance()->GetModel(L"RockBoss");
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void RockBossDown::Update()
{
	// �_�E�����Ԃ�����������
	m_downTime--;
	// �_�E�����Ԃ��I�������ꍇ
	if (m_downTime <= 0.f)
	{
		// �_�E�����Ԃ����Z�b�g����
		m_downTime = MAX_DOWNTIME;
		// �T�[�`��Ԃֈڍs����
		m_rockBoss->ChangeState(m_rockBoss->GetRockBossSearch());
	}
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void RockBossDown::Render()
{
	DirectX::SimpleMath::Matrix view, proj;
	// ���\�[�X���擾����
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	auto states = Graphics::GetInstance()->GetCommonStates();
	view = Graphics::GetInstance()->GetViewMatrix();
	proj = Graphics::GetInstance()->GetProjectionMatrix();

	// ���[���h�s��
	Matrix world = Matrix::CreateScale(0.8f);
	world *= Matrix::CreateRotationX(XMConvertToRadians(-30.f));
	world *= Matrix::CreateRotationY(XMConvertToRadians(m_rockBoss->GetAngle()));
	world *= Matrix::CreateTranslation(m_rockBoss->GetPosition());
	// �������Ă�����
	if (m_rockBoss->GetIsAlive() == true)
	{
		// ���f���\��
		m_model->Draw(context, *states, world, view, proj); // ���f����`�悷��
	}
}


//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void RockBossDown::Finalize()
{
    
}
