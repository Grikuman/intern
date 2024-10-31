/*
	@file	EnemyUIManager.h
	@brief	�v���C���[��UI���Ǘ�����N���X
*/
#pragma once
#include "EnemyUIManager.h"
#include "Gauge.h"

class EnemyUIManager
{
public:
	// �R���X�g���N�^
	EnemyUIManager();
	// �f�X�g���N�^
	~EnemyUIManager();
	// ����������
	void Initialize();
	// �X�V����
	void Update(float bossHP,float MAX_BossHP);
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();

private:
	// �{�X�̗̑̓Q�[�W
	std::unique_ptr<Gauge> m_gauge;
};
