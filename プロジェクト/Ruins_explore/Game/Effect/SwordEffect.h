#pragma once
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <DirectXMath.h>

class SwordEffect
{
private:
    // ���ʂ̃X�e�[�g
    std::unique_ptr<DirectX::CommonStates> m_commonStates;
    // ���̓��C�A�E�g
    Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
    // �e�N�X�`���p
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture[6];
    // �v���~�e�B�u�o�b�`
    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionTexture>> m_primitiveBatch;
    // �G�t�F�N�g
    std::unique_ptr<DirectX::AlphaTestEffect> m_batchEffect;

    // �G�t�F�N�g�̈ʒu
    DirectX::SimpleMath::Vector3 m_position;
    // �摜�ύX�J�E���g
    int m_cnt;

public:
    SwordEffect(ID3D11Device* device);
    ~SwordEffect();

    void Update();

    // �v���C���[�̈ʒu��ݒ肷��
    void SetPosition(const DirectX::SimpleMath::Vector3& position);

    void Render(
        ID3D11DeviceContext1* context,
        DirectX::SimpleMath::Matrix view,
        DirectX::SimpleMath::Matrix proj);
    void Finalize();
};

