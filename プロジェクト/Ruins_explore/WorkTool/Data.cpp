//*=======================================================*
// Data.cpp
// �V�[�����ׂ��Ńf�[�^��n���p�̃N���X
//*=======================================================*
#include "pch.h"
#include "WorkTool/Data.h"

std::unique_ptr<Data> Data::m_Data = nullptr;

Data* const Data::GetInstance()
{
	if (m_Data == nullptr)
	{
		m_Data.reset(new Data());
	}
	return m_Data.get();
}

// �R���X�g���N�^
Data::Data()
	:
	m_playSceneResult{}
{

}

// �X�V����
void Data::Update()
{

}

// �I������
void Data::Finalize()
{

}



