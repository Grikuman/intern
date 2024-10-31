//*=======================================================*
// Collision.cpp
//*=======================================================*
#include "pch.h"
#include "WorkTool/Collision.h"

#include "Game/Player/Player.h"
#include "Game/Enemy/Tunomaru.h"
#include "Game/Enemy/Boss/RockBoss.h"

std::unique_ptr<Collision> Collision::m_collision = nullptr;

Collision* const Collision::GetInstance()
{
	if (m_collision == nullptr)
	{
		m_collision.reset(new Collision());
	}
	return m_collision.get();
}

// �R���X�g���N�^
Collision::Collision()
{

}

// �X�V����
void Collision::Update()
{

}

// �I������
void Collision::Finalize()
{

}

// �̂܂�Ƃ̓����蔻��
void Collision::CheckHitTunomaru(Tunomaru* tunomaru)
{
    // �v���C���[���U��
    if (m_player->GetIsAttack())
    {
        // �U���͈͓��ɂ���Ȃ�_���[�W���󂯂�
        if (m_player->GetPlayerAttack()->GetAttackRange().Intersects(tunomaru->GetBoundingSphere()))
        {
            tunomaru->SetHP(tunomaru->GetHP() - 1.f);
        }
    }
}

// ��{�X�Ƃ̓����蔻��
void Collision::CheckHitRockBoss(RockBoss* rockboss)
{
    // �v���C���[���U��
    if (m_player->GetIsAttack())
    {
        // �U���͈͓��ɂ���Ȃ�_���[�W���󂯂�
        if (m_player->GetPlayerAttack()->GetAttackRange().Intersects(rockboss->GetBoundingSphere()))
        {
            rockboss->SetHP(rockboss->GetHP() - 0.5f);
        }
    }
}



