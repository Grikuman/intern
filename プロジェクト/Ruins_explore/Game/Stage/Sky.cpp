/*
	@file	Sky.cpp
	@brief	��ʓI�ȃV�[���N���X
*/
#include "pch.h"
#include "Sky.h"
#include "WorkTool/DeviceResources.h"
#include "Libraries/MyLib/DebugCamera.h"
#include "Libraries/MyLib/DebugString.h"
#include "Libraries/MyLib/InputManager.h"
#include "Libraries/MyLib/MemoryLeakDetector.h"
#include <cassert>
#include "WorkTool/Graphics.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
Sky::Sky()
	:
	m_projection{},
	m_model{}
{
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
Sky::~Sky()
{
	// do nothing.
}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void Sky::Initialize()
{
	auto device  = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	auto states  = Graphics::GetInstance()->GetCommonStates();

	// �ˉe�s����쐬����
	m_projection = SimpleMath::Matrix::CreatePerspectiveFieldOfView(
		XMConvertToRadians(45.0f),
		1280 / 720,
		0.1f, 1000.0f
	);
	/*
		�E�ˉe�s���far�v���[������������
		�E�J������far�v���[�����󋵂ɉ����ăC�C�����ɒ�������
		����:
		45.f�̓J�����̉�p
		static_cast���s���Ă��镔���͉�ʃT�C�Y
		0.1f�̓J�������������ԋ߂�����
		1000.f�̕�����100.f�Ȃǂɂ���Ɖf��Ȃ��Ȃ�ꍇ������
	*/


	// ���f����ǂݍ��ޏ���
	std::unique_ptr<EffectFactory> fx = std::make_unique<EffectFactory>(device);
	fx->SetDirectory(L"Resources/Models");

	// ���f����ǂݍ���
	m_model = Model::CreateFromCMO(device, L"Resources/Models/skydome_night.cmo", *fx);
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void Sky::Update()
{
	
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void Sky::Render()
{
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	auto states  = Graphics::GetInstance()->GetCommonStates();

	// �r���[�s����擾����
	Matrix view = Graphics::GetInstance()->GetViewMatrix();


	// ���f���̃G�t�F�N�g�����X�V����
	m_model->UpdateEffects([](DirectX::IEffect* effect)
		{
			// �x�[�V�b�N�G�t�F�N�g��ݒ肷��
			BasicEffect* basicEffect = dynamic_cast<BasicEffect*>(effect);
			if (basicEffect)
			{
				//// ���C�g��L��������
				//basicEffect->SetLightingEnabled(true);
				/*
					�E���f���N���X�ł̓f�t�H���g�œ����I�Ƀ��C�g���L��������Ă���
					�E���̐ݒ肪�����Ă����C�g�͗L��������Ă���
				*/

				// �ʂ̃��C�g�����ׂĖ���������
				basicEffect->SetLightEnabled(0, false);
				basicEffect->SetLightEnabled(1, false);
				basicEffect->SetLightEnabled(2, false);

				// ���f����������������
				basicEffect->SetEmissiveColor(Colors::White);
			}
		}
	);

	// ���[���h�s����X�V����
	Matrix world = Matrix::Identity;
	world *= Matrix::CreateRotationX(XMConvertToRadians(180));

	// ���f����`�悷��
	m_model->Draw(context, *states, world, view, m_projection);


	// �f�o�b�O����\������
	//auto debugString = m_commonResources->GetDebugString();
	//debugString->AddString("SkySphere");
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void Sky::Finalize()
{
	// do nothing.
}
