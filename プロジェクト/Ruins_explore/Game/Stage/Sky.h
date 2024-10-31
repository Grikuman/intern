/*
	@file	Sky.h
	@brief	��ʓI�ȃV�[���N���X
*/
#pragma once

// ��ʓI�ȃV�[���N���X
class Sky
{
private:
	// �ˉe�s��
	DirectX::SimpleMath::Matrix m_projection;

	// ���ȉ��A�ǋL����ϐ��Ȃǁ�

	// ���f���̕`��Ŏg�p����
	std::unique_ptr<DirectX::Model> m_model;	// ���f��


public:
	Sky();
	~Sky();

	void Initialize();
	void Update();
	void Render();
	void Finalize();
};
