/*
	�t�@�C��: PlayerDash.h
	�N���X  : �v���C���[�_�b�V���N���X
*/
#pragma once
#include "IState.h"

// �O���錾
class Player;
namespace NRLib
{
	class TPS_Camera;
};

class PlayerDash : public IState
{
public:
	// �R���X�g���N�^
	PlayerDash(Player* player);
	// �f�X�g���N�^
	~PlayerDash();
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
	
	// �_�b�V�����s������
	const float DASHTIME = 15;
	// �_�b�V������
	float m_dashTime;
};
