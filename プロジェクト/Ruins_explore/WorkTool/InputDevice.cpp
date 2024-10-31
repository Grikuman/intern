#include "pch.h"
#include "WorkTool/InputDevice.h"

std::unique_ptr<InputDevice> InputDevice::m_InputDevice = nullptr;

//�O���t�B�b�N�X�̃C���X�^���X���擾
InputDevice* const InputDevice::GetInstance()
{
	if (m_InputDevice == nullptr)
	{
		m_InputDevice.reset(new InputDevice());
	}
	return m_InputDevice.get();
}

// �R���X�g���N�^
InputDevice::InputDevice()
	:
	m_keyboard{},                        // �L�[�{�[�h
	m_keyboardStateTracker{},            // �L�[�{�[�h�X�e�[�g�g���b�J�[
	m_keyboardState{}                    // �L�[�{�[�h�X�e�[�g
{
	
}

// ����������
void InputDevice::Initialize()
{
	// �L�[�{�[�h�𐶐�����
	m_keyboard = std::make_unique<DirectX::Keyboard>();
	m_keyboardStateTracker = std::make_unique<DirectX::Keyboard::KeyboardStateTracker>();
	m_keyboardState = std::make_unique<DirectX::Keyboard::State>();
}

// �X�V����
void InputDevice::Update()
{
	// �L�[�{�[�h���X�V����
	UpdateKeyboardState();
}

// �L�[�{�[�h���X�V����
void InputDevice::UpdateKeyboardState()
{
	*m_keyboardState = m_keyboard->GetState();
	m_keyboardStateTracker->Update(*m_keyboardState);
}

