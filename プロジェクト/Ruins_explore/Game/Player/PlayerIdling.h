/*
	�t�@�C��: PlayerIdling.h
	�N���X  : �v���C���[�A�C�h�����O�N���X
*/
#pragma once
#include "IState.h"

// �O���錾
class Player;

class PlayerIdling : public IState
{
public:
	// �R���X�g���N�^
	PlayerIdling(Player* player);
	// �f�X�g���N�^
	~PlayerIdling();
	// ����������
	void Initialize();
	// �X�V����
	void Update(const float& elapsedTime);
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();

private:
	//�v���C���[
	Player* m_player;
	// ���f��
	DirectX::Model* m_model;
};
