#pragma once
#include "InvincibleEffect.h"

class CommonResources;
class Player;

class PlayerEffectManager
{
public:
    PlayerEffectManager(Player* player);
    ~PlayerEffectManager();
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
    // ���G�G�t�F�N�g�N���X
    std::unique_ptr<InvincibleEffect> m_invincibleEffect;
};

