/*
    @file    TitleSceneUI.h
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#pragma once

class TitleScene;

class TitleSceneUI
{
public:
    // �R���X�g���N�^
    TitleSceneUI(TitleScene* titlescene);
    // �f�X�g���N�^
    ~TitleSceneUI();
    // ����������
    void Initialize();
    // �X�V����
    void Update();
    // �`�悷��
    void Render();
    // �㏈������
    void Finalize();

private:
    // �^�C�g���V�[��
    TitleScene* m_titleScene;
    //�X�v���C�g�o�b�`
    DirectX::DX11::SpriteBatch* m_spriteBatch;

    // �^�C�g������
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_ruinsExplorer;
    // �^�C�g���Z���N�g
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_titleSelect;
    // �Z���N�g�A�C�R��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_selectIcon;
    // i�Eo�̂��邮��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_i_Rotate;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_o_Rotate;
    // �^�C�g���w�i
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_titleBackGround;
    // ��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_black;

    // �Z���N�g�ʒu
    DirectX::SimpleMath::Vector2 m_selectPos;
    // �Z���N�g�t���O
    bool m_selectFlag;
    // ��]
    float m_rotate;
    // �A���t�@�l
    float m_alpha;
    // �t�F�[�h�t���O
    bool m_fadeFlag;
    // �X�P�[��
    float m_scale;
};
