/*
	�t�@�C��: Player.cpp
	�N���X  : �v���C���[�N���X
*/
#include "pch.h"
#include "Player.h"
#include "WorkTool/DeviceResources.h"
#include "WorkTool/Graphics.h"
#include "Libraries/NRLib/TPS_Camera.h"
#include "WorkTool/Resources.h"
#include "WorkTool/Data.h"
#include "WorkTool/InputDevice.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//---------------------------------------------------------
// �R���X�g���N�^
//---------------------------------------------------------
Player::Player()
	:
	m_playerUIManager{},
	m_playerEffectManager{},
	m_playerIdling{},
	m_playerAttack{},
	m_currentState{},
	m_model{},
	m_camera{},
	m_velocity{},
	m_playerAngle{},
	m_chargeCnt{},
	m_invincible{false},
	m_invincibleTime{}
{
	//�v���C���[���W�̏�����
	m_position = DirectX::SimpleMath::Vector3(0.f, 0.5f, 0.f);
	// �̗͂�ݒ�
	m_hp = MAX_HP;
	// �X�^�~�i��ݒ�
	m_stamina = MAX_STAMINA;
	// ���G���Ԃ�ݒ肷��
	m_invincibleTime = 120.f;
}

//---------------------------------------------------------
// �f�X�g���N�^
//---------------------------------------------------------
Player::~Player()
{

}

//---------------------------------------------------------
// ����������
//---------------------------------------------------------
void Player::Initialize()
{
	//D3D�f�o�C�X���擾
	auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();

	// UI�Ǘ��N���X���쐬
	m_playerUIManager = std::make_unique<PlayerUIManager>(this);
	m_playerUIManager->Initialize();

	// �G�t�F�N�g�Ǘ��N���X���쐬����
	m_playerEffectManager = std::make_unique<PlayerEffectManager>(this);
	m_playerEffectManager->Initialize();

	//�J�������쐬
	m_camera = std::make_unique<NRLib::TPS_Camera>();

	m_model = Resources::GetInstance()->GetModel(L"Player");

	// �X�e�[�g���쐬
	// �A�C�h�����O���
	m_playerIdling = std::make_unique<PlayerIdling>(this);
	m_playerIdling->Initialize();
	// �A�^�b�N���
	m_playerAttack = std::make_unique<PlayerAttack>(this);
	m_playerAttack->Initialize();
	// �_�b�V�����
	m_playerDash = std::make_unique<PlayerDash>(this);
	m_playerDash->Initialize();

	// �����X�e�[�g��ݒ�
	m_currentState = m_playerIdling.get();
}

//---------------------------------------------------------
// �X�V����
//---------------------------------------------------------
void Player::Update(float elapsedTime)
{	UNREFERENCED_PARAMETER(elapsedTime);

    // �L�[�{�[�h���擾����
	auto kb = InputDevice::GetInstance()->GetKeyboardState();

	// ���G�̏ꍇ��
	if (m_invincible)
	{
		// ���G���Ԃ�����������
		m_invincibleTime--;
		// ���G���Ԃ��I����
		if (m_invincibleTime <= 0.f)
		{
			m_invincibleTime = 120.f; // ���Z�b�g
			m_invincible = false;     // ���G����
		}
	}

	// �X�^�~�i�񕜃J�E���g���s��
	if (m_stamina != MAX_STAMINA)
	{
		m_chargeCnt++;
	}
	else // �ő�̏ꍇ�J�E���g�����Ȃ�
	{
		m_chargeCnt = 0.f; // �J�E���g���Z�b�g
	}
	// 3�b�J�E���g
	if (m_chargeCnt >= 180.f)
	{
		m_stamina++;       // �X�^�~�i���񕜂���
		m_chargeCnt = 0.f; // �J�E���g���Z�b�g
	}

	// ���x��������
	m_velocity = Vector3::Zero;

	//���݂̃X�e�[�g���X�V����
	m_currentState->Update(elapsedTime);

	// ��]�s����쐬����
	Matrix matrix = Matrix::CreateRotationY(XMConvertToRadians(m_playerAngle));

	// �ړ��ʂ�␳����
	m_velocity *= 0.05f;

	// ��]���������Ď��ۂɈړ�����
	m_position += Vector3::Transform(m_velocity, matrix);

	// �J�������X�V����
	m_camera->Update(m_position, matrix);

	// UI�Ǘ��N���X���X�V����
	m_playerUIManager->Update();

	// �G�t�F�N�g�Ǘ��N���X���X�V����
	m_playerEffectManager->Update();

	// �r���[�ƃv���W�F�N�V������ݒ肷��
	Graphics::GetInstance()->SetViewMatrix(m_camera->GetViewMatrix());
	Graphics::GetInstance()->SetProjectionMatrix(m_camera->GetProjectionMatrix());

	if (kb->F)
	{
		ChangeState(m_playerAttack.get());
	}
}

//---------------------------------------------------------
// �`�悷��
//---------------------------------------------------------
void Player::Render()
{
	// �v���C���[�̃X�e�[�g��`�悷��
	m_currentState->Render();

	// UI�Ǘ��N���X��`�悷��
	m_playerUIManager->Render();

	// �G�t�F�N�g�Ǘ��N���X�`�悷��
	m_playerEffectManager->Render();
}

//---------------------------------------------------------
// ��n������
//---------------------------------------------------------
void Player::Finalize()
{
	m_playerUIManager->Finalize();
	m_playerEffectManager->Finalize();
	m_playerIdling.reset();
	m_playerAttack.reset();
	m_playerDash.reset();
}

NRLib::TPS_Camera* Player::GetCamera()
{
	return m_camera.get();
}

DirectX::BoundingSphere Player::GetBoundingSphere()
{
	Vector3 center = m_position; // �����蔻�苅�̒��S
	float radius = 0.5f;         // �T�C�Y�ɉ����Ē���
	return DirectX::BoundingSphere(center, radius);
}

bool Player::GetIsAttack()
{
	if (m_currentState == m_playerAttack.get())
	{
		return true;
	}
	return false;
}

void Player::ChangeState(IState* newState)
{
	m_currentState = newState;
}