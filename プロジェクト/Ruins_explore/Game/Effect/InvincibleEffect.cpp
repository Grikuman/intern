#pragma once
#include "pch.h"
#include "Game/Effect/InvincibleEffect.h"
#include "Game/Player/Player.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/NRLib/TPS_Camera.h"
#include "WorkTool/Graphics.h"

InvincibleEffect::InvincibleEffect(Player* player)
    :
    m_player{ player },
    m_sphere{},
    m_blendState{ nullptr },
    m_alpha{}
{

}

InvincibleEffect::~InvincibleEffect()
{
    
}

// ������
void InvincibleEffect::Initialize()
{
    auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();

    // �����쐬����
    m_sphere = DirectX::GeometricPrimitive::CreateSphere(context, 2.6f);

    // �u�����h�X�e�[�g���쐬����
    D3D11_BLEND_DESC blendDesc = {};
    blendDesc.RenderTarget[0].BlendEnable = TRUE;
    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    device->CreateBlendState(&blendDesc, &m_blendState);
}

// �X�V����
void InvincibleEffect::Update()
{
    // ���G���Ԃ̏ꍇ
    if (m_player->GetInvincible())
    {
        m_alpha = 0.3f;   // �A���t�@�l
    }
    // ���G���ԂłȂ��ꍇ
    else
    {
        m_alpha -= 0.03f; // �A���t�@�l������
    }

    // �A���t�@�l�̐���
    if (m_alpha <= 0)
    {
        m_alpha = 0.f;
    }
}

// �`�悷��
void InvincibleEffect::Render()
{
    auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();

    // �u�����h�X�e�[�g��L���ɂ���
    float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    context->OMSetBlendState(m_blendState, blendFactor, 0xFFFFFFFF);

    // ���̂̐F�Ɠ����x��ݒ�
    DirectX::SimpleMath::Color color(0.0f, 1.0f, 1.0f, m_alpha);

    // ���̂̃��[���h�s����v�Z���ĕ`��
    DirectX::SimpleMath::Matrix world = 
        DirectX::SimpleMath::Matrix::CreateTranslation(
        m_player->GetPosition() + DirectX::SimpleMath::Vector3(0.f,0.6f,0.f));
    m_sphere->Draw(world, m_player->GetCamera()->GetViewMatrix(), m_player->GetCamera()->GetProjectionMatrix(), color);

    // �u�����h�X�e�[�g�����Z�b�g����
    context->OMSetBlendState(nullptr, blendFactor, 0xFFFFFFFF);
}

// �㏈������
void InvincibleEffect::Finalize()
{
    
}
