/*
    �t�@�C��: Tunomaru.h
    �N���X  : �̂܂�N���X
*/
#pragma once
#include <memory>
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "Game/UI/HPUI.h"
#include "IEnemyState.h"

#include "TunomaruSearch.h"
#include "TunomaruAttack.h"
#include "TunomaruDown.h"

class Player;

class Tunomaru 
{
public:
    // �R���X�g���N�^
    Tunomaru(Player* player);
    // �f�X�g���N�^
    ~Tunomaru();
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
    Player* GetPlayer() { return m_player; }

    // �̂܂�T�[�`���擾����
    TunomaruSearch* GetTunomaruSearch() { return m_tunomaruSearch.get(); }
    // �̂܂�A�^�b�N���擾����
    TunomaruAttack* GetTunomaruAttack() { return m_tunomaruAttack.get(); }
    // �̂܂�_�E�����擾����
    TunomaruDown* GetTunomaruDown() { return m_tunomaruDown.get(); }

public:
    // �ʒu��ݒ肷��
    void SetPotision(const DirectX::SimpleMath::Vector3 position) { m_position = position; }
    // ���x��ݒ肷��
    void SetVelocity(const DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
    // �p�x��ݒ肷��
    void SetAngle(const float angle) { m_angle = angle; }
    // �̗͂�ݒ肷��
    void SetHP(const float hp) { m_hp = hp; }
    // �_���[�W���󂯂Ă��邩�ݒ肷��
    void SetHit(const bool isHit) { m_isHit = isHit; }
    // �����󋵂�ݒ肷��
    void SetAlive(const bool isAlive) { m_isAlive = isAlive; }

public:
    // �ʒu���擾����
    DirectX::SimpleMath::Vector3 GetPosition() const { return m_position; }
    // ���x���擾����
    DirectX::SimpleMath::Vector3 GetVelocity() const { return m_velocity; }
    // �p�x���擾����
    float GetAngle() const { return m_angle; }
    // �̗͂��擾����
    float GetHP() const { return m_hp; }
    // �_���[�W���󂯂Ă��邩�擾����
    bool GetHit() const { return m_isHit; }
    // �����󋵂��擾����
    bool GetIsAlive() const { return m_isAlive; }
    // �o�E���f�B���O�X�t�B�A���擾����
    DirectX::BoundingSphere GetBoundingSphere() const;

private:
    // �������Ă��邩���肷��
    void CheckAlive();

public:
    // �X�e�[�g��ύX����
    void ChangeState(IEnemyState* newState);
private:
    //HPUI
    std::unique_ptr<HPUI> m_hpUI;
    // �v���C���[
    Player* m_player;
    // �X�e�[�g
    IEnemyState* m_currentState;
    // ���f��
    DirectX::Model* m_model;
    // ���f��
    std::unique_ptr<DirectX::GeometricPrimitive> m_ball;

    // �T�[�`���
    std::unique_ptr<TunomaruSearch> m_tunomaruSearch;
    // �A�^�b�N���
    std::unique_ptr<TunomaruAttack> m_tunomaruAttack;
    // �_�E�����
    std::unique_ptr<TunomaruDown> m_tunomaruDown;

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

