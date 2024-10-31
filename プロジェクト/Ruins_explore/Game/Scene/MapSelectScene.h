/*
	@file	MapSelectScene.h
	@brief	�}�b�v�Z���N�g�V�[���N���X
*/
#pragma once
#include "IScene.h"

class MapSelectUI;

class MapSelectScene final : public IScene
{
public:
	MapSelectScene();
	~MapSelectScene() override;

	// ����������
	void Initialize() override;
	// �X�V����
	void Update(float elapsedTime)override;
	// �`�悷��
	void Render() override;
	// �I������
	void Finalize() override;

public:
	// ���̃V�[��ID���擾����
	SceneID GetNextSceneID() const;
	// �V�[���J�ڂ���
	void ChangeScene();

private:
	// �V�[���`�F���W�t���O
	bool m_isChangeScene;

	// �}�b�v�Z���N�gUI
	std::unique_ptr<MapSelectUI> m_mapSelectUI;
};
