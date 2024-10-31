/*
	@file	MapSelectScene.cpp
	@brief	�}�b�v�Z���N�g�V�[���N���X
*/
#include "pch.h"
#include "MapSelectScene.h"
#include "Game/UI/MapSelectUI.h"
#include "WorkTool/DeviceResources.h"

#include <cassert>
#include "WorkTool/Graphics.h"
#include "WorkTool/InputDevice.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
MapSelectScene::MapSelectScene()
	:
	m_isChangeScene{},
	m_mapSelectUI{}
{
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
MapSelectScene::~MapSelectScene()
{
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void MapSelectScene::Initialize()
{
	// �V�[���ύX�t���O������������
	m_isChangeScene = false;

	// �^�C�g��UI�Ǘ��N���X���쐬����
	m_mapSelectUI = std::make_unique<MapSelectUI>(this);
	// ����������
	m_mapSelectUI->Initialize();
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void MapSelectScene::Update(float elapsedTime)
{
	UNREFERENCED_PARAMETER(elapsedTime);

	// �^�C�g��UI�Ǘ��N���X���X�V����
	m_mapSelectUI->Update();
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void MapSelectScene::Render()
{
	m_mapSelectUI->Render();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void MapSelectScene::Finalize()
{
	m_mapSelectUI->Finalize();
}

//---------------------------------------------------------
// ���̃V�[��ID���擾����
//---------------------------------------------------------
IScene::SceneID MapSelectScene::GetNextSceneID() const
{
	// �V�[���ύX������ꍇ
	if (m_isChangeScene)
	{
		return IScene::SceneID::PLAY;
	}

	// �V�[���ύX���Ȃ��ꍇ
	return IScene::SceneID::NONE;
}

void MapSelectScene::ChangeScene()
{
	m_isChangeScene = true;
}
