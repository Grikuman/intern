#include "pch.h"
#include "TimeUI.h"
#include "WorkTool/Graphics.h"

using namespace DirectX;

/// <summary>
/// Constructor
/// </summary>
TimeUI::TimeUI(ID3D11Device* device, ID3D11DeviceContext* context)
    :
    m_time{}
{
    // �X�v���C�g�o�b�`�ƃX�v���C�g�t�H���g��������
    m_spriteBatch = Graphics::GetInstance()->GetSpriteBatch();
    m_spriteFont = Graphics::GetInstance()->GetFont();
}

/// <summary>
/// Destructor
/// </summary>
TimeUI::~TimeUI()
{
    Finalize();
}

void TimeUI::Update(float elapedTime)
{
    m_time = elapedTime;
}

/// <summary>
/// Render 
/// </summary>
void TimeUI::Render()
{
    m_spriteBatch->Begin();

    // ���l�𕶎���ɕϊ�
    std::wstring timeString = L"TimeLimit : " + std::to_wstring(m_time);

    // �\������e�L�X�g�A�ʒu�A�F���w�肵�ĕ`��
    m_spriteFont->DrawString(m_spriteBatch, timeString.c_str(), 
        SimpleMath::Vector2(width - 400, 20), // position
        Colors::White,                        // color
        0.f,                                  // rotate
        SimpleMath::Vector2::Zero,
        1.4f                                  // scale
    );

    m_spriteBatch->End();
}

/// <summary>
/// Finalize 
/// </summary>
void TimeUI::Finalize()
{
    
}
