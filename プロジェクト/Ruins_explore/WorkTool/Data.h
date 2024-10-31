//*=======================================================*
// Data.h
// �����F�����蔻����s��
//*=======================================================*
#pragma once

class Data
{
public:
	// �R���W�����̃C���X�^���X�擾
	static Data* const GetInstance();
private:
	// �R���X�g���N�^
	Data();
	// �C���X�^���X���R�s�[���邱�Ƃ��֎~����
	void operator=(const Data&) = delete;
	// �C���X�^���X�����[�u���邱�Ƃ��֎~����
	Data& operator= (Data&&) = delete;
	// �R�s�[�R���X�g���N�^�͋֎~����
	Data(const Data&) = delete;
	// ���[�u�R���X�g���N�^�͋֎~����
	Data(Data&&) = delete;

public:
	//�f�X�g���N�^
	~Data() = default;
	// �X�V����
	void Update();
	// �I������
	void Finalize();
public:
	// �v���C�V�[���̌��ʂ�ݒ肷��
	void SetPlaySceneResult(const bool result) { m_playSceneResult = result; };

public:
	// �v���C�V�[���̌��ʂ��擾����
	bool GetPlaySceneResult() const { return m_playSceneResult; }

private:
	// �R���W�����N���X
	static std::unique_ptr<Data> m_Data;
	// �v���C�V�[���̌���
	bool m_playSceneResult;
};