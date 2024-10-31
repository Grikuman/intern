/*
	�t�@�C��: Player.h
	�N���X  : �v���C���[�N���X
*/
#pragma once
#include "IState.h"
#include "PlayerIdling.h"
#include "PlayerAttack.h"
#include "PlayerDash.h"

#include "Game/UI/PlayerUIManager.h"
#include "Game/Effect/PlayerEffectManager.h"

// �O���錾

namespace NRLib
{
	class TPS_Camera;
};

class Player
{
public:
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();
	// ����������
	void Initialize();
	// �X�V����
	void Update(float elapsedTime);
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();
public:
	// �v���C���[�A�C�h�����O���擾����
	PlayerIdling* GetPlayerIdling() { return m_playerIdling.get(); }
	// �v���C���[�A�^�b�N���擾����
	PlayerAttack* GetPlayerAttack() { return m_playerAttack.get(); }
	// �v���C���[�_�b�V�����擾����
	PlayerDash* GetPlayerDash() { return m_playerDash.get(); }

public:
	// �ʒu���擾����
	DirectX::SimpleMath::Vector3 GetPosition() const { return m_position; }
	// ���x���擾����
	DirectX::SimpleMath::Vector3 GetVelocity() const { return m_velocity; }
	// �p�x���擾����
	float GetAngle() const { return m_playerAngle; }
	// �̗͂��擾����
	int GetHP() const { return m_hp; }
	// �ő�̗͂��擾����
	int GetMAXHP() const { return MAX_HP; }
	// �X�^�~�i���擾����
	int GetStamina() const { return m_stamina; }
	// �ő�X�^�~�i���擾����
	int GetMAXSTAMINA() const { return MAX_STAMINA; }
	// ���G���擾
	bool GetInvincible() const { return m_invincible; }

	// �U�����Ă��邩�擾����
	bool GetIsAttack();
	// �o�E���f�B���O�X�t�B�A���擾����
	DirectX::BoundingSphere GetBoundingSphere();

	// �J�������擾����
	NRLib::TPS_Camera* GetCamera();

public:
	// �ʒu��ݒ肷��
	void SetPosition(const DirectX::SimpleMath::Vector3& position) { m_position = position; }
	// ���x��ݒ肷��
	void SetVelocity(const DirectX::SimpleMath::Vector3& velocity) { m_velocity = velocity; }
	// �p�x��ݒ肷��
	void SetAngle(const float angle) { m_playerAngle = angle; }
	// �̗͂�ݒ肷��
	void SetHP(const int hp) { m_hp = hp; }
	// �X�^�~�i��ݒ肷��
	void SetStamina(const int stamina) { m_stamina = stamina; }
	//���G��ݒ肷��
	void SetInvincible(const bool invincible) { m_invincible = invincible; }

	// �X�e�[�g��ύX����
	void ChangeState(IState* newState);
private:
	// UI�Ǘ��N���X
	std::unique_ptr<PlayerUIManager> m_playerUIManager;
	// �G�t�F�N�g�Ǘ��N���X
	std::unique_ptr<PlayerEffectManager> m_playerEffectManager;
	// ���݂̃X�e�[�g
	IState* m_currentState;
	// �J����
	std::unique_ptr<NRLib::TPS_Camera> m_camera;
	// ���f��
	DirectX::Model* m_model;

	// �A�C�h�����O���
	std::unique_ptr<PlayerIdling> m_playerIdling;
	// �A�^�b�N���
	std::unique_ptr<PlayerAttack> m_playerAttack;
	// �_�b�V�����
	std::unique_ptr<PlayerDash> m_playerDash;

	// �ʒu
	DirectX::SimpleMath::Vector3 m_position;
	// ���x
	DirectX::SimpleMath::Vector3 m_velocity;
	// �p�x
	float m_playerAngle;
	// �̗�
	int m_hp;
	// �ő�̗�
	const int MAX_HP = 6;
	// �X�^�~�i
	int m_stamina;
	// �ő�X�^�~�i
	const int MAX_STAMINA = 6;
	// �X�^�~�i�̉񕜃J�E���g
	float m_chargeCnt;
	// ���G
	bool m_invincible;
	// ���G����
	float m_invincibleTime;
};
