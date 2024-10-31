/*
	�t�@�C��: RockBossAttck.h
	�N���X  : ��{�X�A�^�b�N�N���X
*/
#pragma once
#include "Game/Enemy/IEnemyState.h"

// �O���錾
class RockBoss;

namespace NRLib
{
	class TPS_Camera;
};

class RockBossAttack : public IEnemyState
{
public:
	// �R���X�g���N�^
	RockBossAttack(RockBoss* RockBoss);
	// �f�X�g���N�^
	~RockBossAttack();
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();

public:
	// �U���̃o�E���f�B���O�X�t�B�A���擾����
	DirectX::BoundingSphere GetAttackBoundingSphere() const;
	// �U�����󂯂Ȃ��o�E���f�B���O�X�t�B�A���擾����
	DirectX::BoundingSphere GetNoDamageBoundingSphere() const;
private:
	// ��{�X
	RockBoss* m_rockBoss;
	// ���f��
	DirectX::Model* m_model;

	// �U���܂ł̗P�\����
	float m_atackStartTime;
	const float ATACKSTART_TIME = 60.f;
	// ��]�J�E���g
	float m_rotateCnt;
};
