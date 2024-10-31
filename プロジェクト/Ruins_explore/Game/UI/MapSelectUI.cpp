/*
    @file    MapSelectUI.cpp
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#include "pch.h"
#include "MapSelectUI.h"
#include "Game/Scene/MapSelectScene.h"
#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"
#include "WorkTool/InputDevice.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
MapSelectUI::MapSelectUI(MapSelectScene* mapSelectScene)
{
    
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
MapSelectUI::~MapSelectUI()
{
    
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void MapSelectUI::Initialize()
{
    // �X�v���C�g�o�b�`��ݒ肷��
    m_spriteBatch = Graphics::GetInstance()->GetSpriteBatch();
    // �摜�ǂݍ���
    //m_   = Resources::GetInstance()->GetTexture(L"Ruins_Explorer");
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void MapSelectUI::Update()
{

}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void MapSelectUI::Render()
{
    // �ʏ�̃X�v���C�g�o�b�`���J�n
    m_spriteBatch->Begin();

    

    // �ʏ�̃X�v���C�g�o�b�`���I��
    m_spriteBatch->End();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void MapSelectUI::Finalize()
{
   
}