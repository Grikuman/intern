/*
	@file	TitleScene.h
	@brief	�v���C�V�[���N���X
*/
#pragma once
#include "IScene.h"
#include <memory>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <wrl/client.h>
#include "Game/UI/TitleSceneUI.h"

namespace NRLib
{
	class FixedCamera;
};

class TitleScene final : public IScene
{
public:
	TitleScene();
	~TitleScene() override;

	void Initialize() override;
	void Update(float elapsedTime)override;
	void Render() override;
	void Finalize() override;

	SceneID GetNextSceneID() const;

	void ChangeScene();

private:
	// �V�[���`�F���W�t���O
	bool m_isChangeScene;

	// �^�C�g��UI�Ǘ��N���X
	std::unique_ptr<TitleSceneUI> m_titleSceneUI;
};
