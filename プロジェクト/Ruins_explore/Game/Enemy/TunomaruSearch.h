/*
	�t�@�C��: TunomaruSearch.h
	�N���X  : �̂܂�T�[�`�N���X
*/
#pragma once
#include "IEnemyState.h"

// �O���錾
class Tunomaru;

class TunomaruSearch : public IEnemyState
{
public:
	// �R���X�g���N�^
	TunomaruSearch(Tunomaru* tunomaru);
	// �f�X�g���N�^
	~TunomaruSearch();
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
};
