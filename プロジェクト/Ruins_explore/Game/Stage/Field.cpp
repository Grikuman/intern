/*
	@file	Field.cpp
	@brief	��ʓI�ȃV�[���N���X
*/
#include "pch.h"
#include "Game/Stage/Field.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/MyLib/InputManager.h"
#include "Libraries/MyLib/MemoryLeakDetector.h"
#include <cassert>
#include <GeometricPrimitive.h>
#include "Libraries/NRLib/TPS_Camera.h"
#include "WorkTool/Graphics.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
Field::Field()
	:
	m_pyramid{}
{
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
Field::~Field()
{
	
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void Field::Initialize()
{
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();

	// �I�u�W�F�N�g���쐬
	m_box = DirectX::GeometricPrimitive::CreateBox(context, Vector3(50.f, 2.f, 50.f));

	// �e�t�B�[���h�I�u�W�F�N�g�̈ʒu��ݒ�
	m_boxPos = Vector3(0.f, -1.f, 0.f);

	// ���f����ǂݍ��ޏ���
	std::unique_ptr<DirectX::EffectFactory> fx = std::make_unique<DirectX::EffectFactory>(device);
	fx->SetDirectory(L"Resources/Models");
	// ���f����ǂݍ���
	m_pyramid = DirectX::Model::CreateFromCMO(device, L"Resources/Models/Block.cmo", *fx);
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void Field::Update()
{
	
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void Field::Render()
{
	// world�s��͏㏑�����Ďg����
	DirectX::SimpleMath::Matrix world = Matrix::Identity;
	DirectX::SimpleMath::Matrix view = Graphics::GetInstance()->GetViewMatrix();
	DirectX::SimpleMath::Matrix proj = Graphics::GetInstance()->GetProjectionMatrix();

	// �I�u�W�F�N�g�̕`��
	world *= Matrix::CreateTranslation(m_boxPos);
	m_box->Draw(world, view, proj, Colors::DarkGray);

	world = Matrix::CreateScale(0.1f);
	world *= Matrix::CreateTranslation(Vector3(0.f, 0.f, 0.f));
	
	//m_pyramid->Draw(context, *states, world, view, proj);
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void Field::Finalize()
{
	// do nothing.
}
