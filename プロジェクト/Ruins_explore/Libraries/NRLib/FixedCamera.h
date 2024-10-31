/*
	@file	FixedCamera.h
	@brief	�Œ�J�����N���X
*/
#pragma once

namespace NRLib
{
	class FixedCamera
	{
	private:
		// ��p
		const float FOV = DirectX::XMConvertToRadians(45.0f);
		
		// �߂����e��
		const float NEAR_PLANE = 1.0f;
		
		// �������e��
		const float FAR_PLANE  = 100.0f;

		// �r���[�s��
		DirectX::SimpleMath::Matrix m_view;

		// �v���W�F�N�V�����s��
		DirectX::SimpleMath::Matrix m_projection;

		// �J�������W
		DirectX::SimpleMath::Vector3 m_eye;

		// �����_
		DirectX::SimpleMath::Vector3 m_target;

		// �J�����̓��̕���
		DirectX::SimpleMath::Vector3 m_up;


	public:
		// �R���X�g���N�^
		FixedCamera(
			DirectX::SimpleMath::Vector3& eye, 
			DirectX::SimpleMath::Vector3& target, 
			const DirectX::SimpleMath::Vector3& up = DirectX::SimpleMath::Vector3::UnitY);

		// �f�X�g���N�^
		~FixedCamera() = default;

		// getter
		const DirectX::SimpleMath::Matrix& GetViewMatrix() const { return m_view; }

		const DirectX::SimpleMath::Matrix& GetProjectionMatrix() const { return m_projection; }

		DirectX::SimpleMath::Vector3& GetEyePosition() { return m_eye; }

		DirectX::SimpleMath::Vector3& GetTargetPosition() { return m_target; }

		const DirectX::SimpleMath::Vector3& GetUpVector() const { return m_up; }

		// setter
		void SetEyePosition(DirectX::SimpleMath::Vector3 eye) { m_eye = eye; }

		void SetTargetPosition(DirectX::SimpleMath::Vector3 target) { m_target = target; }

	private:
		// �r���[�s����v�Z����
		void CalculateViewMatrix();

		// �v���W�F�N�V�����s����v�Z����
		void CalculateProjectionMatrix();
	};
}
