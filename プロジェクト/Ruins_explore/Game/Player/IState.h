/*
	@file	IState.h
	@brief	�X�e�[�g�̃C���^�[�t�F�[�X
*/
#pragma once

class IState
{
public:
	virtual ~IState() = default;
	// ����������
	virtual void Initialize() = 0;
	// �X�V����
	virtual void Update(const float& elapsedTime) = 0;
	// �`�悷��
	virtual void Render() = 0;
	// �㏈�����s��
	virtual void Finalize() = 0;
};
