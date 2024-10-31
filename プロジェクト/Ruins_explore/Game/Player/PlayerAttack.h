/*
	�t�@�C��: PlayerAttack.h
	�N���X  : �v���C���[�A�^�b�N�N���X
*/
#pragma once
#include "IState.h"

// �O���錾
class Player;
class SwordEffect;
namespace NRLib
{
	class TPS_Camera;
};

class PlayerAttack : public IState
{
public:
	// �R���X�g���N�^
	PlayerAttack(Player* player);
	// �f�X�g���N�^
	~PlayerAttack();
	// ����������
	void Initialize();
	// �X�V����
	void Update(const float& elapsedTime);
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();
public:
	// �U���͈͂��擾
	DirectX::BoundingSphere GetAttackRange();

private:
	//�v���C���[
	Player* m_player;
	// ���f��
	DirectX::Model* m_model;
	// �a���G�t�F�N�g
	std::unique_ptr<SwordEffect> m_swordEffect;
	
	// �J�E���g
	int m_cnt;
};
