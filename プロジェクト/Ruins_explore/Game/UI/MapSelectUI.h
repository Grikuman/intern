/*
    @file    MapSelectUI.h
    @brief   �v���C���[��UI���Ǘ�����N���X
*/
#pragma once

class MapSelectScene;

class MapSelectUI
{
public:
    // �R���X�g���N�^
    MapSelectUI(MapSelectScene* mapSelectScene);
    // �f�X�g���N�^
    ~MapSelectUI();
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
    MapSelectScene* m_mapSelectScene;;
    //�X�v���C�g�o�b�`
    DirectX::DX11::SpriteBatch* m_spriteBatch;

    // 
    //Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_;
};
