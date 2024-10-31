#pragma once
#ifndef InputDevice_DEFINED
#define InputDevice_DEFINED

class InputDevice final
{
public:
	//�C���v�b�g�f�o�C�X�̃C���X�^���X�擾
	static InputDevice* const GetInstance();

	// �L�[�{�[�h�̃C���X�^���X���擾����
	DirectX::Keyboard* GetKeyboard()                                                 { return m_keyboard.get(); }
	// �L�[�{�[�h�X�e�[�g�g���b�J�[�̃C���X�^���X���擾����
	DirectX::Keyboard::KeyboardStateTracker* GetKeyboardStateTracker()               { return m_keyboardStateTracker.get(); }
	// �L�[�{�[�h�X�e�[�g�̃C���X�^���X���擾����
	DirectX::Keyboard::State* GetKeyboardState()                                     { return m_keyboardState.get(); }

private:
	// �L�[�{�[�h���X�V����
	void UpdateKeyboardState();
private:
	// �R���X�g���N�^
	InputDevice();
	// �C���X�^���X���R�s�[���邱�Ƃ��֎~����
	void operator=(const InputDevice&) = delete;
	// �C���X�^���X�����[�u���邱�Ƃ��֎~����
	InputDevice& operator= (InputDevice&&) = delete;
	// �R�s�[�R���X�g���N�^�͋֎~����
	InputDevice(const InputDevice&) = delete;
	// ���[�u�R���X�g���N�^�͋֎~����
	InputDevice(InputDevice&&) = delete;

public:
	// ����������
	void Initialize();
	// �X�V����
	void Update();
	// �f�X�g���N�^
	~InputDevice() = default;

private:
	// �C���v�b�g�f�o�C�X
	static std::unique_ptr<InputDevice>                                          m_InputDevice;
	
	// �L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard>                                        m_keyboard;
	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker>                  m_keyboardStateTracker;
	std::unique_ptr<DirectX::Keyboard::State>                                 m_keyboardState;
};

#endif		// InputDevice_DEFINED
