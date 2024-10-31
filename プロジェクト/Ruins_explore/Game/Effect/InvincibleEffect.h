#pragma once
class CommonResources;
class Player;

class InvincibleEffect
{
public:
    InvincibleEffect(Player* player);
    ~InvincibleEffect();
    // ����������
    void Initialize();
    // �X�V����
    void Update();
    // �`�悷��
    void Render();
    // �㏈������
    void Finalize();
private:
    // �v���C���[
    Player* m_player;
    // ��
    std::unique_ptr<DirectX::GeometricPrimitive> m_sphere;
    // �u�����h�X�e�[�g
    ID3D11BlendState* m_blendState;

    // �A���t�@�l
    float m_alpha;
};


