/*
	@file	FixedCamera.cpp
	@brief	�Œ�J�����N���X
*/
#include "pch.h"
#include "FixedCamera.h"
#include "Game/Screen.h"

//-------------------------------------------------------------------
// �R���X�g���N�^
//-------------------------------------------------------------------
NRLib::FixedCamera::FixedCamera(
	DirectX::SimpleMath::Vector3& eye,
	DirectX::SimpleMath::Vector3& target,
	const DirectX::SimpleMath::Vector3& up
)
	:
	m_view{},
	m_projection{},
	m_eye{ eye },
	m_target{ target },
	m_up{ up }
{
	CalculateViewMatrix();
	CalculateProjectionMatrix();
}

//-------------------------------------------------------------------
// �r���[�s����v�Z����
//-------------------------------------------------------------------
void NRLib::FixedCamera::CalculateViewMatrix()
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye, m_target, m_up);
}

//-------------------------------------------------------------------
// �v���W�F�N�V�����s����v�Z����
//-------------------------------------------------------------------
void NRLib::FixedCamera::CalculateProjectionMatrix()
{
	// �E�B���h�E�T�C�Y
	const float width = static_cast<float>(Screen::WIDTH);
	const float height = static_cast<float>(Screen::HEIGHT);
	
	// ��ʏc����
	const float aspectRatio = width / height;

	m_projection = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
}
