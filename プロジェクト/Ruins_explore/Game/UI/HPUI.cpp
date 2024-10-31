
#include "pch.h"
#include "HPUI.h"
#include <PrimitiveBatch.h> 
#include <VertexTypes.h> 
#include <CommonStates.h>
#include "WorkTool/Graphics.h"
//#include <WICTextureLoader.h> 

using namespace DirectX;

const DirectX::VertexPositionColor HPUI::VERTICES_GREEN[4] =
{
    VertexPositionColor(SimpleMath::Vector3(-1.0f,  1.0f, 0.0f), Colors::Green), //����
    VertexPositionColor(SimpleMath::Vector3(1.0f,  1.0f, 0.0f), Colors::Green),  //�E��
    VertexPositionColor(SimpleMath::Vector3(1.0f, 0.5f, 0.0f), Colors::Green),   //�E��
    VertexPositionColor(SimpleMath::Vector3(-1.0f, 0.5f, 0.0f), Colors::Green),  //����
};

const DirectX::VertexPositionColor HPUI::VERTICES_RED[4] =
{
    VertexPositionColor(SimpleMath::Vector3(-1.0f,  1.0f, 0.0f), Colors::Red), //����
    VertexPositionColor(SimpleMath::Vector3(1.0f,  1.0f, 0.0f), Colors::Red),  //�E��
    VertexPositionColor(SimpleMath::Vector3(1.0f, 0.5f, 0.0f), Colors::Red),   //�E��
    VertexPositionColor(SimpleMath::Vector3(-1.0f, 0.5f, 0.0f), Colors::Red),  //����
};


/// <summary>
/// Constractor
/// </summary>
HPUI::HPUI(ID3D11Device1* device)
{
    // �G�t�F�N�g�̍쐬 
    m_BatchEffect = std::make_unique<BasicEffect>(device);
    m_BatchEffect->SetVertexColorEnabled(true);

    // ���̓��C�A�E�g���� 
    void const* shaderByteCode;
    size_t byteCodeLength;
    m_BatchEffect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
    device->CreateInputLayout(
        VertexPositionColor::InputElements,
        VertexPositionColor::InputElementCount,
        shaderByteCode, byteCodeLength, m_InputLayout.GetAddressOf()
    );

    //���ʃX�e�[�g�̍쐬
    m_States = std::make_unique<CommonStates>(device);

    m_scale = 1.f;
}


/// <summary>
/// Destractor
/// </summary>
HPUI::~HPUI()
{

}

/// <summary>
/// Render 
/// </summary>
void HPUI::Render(ID3D11DeviceContext1* context, SimpleMath::Matrix view, SimpleMath::Matrix proj)
{
    // �v���~�e�B�u�o�b�`�̍쐬 
    m_Batch = std::make_unique<PrimitiveBatch<VertexPositionColor>>(context);

    //m_Batch = Graphics::GetInstance()->GetPrimitiveBatch();

    // �J�����̈ʒu���擾
    SimpleMath::Matrix invView = view.Invert();
    SimpleMath::Vector3 camPos = invView.Translation();

    // �r���{�[�h�̕����x�N�g�����v�Z
    SimpleMath::Vector3 direction = camPos - m_Position;
    direction.Normalize();

    // �r���{�[�h�̉�]�s����쐬
    SimpleMath::Vector3 up(0.0f, 1.0f, 0.0f);
    SimpleMath::Vector3 right = up.Cross(direction);
    right.Normalize();
    up = direction.Cross(right);

    SimpleMath::Matrix billboardMatrix(
        right.x, right.y, right.z, 0.0f,
        up.x, up.y, up.z, 0.0f,
        direction.x, direction.y, direction.z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    // ���_���i�|���S���̒��_�j 
    VertexPositionColor vertex_g[4];
    VertexPositionColor vertex_r[4];

    // �΂̕����̕��𒲐�
    float greenWidth = (m_currentHP / m_maxHP) * 2.0f - 1.0f; // -1.0f ���� 1.0f �͈̔͂Œ���

    // HP�̗Ε����̏���
    for (int i = 0; i < 4; i++)
    {
        vertex_g[i] = VERTICES_GREEN[i];

        if (i == 1 || i == 2) // �E���̒��_�̂ݒ���
        {
            vertex_g[i].position.x = greenWidth;
        }

        // �O������w�肳�ꂽ�T�C�Y���g���āA�傫����ς���
        vertex_g[i].position.x *= m_scale;
        vertex_g[i].position.y *= m_scale;
        vertex_g[i].position.z *= m_scale;

        // �r���{�[�h�̉�]��K�p
        vertex_g[i].position = SimpleMath::Vector3::Transform(vertex_g[i].position, billboardMatrix);

        // �O������w�肳�ꂽ���W���g���Ĉړ�����
        vertex_g[i].position = vertex_g[i].position + m_Position;
    }

    // HP�̐ԕ����̏���
    for (int i = 0; i < 4; i++)
    {
        vertex_r[i] = VERTICES_RED[i];

        // �Ԃ̃o�[���������ɂ��炷
        vertex_r[i].position.z -= 0.01f;

        // �O������w�肳�ꂽ�T�C�Y���g���āA�傫����ς���
        vertex_r[i].position.x *= m_scale;
        vertex_r[i].position.y *= m_scale;
        vertex_r[i].position.z *= m_scale;

        // �r���{�[�h�̉�]��K�p
        vertex_r[i].position = SimpleMath::Vector3::Transform(vertex_r[i].position, billboardMatrix);

        // �O������w�肳�ꂽ���W���g���Ĉړ�����
        vertex_r[i].position = vertex_r[i].position + m_Position;
    }

    // �[�x�o�b�t�@�ɏ������ݎQ�Ƃ��� 
    context->OMSetDepthStencilState(m_States->DepthDefault(), 0);

    // ���ʂ͕`�悵�Ȃ�(�w�ʃJ�����O)
    context->RSSetState(m_States->CullCounterClockwise());

    // �G�t�F�N�g�̐ݒ�
    m_BatchEffect->SetWorld(SimpleMath::Matrix::Identity);
    m_BatchEffect->SetView(view);
    m_BatchEffect->SetProjection(proj);
    m_BatchEffect->Apply(context);
    context->IASetInputLayout(m_InputLayout.Get());

    // �|���S����`�� 
    m_Batch->Begin();
    m_Batch->DrawQuad(vertex_g[0], vertex_g[1], vertex_g[2], vertex_g[3]);
    m_Batch->DrawQuad(vertex_r[0], vertex_r[1], vertex_r[2], vertex_r[3]);
    m_Batch->End();
}



/// <summary>
/// Finalize 
/// </summary>
void HPUI::Finalize()
{

}

void HPUI::SetPosition(const DirectX::SimpleMath::Vector3& pos)
{
	m_Position = pos;
}

void HPUI::SetScale(const float& ratio)
{
	m_scale = ratio;
}

void HPUI::SetHP(float currentHP, float maxHP)
{
    m_currentHP = currentHP;
    m_maxHP = maxHP;
}