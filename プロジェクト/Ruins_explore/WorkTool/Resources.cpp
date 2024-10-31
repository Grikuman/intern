#include "pch.h"
#include "Resources.h"
#include "Graphics.h"

std::unique_ptr<Resources> Resources::m_resources = nullptr;

using namespace Microsoft::WRL;

//�O���t�B�b�N�X�̃C���X�^���X���擾
Resources* const Resources::GetInstance()
{
	if (m_resources == nullptr)
	{
		m_resources.reset(new Resources());
	}
	return m_resources.get();
}

// �R���X�g���N�^
Resources::Resources()
	:
	m_models{},
	m_textures{}
{
	
}

void Resources::LoadResources()
{
	// �f�o�C�X�ƃR���e�L�X�g���擾����
	auto device = Graphics::GetInstance()->GetDeviceResources()->GetD3DDevice();
	auto context = Graphics::GetInstance()->GetDeviceResources()->GetD3DDeviceContext();
	// �G�t�F�N�g�t�@�N�g���[���擾����
	DirectX::EffectFactory* fx = Graphics::GetInstance()->GetFX();

	//============
	// * ���f�� *
	//============
	// �v���C���[
	std::unique_ptr<DirectX::Model> player = DirectX::Model::CreateFromCMO(device, L"Resources/Models/Player.cmo", *fx);
	// �̂܂�
	std::unique_ptr<DirectX::Model> tunomaru = DirectX::Model::CreateFromCMO(device, L"Resources/Models/Tunomaru.cmo", *fx);
	// ��{�X
	std::unique_ptr<DirectX::Model> rockBoss   = DirectX::Model::CreateFromCMO(device, L"Resources/Models/RockBoss.cmo", *fx);
	// ���f����o�^����
	m_models.emplace(L"Player", std::move(player));
	m_models.emplace(L"Tunomaru", std::move(tunomaru));
	m_models.emplace(L"RockBoss", std::move(rockBoss));

	//================
	// * �e�N�X�`�� *
	//================
	// �ϐ�
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> health_red;       // �̗�(��)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> health_gray;      // �̗�(�D�F)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> stamina_yellow;   // �X�^�~�i(���F)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> stamina_gray;     // �X�^�~�i(�D�F)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> status_icon;      // �X�e�[�^�X�A�C�R��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> ruins_explorer;   // �^�C�g������
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> titleselect;      // �^�C�g���Z���N�g
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> selecticon;       // �Z���N�g�A�C�R��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> i_rotate;         // i�̂��邮��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> o_rotate;         // o�̂��邮��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> titlebackground;  // �^�C�g���w�i
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> black;            // ��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> clear;            // �N���A����
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> dead;             // ���S����
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> resultclear;      // �N���A���
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> resultdead;       // ���S���
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pushspacekey;     // �X�y�[�X�L�[


	// �ǂݍ���
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Health_Red.png", nullptr, health_red.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Health_Gray.png", nullptr, health_gray.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Stamina_Yellow.png", nullptr, stamina_yellow.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Stamina_Gray.png", nullptr, stamina_gray.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Status_icon.png", nullptr, status_icon.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Ruins_Explorer.png", nullptr, ruins_explorer.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/TitleSelect.png", nullptr, titleselect.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/SelectIcon.png", nullptr, selecticon.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/i_rotate.png", nullptr, i_rotate.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/o_rotate.png", nullptr, o_rotate.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/TitleScene.png", nullptr, titlebackground.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Black.png", nullptr, black.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Clear_text.png", nullptr, clear.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Dead_text.png", nullptr, dead.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Alive.png", nullptr, resultclear.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/Dead.png", nullptr, resultdead.GetAddressOf());
	DirectX::CreateWICTextureFromFile(device, context, L"Resources/Textures/PushSpaceKey.png", nullptr, pushspacekey.GetAddressOf());

	// �e�N�X�`����o�^����
	m_textures.emplace(L"Health_Red", health_red);
	m_textures.emplace(L"Health_Gray", health_gray);
	m_textures.emplace(L"Stamina_Yellow", stamina_yellow);
	m_textures.emplace(L"Stamina_Gray", stamina_gray);
	m_textures.emplace(L"Status_Icon", status_icon);
	m_textures.emplace(L"Ruins_Explorer", ruins_explorer);
	m_textures.emplace(L"TitleSelect", titleselect);
	m_textures.emplace(L"SelectIcon", selecticon);
	m_textures.emplace(L"i_Rotate", i_rotate);
	m_textures.emplace(L"o_Rotate", o_rotate);
	m_textures.emplace(L"TitleBackGround", titlebackground);
	m_textures.emplace(L"Black", black);
	m_textures.emplace(L"Clear", clear);
	m_textures.emplace(L"Dead", dead);
	m_textures.emplace(L"ResultClear", resultclear);
	m_textures.emplace(L"ResultDead", resultdead);
	m_textures.emplace(L"PushSpaceKey", pushspacekey);
}

// ���f�����擾����
DirectX::Model* Resources::GetModel(const wchar_t* name)
{
	// ���f������������
	auto it = m_models.find(name);
	//�@���f���̃|�C���^��Ԃ�
	return it->second.get();
}

// �e�N�X�`�����擾����
Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> Resources::GetTexture(const wchar_t* name)
{
	// ���f������������
	auto it = m_textures.find(name);
	// �e�N�X�`����Ԃ�
	return it->second;
}

