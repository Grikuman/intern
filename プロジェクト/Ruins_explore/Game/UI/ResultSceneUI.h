/*
    @file    ResultSceneUI.h
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#pragma once

class ResultScene;

class ResultSceneUI
{
public:
    // �R���X�g���N�^
    ResultSceneUI(ResultScene* result);
    // �f�X�g���N�^
    ~ResultSceneUI();
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
    ResultScene* m_resultScene;
    //�X�v���C�g�o�b�`
    DirectX::DX11::SpriteBatch* m_spriteBatch;

    // �Z���N�g�A�C�R��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_selectIcon;
    // �N���A����
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_clear;
    // ���S����
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_dead;
    // ���U���g�N���A���
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_resultClear;
    // ���U���g���S���
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_resultDead;
    // ��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_black;
    // �X�y�[�X�L�[
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_pushSpaceKey;

    // �Z���N�g�ʒu
    DirectX::SimpleMath::Vector2 m_selectPos;
    // �Z���N�g�t���O
    bool m_selectFlag;
    // �A���t�@�l
    float m_alpha;
    // �X�y�[�X�L�[�̃A���t�@�l
    float m_spaceAlpha;
    // �t�F�[�h�t���O
    bool m_fadeFlag;
    // ����
    float m_time;
};
