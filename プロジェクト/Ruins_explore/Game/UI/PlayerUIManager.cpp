/*
	@file	PlayerUIManagerUIManager.cpp
	@brief	�v���C���[��UI���Ǘ�����N���X
*/
#include "pch.h"
#include "Game/UI/PlayerUIManager.h"

#include "Libraries/MyLib/DebugString.h"
#include "Libraries/MyLib/InputManager.h"
#include "Game/Player/Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
PlayerUIManager::PlayerUIManager(Player* player)
	:
	m_player{player},
	m_playerStatusUI{}
{

}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
PlayerUIManager::~PlayerUIManager()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void PlayerUIManager::Initialize()
{
	// �v���C���[��HPUI���쐬����
	m_playerStatusUI = std::make_unique<PlayerStatusUI>(m_player);
	m_playerStatusUI->Initialize();
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void PlayerUIManager::Update()
{
	// �v���C���[��HPUI���X�V����
	m_playerStatusUI->Update();
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void PlayerUIManager::Render()
{
	// �v���C���[��HPUI��`�悷��
	m_playerStatusUI->Render();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void PlayerUIManager::Finalize()
{
	m_playerStatusUI->Finalize();
}