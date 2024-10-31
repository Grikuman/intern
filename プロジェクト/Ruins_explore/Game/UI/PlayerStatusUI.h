/*
    @file    PlayerStatusUI.h
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#pragma once

// �O���錾
class Player;

class PlayerStatusUI
{
public:
    // �R���X�g���N�^
    PlayerStatusUI(Player* player);
    // �f�X�g���N�^
    ~PlayerStatusUI();
    // ����������
    void Initialize();
    // �X�V����
    void Update();
    // �`�悷��
    void Render();
    // �㏈������
    void Finalize();
private:
    // Player
    Player* m_player;

    //�X�v���C�g�o�b�`
    DirectX::DX11::SpriteBatch* m_spriteBatch;
    // �̗�(�ԐF)
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_tex_HealthRed[6];
    // �̗�(�D�F)
    Microsoft::WRL::ComPtr< ID3D11ShaderResourceView> m_tex_HealthGray[6];
    // �X�^�~�i(���F)
    Microsoft::WRL::ComPtr< ID3D11ShaderResourceView> m_tex_StaminaYellow[6];
    // �X�^�~�i(�D�F)
    Microsoft::WRL::ComPtr< ID3D11ShaderResourceView> m_tex_StaminaGray[6];
    // �X�e�[�^�X�A�C�R��
    Microsoft::WRL::ComPtr < ID3D11ShaderResourceView> m_tex_StatusIcon;
    // �̗̓Q�[�W�̘g
    Microsoft::WRL::ComPtr < ID3D11ShaderResourceView> m_tex_HelthGaugeFrame;
    // �X�^�~�i�Q�[�W�̘g
    Microsoft::WRL::ComPtr < ID3D11ShaderResourceView> m_tex_StaminaGaugeFrame;

    // �X�P�[��
    float m_scale;
    // HP�̕\������(matrix)
    DirectX::SimpleMath::Matrix m_matrix;

    // �̗͂̈ʒu
    DirectX::SimpleMath::Vector2 m_healthPosition[6];
    // �X�^�~�i�̈ʒu
    DirectX::SimpleMath::Vector2 m_staminaPosition[6];
    // �X�e�[�^�X�A�C�R���̈ʒu
    DirectX::SimpleMath::Vector2 m_backPosition;
    // �Q�[�W�̘g�̈ʒu
    DirectX::SimpleMath::Vector2 m_framePosition;
};
