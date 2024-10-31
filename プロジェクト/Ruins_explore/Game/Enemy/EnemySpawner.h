/*
	�t�@�C��: EnemySpawner.h
	�N���X  : �G�����N���X
*/
#pragma once
#include "Game/Enemy/Tunomaru.h"
#include "Game/Enemy/Boss/RockBoss.h"

// �O���錾
class Player;
class EnemyUIManager;

namespace NRLib
{
	class TPS_Camera;
}

// ��ʓI�ȃV�[���N���X
class EnemySpawner
{
public:
	EnemySpawner(Player* player);
	~EnemySpawner();
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �`�悷��
	void Render();
	// �I������
	void Finalize();
	// �V�[���ύX����
	bool IsChangeScene();
private:
	// �v���C���[
	Player* m_player;
	// �G�̍ő吔
	const int MAX_ENEMY = 2;
	// ���ꂼ��̓G�̐�
	static const int MAX_TUNOMARU = 2;
	// �̂܂�
	std::unique_ptr<Tunomaru> m_tunomaru[MAX_TUNOMARU];
	// ��{�X
	std::unique_ptr<RockBoss> m_rockBoss;
	// �G��UI�Ǘ��N���X
	std::unique_ptr<EnemyUIManager> m_enemyUIManager;

	// �������Ă���G�̐�
	int m_aliveEnemy;
	// �V�[���J�ڃt���O
	bool m_isChangeScene;
};
