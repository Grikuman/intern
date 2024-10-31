/*
	@file	FollowCamera.h
	@brief	��ǂ��J�����N���X�A�΂˕t��
*/
#pragma once
namespace mylib
{
	class FollowCamera
	{
	private:
		// �o�l���[�g
		static constexpr float SPRING_RATE_EYE = 0.05f;
		static constexpr float SPRING_RATE_TARGET = 0.05f;
		// �����A����
		static constexpr float DISTANCE = 5.0f;
		static constexpr float HEIGHT = 3.0f;

		// �J�������W
		DirectX::SimpleMath::Vector3 m_eye;

		// �����_
		DirectX::SimpleMath::Vector3 m_target;

		// �ǐՑΏۂ̍��W�̃|�C���^�i�Q�Ɛ���X�V�s�Ƃ���j
		const DirectX::SimpleMath::Vector3* m_followUpTargetPosition;

		// �ǐՑΏۂ̃N�H�[�^�j�I���̃|�C���^�i�Q�Ɛ���X�V�s�Ƃ���j
		const DirectX::SimpleMath::Quaternion* m_followUpTargetQuaternion;


	public:
		FollowCamera();
		~FollowCamera() = default;

		void Initialize(
			const DirectX::SimpleMath::Vector3* followUpTargetPosition,
			const DirectX::SimpleMath::Quaternion* followUpTargetQuaternion
		);
		void Update(float elapsedTime);

		// getter
		const DirectX::SimpleMath::Vector3& GetEyePosition() const { return m_eye; }
		const DirectX::SimpleMath::Vector3& GetTargetPosition() const { return m_target; }
	};
}
