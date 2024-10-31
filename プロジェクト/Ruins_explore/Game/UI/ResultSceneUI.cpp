/*
    @file    TitleSceneUI.cpp
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#include "pch.h"
#include "ResultSceneUI.h"
#include "Game/Scene/ResultScene.h"
#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"
#include "WorkTool/Data.h"
#include "WorkTool/InputDevice.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
ResultSceneUI::ResultSceneUI(ResultScene* result)
    :
    m_selectIcon{},
    m_clear{},
    m_dead{},
    m_resultClear{},
    m_resultDead{},
    m_black{},
    m_pushSpaceKey{},
    m_selectPos{},
    m_selectFlag{true},
    m_alpha{1.0f},
    m_spaceAlpha{1.0f},
    m_fadeFlag{false},
    m_time{}
{
    
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
ResultSceneUI::~ResultSceneUI()
{
    
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void ResultSceneUI::Initialize()
{
    // �X�v���C�g�o�b�`��ݒ肷��
    m_spriteBatch     = Graphics::GetInstance()->GetSpriteBatch();
    // �摜���擾����
    m_selectIcon      = Resources::GetInstance()->GetTexture(L"SelectIcon");
    m_clear           = Resources::GetInstance()->GetTexture(L"Clear");
    m_dead            = Resources::GetInstance()->GetTexture(L"Dead");;
    m_resultClear     = Resources::GetInstance()->GetTexture(L"ResultClear");;
    m_resultDead      = Resources::GetInstance()->GetTexture(L"ResultDead");
    m_black           = Resources::GetInstance()->GetTexture(L"Black");
    m_pushSpaceKey    = Resources::GetInstance()->GetTexture(L"PushSpaceKey");
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void ResultSceneUI::Update()
{
    // �L�[�{�[�h���擾����
    auto kb = InputDevice::GetInstance()->GetKeyboardStateTracker();

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
    
    // �t���O���ƂɃZ���N�g�A�C�R���̈ʒu���ړ�
    if (m_selectFlag)
    {
        m_selectPos = Vector2(500, 390);
    }
    else
    {
        m_selectPos = Vector2(500, 510);
    }

    // �t�F�[�h�C������
    if (m_alpha >= 0)
    {
        m_alpha -= 0.008f;
    }
    // �_�ł̑��x��ݒ�
    float blinkSpeed = 5.0f; // 1�b�Ԃ�1��_��
    // ���ԉ��Z
    m_time += 0.016f;
    // sin�֐����g���āA0����1�̊Ԃŕω�������
    m_spaceAlpha = (sin(m_time * blinkSpeed) + 1) / 2; // 0-1�͈̔͂Ɏ��߂�
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void ResultSceneUI::Render()
{
    // �ʏ�̃X�v���C�g�o�b�`���J�n
    m_spriteBatch->Begin();

    // �� ���U���g���ʂŕ\����ύX���� ��
    if (Data::GetInstance()->GetPlaySceneResult()) // ����
    {
        m_spriteBatch->Draw(m_resultClear.Get(), Vector2(0, 0));
        m_spriteBatch->Draw(m_clear.Get(), Vector2(200, 50));
    }
    else // ���S
    {
        m_spriteBatch->Draw(m_resultDead.Get(), Vector2(0, 0));
        m_spriteBatch->Draw(m_dead.Get(), Vector2(200, 50));
    }
    // �X�y�[�X�L�[�̃t�F�[�h�J���[
    Color spacecolor = Color(0.9f, 0.9f, 0.9f, m_spaceAlpha);
    // �X�y�[�X�L�[
    m_spriteBatch->Draw(m_pushSpaceKey.Get(), Vector2(400, 580),spacecolor);

    // �t�F�[�h�̐F
    Color color = Color(0.0f, 0.0f, 0.0f, m_alpha);
    // ���̃t�F�[�h
    m_spriteBatch->Draw(m_black.Get(), Vector2(0, 0), color);

    // �ʏ�̃X�v���C�g�o�b�`���I��
    m_spriteBatch->End();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void ResultSceneUI::Finalize()
{
   
}