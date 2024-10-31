/*
	
*/
#include "pch.h"
#include "Game/UI/EnemyUIManager.h"
#include "Gauge.h"
#include "WorkTool/Graphics.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
EnemyUIManager::EnemyUIManager()
	:
	m_gauge{}
{

}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
EnemyUIManager::~EnemyUIManager()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void EnemyUIManager::Initialize()
{

	m_gauge = std::make_unique<Gauge>();
	
	m_gauge->Initialize(Graphics::GetInstance()->GetDeviceResources(), 1280,720);
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void EnemyUIManager::Update(float bossHP,float MAX_BossHP)
{
	m_gauge->Update(bossHP,MAX_BossHP);
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void EnemyUIManager::Render()
{
	m_gauge->Render();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void EnemyUIManager::Finalize()
{
	
}