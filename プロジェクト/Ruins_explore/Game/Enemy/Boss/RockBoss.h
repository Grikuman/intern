/*
    �t�@�C��: RockBoss.h
    �N���X  : ��{�X�N���X
*/
#pragma once
#include <memory>
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "Game/Enemy/IEnemyState.h"

#include "RockBossSearch.h"
#include "RockBossAttack.h"
#include "RockBossDown.h"

class Player;

class RockBoss
{
public:
    // �R���X�g���N�^
    RockBoss(Player* player);
    // �f�X�g���N�^
    ~RockBoss();
    // ����������
    void Initialize(DirectX::SimpleMath::Vector3 position);
    // �X�V����
    void Update();
    // �`�悷��
    void Render();
    // �㏈��������
    void Finalize();
public:
    // �v���C���[���擾����
    Player* GetPlayer()                  { return m_player; }

    // ��{�X�T�[�`���擾����
    RockBossSearch* GetRockBossSearch()  { return m_RockBossSearch.get(); }
    // ��{�X�A�^�b�N���擾����
    RockBossAttack* GetRockBossAttack()  { return m_RockBossAttack.get(); }
    // ��{�X�_�E�����擾����
    RockBossDown* GetRockBossDown()      { return m_RockBossDown.get(); }

public:
    // �ʒu��ݒ肷��
    void SetPotision(const DirectX::SimpleMath::Vector3 position)  { m_position = position; }
    // ���x��ݒ肷��
    void SetVelocity(const DirectX::SimpleMath::Vector3 velocity)  { m_velocity = velocity; }
    // �p�x��ݒ肷��
    void SetAngle(const float angle)                               { m_angle = angle; }
    // �̗͂�ݒ肷��
    void SetHP(const float hp)                                     { m_hp = hp; }
    // �_���[�W���󂯂Ă��邩�ݒ肷��
    void SetHit(const bool isHit)                                  { m_isHit = isHit; }
    // �����󋵂�ݒ肷��
    void SetAlive(const bool isAlive)                              { m_isAlive = isAlive; }

    // �X�e�[�g��ύX����
    void ChangeState(IEnemyState* newState)                        { m_currentState = newState; }
public:
    // �ʒu���擾����
    DirectX::SimpleMath::Vector3 GetPosition() const  { return m_position; }
    // ���x���擾����
    DirectX::SimpleMath::Vector3 GetVelocity() const  { return m_velocity; }
    // �p�x���擾����
    float GetAngle() const                            { return m_angle; }
    // �̗͂��擾����
    float GetHP() const                               { return m_hp; }
    // �ő�̗͂��擾����
    float GetMAXHP() const                            { return MAXHP; }
    // �_���[�W���󂯂Ă��邩�擾����
    bool GetHit() const                               { return m_isHit; }
    // �����󋵂��擾����
    bool GetIsAlive() const                           { return m_isAlive; }
    // �o�E���f�B���O�X�t�B�A���擾����
    DirectX::BoundingSphere GetBoundingSphere() const;

private:
    // �������Ă��邩���肷��
    void CheckAlive();

private:
    // �v���C���[
    Player* m_player;
    // �X�e�[�g
    IEnemyState* m_currentState;
    // ���f��
    std::unique_ptr<DirectX::Model> m_model;
    // ���f��
    std::unique_ptr<DirectX::GeometricPrimitive> m_ball;

    // �T�[�`���
    std::unique_ptr<RockBossSearch> m_RockBossSearch;
    // �A�^�b�N���
    std::unique_ptr<RockBossAttack> m_RockBossAttack;
    // �_�E�����
    std::unique_ptr<RockBossDown> m_RockBossDown;

    // �ʒu
    DirectX::SimpleMath::Vector3 m_position;
    // ���x
    DirectX::SimpleMath::Vector3 m_velocity;
    // �p�x
    float m_angle;
    // �̗�
    float m_hp;
    // �ő�̗�
    const float MAXHP = 100;
    // �_���[�W���󂯂Ă��邩
    bool m_isHit;
    // ������
    bool m_isAlive;
};

