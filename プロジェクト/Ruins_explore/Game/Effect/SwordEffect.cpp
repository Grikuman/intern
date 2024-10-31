#pragma once
#include "pch.h"
#include "Game/Effect/SwordEffect.h"
#include <WICTextureLoader.h>
#include "Mouse.h"

SwordEffect::SwordEffect(ID3D11Device* device)
{
    // �G�t�F�N�g�̍쐬
    m_batchEffect = std::make_unique<DirectX::AlphaTestEffect>(device);
    m_batchEffect->SetAlphaFunction(D3D11_COMPARISON_EQUAL);
    m_batchEffect->SetReferenceAlpha(255);

    // ���̓��C�A�E�g�𐶐�����
    void const* shaderByteCode;
    size_t byteCodeLength;
    m_batchEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
    device->CreateInputLayout(
        DirectX::VertexPositionTexture::InputElements,
        DirectX::VertexPositionTexture::InputElementCount,
        shaderByteCode, byteCodeLength, m_inputLayout.GetAddressOf()
    );

    // ���ʃX�e�[�g���쐬����
    m_commonStates = std::make_unique<DirectX::CommonStates>(device);

    // �e�N�X�`�������[�h����
    for (int i = 0; i < 6; i++)
    {
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_1.png", nullptr, m_texture[0].GetAddressOf());
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_2.png", nullptr, m_texture[1].GetAddressOf());
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_3.png", nullptr, m_texture[2].GetAddressOf());
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_4.png", nullptr, m_texture[3].GetAddressOf());
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_5.png", nullptr, m_texture[4].GetAddressOf());
        DirectX::CreateWICTextureFromFile(device, L"Resources/Effect/SwordEffect_6.png", nullptr, m_texture[5].GetAddressOf());
    }

    m_position = DirectX::SimpleMath::Vector3::Zero; // �f�t�H���g�ʒu

    m_cnt = 0;
}

SwordEffect::~SwordEffect()
{

}

void SwordEffect::Update()
{
    m_cnt++;
    if (m_cnt >= 30)
    {
        m_cnt = 0;
    }
}

void SwordEffect::SetPosition(const DirectX::SimpleMath::Vector3& position)
{
    m_position = position;
}

void SwordEffect::Render(
    ID3D11DeviceContext1* context,
    DirectX::SimpleMath::Matrix view,
    DirectX::SimpleMath::Matrix proj)
{
    // �v���~�e�B�u�o�b�`�̍쐬
    m_primitiveBatch = std::make_unique<DirectX::PrimitiveBatch<DirectX::VertexPositionTexture>>(context);

    // ���_���i�|���S���̒��_�j
    DirectX::VertexPositionTexture vertex[4] =
    {
        DirectX::VertexPositionTexture(m_position + DirectX::SimpleMath::Vector3(2.0f, 0.5f, 2.0f), DirectX::SimpleMath::Vector2(0.0f, 1.0f)),
        DirectX::VertexPositionTexture(m_position + DirectX::SimpleMath::Vector3(-2.0f, 0.5f, 2.0f), DirectX::SimpleMath::Vector2(1.0f, 1.0f)),
        DirectX::VertexPositionTexture(m_position + DirectX::SimpleMath::Vector3(-2.0f, 0.5f, -2.0f), DirectX::SimpleMath::Vector2(1.0f, 0.0f)),
        DirectX::VertexPositionTexture(m_position + DirectX::SimpleMath::Vector3(2.0f, 0.5f, -2.0f), DirectX::SimpleMath::Vector2(0.0f, 0.0f)),
    };

    // �e�N�X�`���T���v���[�̐ݒ�i�N�����v�e�N�X�`���A�h���b�V���O���[�h�j
    ID3D11SamplerState* samplers[1] = { m_commonStates->PointWrap() };
    context->PSSetSamplers(0, 1, samplers);

    // �[�x�o�b�t�@�ɏ������ݎQ�Ƃ���
    context->OMSetDepthStencilState(m_commonStates->DepthDefault(), 0);

    // �J�����O�͍�����i�����v���j
    context->RSSetState(m_commonStates->CullCounterClockwise());

    // �s�����̂ݕ`�悷��ݒ�
    m_batchEffect->SetAlphaFunction(D3D11_COMPARISON_NOT_EQUAL);
    m_batchEffect->SetReferenceAlpha(0);
    m_batchEffect->SetWorld(DirectX::SimpleMath::Matrix::Identity);
    m_batchEffect->SetView(view);
    m_batchEffect->SetProjection(proj);
    m_batchEffect->SetTexture(m_texture[(m_cnt / 5) % 6].Get());
    m_batchEffect->Apply(context);
    context->IASetInputLayout(m_inputLayout.Get());

    // ������������`��
    m_primitiveBatch->Begin();
    m_primitiveBatch->DrawQuad(vertex[0], vertex[1], vertex[2], vertex[3]);
    m_primitiveBatch->End();
}

void SwordEffect::Finalize()
{

}
