#pragma once
#include <PrimitiveBatch.h>
#include <VertexTypes.h>

class HPUI 
{
private:
    //HP�̗Ε���
    static const DirectX::VertexPositionColor VERTICES_GREEN[4];
    //HP�̐ԕ���
    static const DirectX::VertexPositionColor VERTICES_RED[4];

    //  ���W�p�̕ϐ������
    DirectX::SimpleMath::Vector3 m_Position;

    //  �T�C�Y�p�̕ϐ�
    float m_scale;

    // ���̓��C�A�E�g 
    Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;

    //���ʃX�e�[�g�I�u�W�F�N�g�ւ̃|�C���^
    std::unique_ptr<DirectX::CommonStates> m_States;

    // �e�N�X�`���n���h�� 
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Texture;

    // �G�t�F�N�g 
    std::unique_ptr<DirectX::BasicEffect> m_BatchEffect;

    // �v���~�e�B�u�o�b�` 
    std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_Batch;
    //DirectX::PrimitiveBatch<DirectX::VertexPositionColor>* m_Batch;
    // ���݂�HP
    float m_currentHP;
    // �ő�HP
    float m_maxHP;

public:
    HPUI(ID3D11Device1* device);
    ~HPUI();

    void Render(ID3D11DeviceContext1* context, DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj);
    void Finalize();

    void SetPosition(const DirectX::SimpleMath::Vector3& pos);
    void SetScale(const float& ratio);
    void SetHP(float currentHP, float maxHP);
};