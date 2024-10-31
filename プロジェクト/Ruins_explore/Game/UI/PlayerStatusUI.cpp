/*
    @file    PlayerStatusUI.cpp
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#include "pch.h"
#include "PlayerStatusUI.h"
#include "Game/Player/Player.h"

#include "WorkTool/DeviceResources.h"
#include "Libraries/MyLib/InputManager.h"
#include "PlayerUIManager.h"
#include "WorkTool/Graphics.h"
#include "WorkTool/Resources.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
PlayerStatusUI::PlayerStatusUI(Player* player)
    :
    m_player{player},
    m_healthPosition{},
    m_backPosition{},
    m_framePosition{},
    m_staminaPosition{},
    m_scale{1.f},
    m_matrix{},
    m_tex_HealthRed{},
    m_tex_HealthGray{},
    m_tex_StaminaYellow{},
    m_tex_StaminaGray{},
    m_tex_StatusIcon{},
    m_tex_HelthGaugeFrame{}
{

}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
PlayerStatusUI::~PlayerStatusUI()
{
    
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void PlayerStatusUI::Initialize()
{
    // �X�^�~�i�̈ʒu��ݒ肷��
    for (int i = 0; i < m_player->GetMAXHP(); i++)
    {
        m_healthPosition[i] = Vector2(53.f * i + 108.f, 600.f);
    }
    // �X�^�~�i�̈ʒu��ݒ肷��
    for (int i = 0; i < m_player->GetMAXSTAMINA(); i++)
    {
        m_staminaPosition[i] = Vector2(50.f * i + 130.f, 660.f);
    }
    // �X�e�[�^�X�A�C�R���̈ʒu��ݒ肷��
    m_backPosition = Vector2(10.f,600.f);
    // �Q�[�W�̘g�̈ʒu��ݒ肷��
    m_framePosition = Vector2(120.f, 610.f);

    // �摜��ǂݍ���
    m_tex_StatusIcon            = Resources::GetInstance()->GetTexture(L"Status_Icon");

    for (int i = 0; i < 6; i++)
    {
        m_tex_HealthRed[i]      = Resources::GetInstance()->GetTexture(L"Health_Red");
        m_tex_HealthGray[i]     = Resources::GetInstance()->GetTexture(L"Health_Gray");
        m_tex_StaminaYellow[i]  = Resources::GetInstance()->GetTexture(L"Stamina_Yellow");
        m_tex_StaminaGray[i]    = Resources::GetInstance()->GetTexture(L"Stamina_Gray");
    }

    // �X�v���C�g�o�b�`��ݒ肷��
    m_spriteBatch = Graphics::GetInstance()->GetSpriteBatch();
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void PlayerStatusUI::Update()
{
    // ���݂�HP�������v�Z
    m_scale = static_cast<float>(m_player->GetHP() / m_player->GetMAXHP());
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void PlayerStatusUI::Render()
{
    // �ʏ�̃X�v���C�g�o�b�`���J�n
    m_spriteBatch->Begin();

    // �X�e�[�^�X�A�C�R����`�悷��
    m_spriteBatch->Draw(m_tex_StatusIcon.Get(), m_backPosition);

    // �̗�(�D�F)
    for (int i = 0; i < m_player->GetMAXHP(); i++)
    {
        m_spriteBatch->Draw(m_tex_HealthGray[i].Get(), m_healthPosition[i]);
    }
    // �X�^�~�i(�D�F)
    for (int i = 0; i < m_player->GetMAXSTAMINA(); i++)
    {
        m_spriteBatch->Draw(m_tex_StaminaGray[i].Get(), m_staminaPosition[i]);
    }

    // �̗�(�ԐF)
    for (int i = 0; i < m_player->GetHP(); i++)
    {
        m_spriteBatch->Draw(m_tex_HealthRed[i].Get(), m_healthPosition[i]);
    }
    // �X�^�~�i(���F)
    for (int i = 0; i < m_player->GetStamina(); i++)
    {
        m_spriteBatch->Draw(m_tex_StaminaYellow[i].Get(), m_staminaPosition[i]);
    }

    // �ʏ�̃X�v���C�g�o�b�`���I��
    m_spriteBatch->End();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void PlayerStatusUI::Finalize()
{
   
}