/*
	@file	TPS_Camera.cpp
	@brief	TPS�J�����N���X�A�΂˕t��
*/
#include "pch.h"
#include "TPS_Camera.h"
#include "Game/Screen.h"

//-------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------
NRLib::TPS_Camera::TPS_Camera(const DirectX::SimpleMath::Vector3& target)
	:
	m_view{},
	m_projection{},
	m_eye{},
	m_target{ target },
	m_up{ DirectX::SimpleMath::Vector3::UnitY }
{
	CalculateEyePosition(DirectX::SimpleMath::Matrix::Identity);
	CalculateViewMatrix();
	CalculateProjectionMatrix();
}

//-------------------------------------------------------------------
// �X�V����
//-------------------------------------------------------------------
void NRLib::TPS_Camera::Update(
	const DirectX::SimpleMath::Vector3& newTarget,
	const DirectX::SimpleMath::Matrix& rotate
)
{
	/*
		ToDo::�Ǐ]�J�����Ȃ̂ŁA������elapsedTime�����ɂ�����
		��newTarget,rotate�̓J�����̓����I�Ɍv�Z������
	*/

	// target�̈ʒu���X�V����
	//m_target = newTarget;	// �o�l�Ȃ�
	m_target += (newTarget - m_target) * 0.05f;	// �o�l�t��

	// �J�������W���v�Z����
	CalculateEyePosition(rotate);

	// �r���[�s����X�V����
	CalculateViewMatrix();
}

//-------------------------------------------------------------------
// �r���[�s����v�Z����
//-------------------------------------------------------------------
void NRLib::TPS_Camera::CalculateViewMatrix()
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);
}

//-------------------------------------------------------------------
// �v���W�F�N�V�����s����v�Z����
//-------------------------------------------------------------------
void NRLib::TPS_Camera::CalculateProjectionMatrix()
{
	// �E�B���h�E�T�C�Y
	const float width = static_cast<float>(Screen::WIDTH);
	const float height = static_cast<float>(Screen::HEIGHT);
	
	// ��ʏc����
	const float aspectRatio = width / height;

	m_projection = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
}

//-------------------------------------------------------------------
// �J�������W���v�Z����
//-------------------------------------------------------------------
void NRLib::TPS_Camera::CalculateEyePosition(const DirectX::SimpleMath::Matrix& rotate)
{
	// �J�����̃f�t�H���g�̍��W�x�N�g��
	DirectX::SimpleMath::Vector3 eye{ 0.0f,CAMERA_HIGHT,CAMERA_DISTANCE };

	// �^�[�Q�b�g�̌����Ă�������ɒǏ]����
	eye = DirectX::SimpleMath::Vector3::Transform(eye, rotate);

	// �J�������W���v�Z����
	//m_eye = m_target + eye;	// �o�l�Ȃ�
	m_eye += (m_target + eye - m_eye) * 0.05f;	// �o�l�t��
}
