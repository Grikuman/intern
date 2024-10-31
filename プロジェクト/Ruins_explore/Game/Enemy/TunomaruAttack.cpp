/*
	�t�@�C��: TunomaruAttack.cpp
	�N���X  : �̂܂�A�^�b�N�N���X
*/
#include "pch.h"
#include "Tunomaru.h"
#include "Game/Player/Player.h"
#include "TunomaruAttack.h"

#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
TunomaruAttack::TunomaruAttack(Tunomaru* tunomaru)
	:
    m_tunomaru(tunomaru),
	m_model{}
{
	// �ːi���Ԃ�ݒ肷��
	m_rushTime = MAX_RUSHTIME;
}


//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
TunomaruAttack::~TunomaruAttack()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void TunomaruAttack::Initialize()
{
	// ���f�����擾����
	m_model = Resources::GetInstance()->GetModel(L"Tunomaru");
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void TunomaruAttack::Update()
{
	// �ːi����
	m_tunomaru->SetVelocity(Vector3::Forward * 2.f);
	// �ːi���Ԃ����炷
	m_rushTime--;
	// �̂܂�ƃv���C���[���ڐG�����ꍇ
	if (m_tunomaru->GetBoundingSphere().Intersects(m_tunomaru->GetPlayer()->GetBoundingSphere()))
	{
		// �v���C���[�����G�łȂ����
		if (m_tunomaru->GetPlayer()->GetInvincible() == false)
		{
			// �v���C���[���U��
			m_tunomaru->GetPlayer()->SetHP(m_tunomaru->GetPlayer()->GetHP() - 1);
				m_tunomaru->GetPlayer()->SetInvincible(true);
		}
	}
	
	// �ːi���Ԃ��I�������ꍇ
	if (m_rushTime <= 0.f)
	{
		m_rushTime = MAX_RUSHTIME;
		m_tunomaru->ChangeState(m_tunomaru->GetTunomaruDown());
	}

	// ��]�s����쐬����
	Matrix matrix = Matrix::CreateRotationY(XMConvertToRadians(m_tunomaru->GetAngle()));

	// �ړ��ʂ�␳����
	m_tunomaru->SetVelocity(m_tunomaru->GetVelocity() * 0.05f);

	// ��]���������Ď��ۂɈړ�����
	m_tunomaru->SetPotision(m_tunomaru->GetPosition() + Vector3::Transform(m_tunomaru->GetVelocity(), matrix));
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void TunomaruAttack::Render()
{
	DirectX::SimpleMath::Matrix view, proj;
	// ���\�[�X���擾����
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	auto states = Graphics::GetInstance()->GetCommonStates();
	view = Graphics::GetInstance()->GetViewMatrix();
	proj = Graphics::GetInstance()->GetProjectionMatrix();

	// ���[���h�s��
	Matrix world = Matrix::CreateScale(1.f);
	world *= Matrix::CreateRotationY(XMConvertToRadians(m_tunomaru->GetAngle()));
	world *= Matrix::CreateTranslation(m_tunomaru->GetPosition());
	// �������Ă�����
	if (m_tunomaru->GetIsAlive() == true)
	{
		// ���f���\��
		m_model->Draw(context, *states, world, view, proj); // ���f����`�悷��
	}
}


//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void TunomaruAttack::Finalize()
{
    
}
