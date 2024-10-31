/*
	�t�@�C��: RockBossSearch.h
	�N���X  : ��{�X�T�[�`�N���X
*/
#pragma once
#include "Game/Enemy/IEnemyState.h"

// �O���錾
class CommonResources;
class RockBoss;

namespace NRLib
{
	class TPS_Camera;
};

class RockBossSearch : public IEnemyState
{
public:
	// �R���X�g���N�^
	RockBossSearch(RockBoss* RockBoss);
	// �f�X�g���N�^
	~RockBossSearch();
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();

private:
	// ��{�X
	RockBoss* m_rockBoss;
	// ���f��
	DirectX::Model* m_model;
};
