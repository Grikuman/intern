/*
	@file	Field.h
	@brief	��ʓI�ȃV�[���N���X
*/
#pragma once

// �O���錾
class GeometricPrimitive;

// ��ʓI�ȃV�[���N���X
class Field
{
private:
	// �X�e�[�W�̃��f��
	std::unique_ptr<DirectX::GeometricPrimitive> m_box;
	// �X�e�[�W�̍��W
	DirectX::SimpleMath::Vector3 m_boxPos;

public:
	Field();
	~Field();

	void Initialize();
	void Update();
	void Render();
	void Finalize();

private:
	std::unique_ptr<DirectX::Model> m_pyramid;

};
