/*
    @file    TitleSceneUI.cpp
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#include "pch.h"
#include "TitleSceneUI.h"
#include "Game/Player/Player.h"
#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"
#include "WorkTool/InputDevice.h"
#include "Game/Scene/TitleScene.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
TitleSceneUI::TitleSceneUI(TitleScene* titlescene)
    :
    m_ruinsExplorer{},
    m_titleSelect{},
    m_selectIcon{},
    m_i_Rotate{},
    m_o_Rotate{},
    m_titleBackGround{},
    m_black{},
    m_selectPos{},
    m_selectFlag{true},
    m_titleScene{titlescene},
    m_rotate{},
    m_alpha{},
    m_fadeFlag{false},
    m_scale{1.f}
{
    
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
TitleSceneUI::~TitleSceneUI()
{
    
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void TitleSceneUI::Initialize()
{
    // �X�v���C�g�o�b�`��ݒ肷��
    m_spriteBatch = Graphics::GetInstance()->GetSpriteBatch();
    // �摜�ǂݍ���
    m_ruinsExplorer   = Resources::GetInstance()->GetTexture(L"Ruins_Explorer");
    m_titleSelect     = Resources::GetInstance()->GetTexture(L"TitleSelect");
    m_selectIcon      = Resources::GetInstance()->GetTexture(L"SelectIcon");
    m_i_Rotate        = Resources::GetInstance()->GetTexture(L"i_Rotate");
    m_o_Rotate        = Resources::GetInstance()->GetTexture(L"o_Rotate");
    m_titleBackGround = Resources::GetInstance()->GetTexture(L"TitleBackGround");
    m_black           = Resources::GetInstance()->GetTexture(L"Black");
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void TitleSceneUI::Update()
{
    // �L�[�{�[�h���擾����
    auto kb = InputDevice::GetInstance()->GetKeyboardStateTracker();

    // ��]
    m_rotate += 1.f;

    //�t�F�[�h�Ɉڍs���Ă��Ȃ����
    if (!m_fadeFlag)
    {
        // ��L�[����������
        if (kb->IsKeyPressed(DirectX::Keyboard::Up))
        {
            m_selectFlag = true;
        }
        // ���L�[����������
        if (kb->IsKeyPressed(DirectX::Keyboard::Down))
        {
            m_selectFlag = false;
        }
    }
    
    // �t���O���ƂɃZ���N�g�A�C�R���̈ʒu���ړ�
    if (m_selectFlag)
    {
        m_selectPos = Vector2(500, 390);
    }
    else
    {
        m_selectPos = Vector2(500, 510);
    }

    // �V�[���J��
    if (kb->IsKeyPressed(DirectX::Keyboard::Space) && m_selectFlag)
    {
        // �t�F�[�h�t���O��true
        m_fadeFlag = true;
    }
    // �t�F�[�h����
    if (m_fadeFlag)
    {
        m_alpha += 0.008f;
        m_scale += 0.001f;
        if (m_alpha >= 1.f)
        {
            // �A���t�@�l�ƃX�P�[���l�����Z�b�g���Ă���
            m_alpha = 0.f;
            m_scale = 1.f;
            // �V�[���J��
            m_titleScene->ChangeScene();
        }
    }
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void TitleSceneUI::Render()
{
    //Matrix matrix = Matrix::CreateTranslation(Vector3(640, 360, 0));
    Matrix matrix = Matrix::CreateScale(m_scale);
    matrix *= Matrix::CreateTranslation(Vector3(0, 0, 0));
    m_spriteBatch->Begin(DirectX::DX11::SpriteSortMode_Deferred,nullptr,nullptr,nullptr,nullptr,nullptr,matrix);
    // �w�i
    m_spriteBatch->Draw(m_titleBackGround.Get(), Vector2(0,0));
    m_spriteBatch->End();

    // �ʏ�̃X�v���C�g�o�b�`���J�n
    m_spriteBatch->Begin();

    // �X�e�[�^�X�A�C�R��
    m_spriteBatch->Draw(m_ruinsExplorer.Get(), DirectX::SimpleMath::Vector2(350,150));
    // �Z���N�g
    m_spriteBatch->Draw(m_titleSelect.Get(), DirectX::SimpleMath::Vector2(450, 400));
    // �Z���N�g�A�C�R��
    m_spriteBatch->Draw(m_selectIcon.Get(), m_selectPos);
    // i
    m_spriteBatch->Draw(m_i_Rotate.Get(), Vector2(485, 210), nullptr, 
        Colors::White, XMConvertToRadians(m_rotate), Vector2(25, 25));
    // o
    m_spriteBatch->Draw(m_o_Rotate.Get(), Vector2(810, 255), nullptr, 
        Colors::White, XMConvertToRadians(m_rotate), Vector2(25, 25));
    // �t�F�[�h�̐F
    Color color = Color(0.0f, 0.0f, 0.0f, m_alpha);
    // ���̃t�F�[�h
    m_spriteBatch->Draw(m_black.Get(), Vector2(0,0), color);

    // �ʏ�̃X�v���C�g�o�b�`���I��
    m_spriteBatch->End();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void TitleSceneUI::Finalize()
{
   
}