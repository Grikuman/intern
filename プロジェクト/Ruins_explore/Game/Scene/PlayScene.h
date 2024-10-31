/*
	@file	PlayScene.h
	@brief	�v���C�V�[���N���X
*/
#pragma once
#include "IScene.h"
#include "Game/Player/Player.h"

#include "Game/Stage/Sky.h"
#include "Game/Stage/Field.h"
#include "Game/Enemy/EnemySpawner.h"
#include "Game/UI/TimeUI.h"


namespace NRLib
{
	class FixedCamera;
};

class PlayScene final : public IScene
{
private:
	// �v���C���[
	std::unique_ptr<Player> m_player;
	// �V��
	std::unique_ptr<Sky> m_sky;
	// �t�B�[���h
	std::unique_ptr<Field> m_field;
	// �G�l�~�[�X�|�i�[
	std::unique_ptr<EnemySpawner> m_enemySpawner;
	//TextUI
	std::unique_ptr<TimeUI> m_timeUI;
	// �v���C�V�[��UI

	// �V�[���`�F���W�t���O
	bool m_isChangeScene;

	// �Q�[������
	float m_gameTime;
	// �Q�[���̐�������
	static const int MAX_GAMETIME = 60;

public:
	PlayScene();
	~PlayScene() override;

	void Initialize() override;
	void Update(float elapsedTime)override;
	void Render() override;
	void Finalize() override;

	SceneID GetNextSceneID() const;
	// �v���C��ʂ̃X�N���[�����B��
	void SaveScreenshotOnExit(IDXGISwapChain* swapChain, ID3D11DeviceContext* deviceContext);
};
