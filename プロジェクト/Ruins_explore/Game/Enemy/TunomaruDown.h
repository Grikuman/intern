/*
	�t�@�C��: TunomaruDown.h
	�N���X  : �̂܂�_�E���N���X
*/
#pragma once
#include "IEnemyState.h"

// �O���錾
class Tunomaru;

namespace NRLib
{
	class TPS_Camera;
};

class TunomaruDown : public IEnemyState
{
public:
	// �R���X�g���N�^
	TunomaruDown(Tunomaru* tunomaru);
	// �f�X�g���N�^
	~TunomaruDown();
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �`�悷��
	void Render();
	// �㏈������
	void Finalize();

private:
	// �̂܂�
	Tunomaru* m_tunomaru;
	// ���f��
	DirectX::Model* m_model;

	// �_�E�����Ă��鎞��
	float m_downTime;
	// ����
	const float MAX_DOWNTIME = 90.f;
};
