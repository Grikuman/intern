/*
	@file	PlayerUIManager.h
	@brief	�v���C���[��UI���Ǘ�����N���X
*/
#pragma once
#include "PlayerStatusUI.h"

// �O���錾
class Player;

class PlayerUIManager
{
public:
	// �R���X�g���N�^
	PlayerUIManager(Player* player);
	// �f�X�g���N�^
	~PlayerUIManager();
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();
private:
	// Player
	Player* m_player;
	// HPUI�N���X
	std::unique_ptr<PlayerStatusUI> m_playerStatusUI;
};
