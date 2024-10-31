#pragma once
#ifndef Resources_DEFINED
#define Resources_DEFINED

#include "WorkTool/DeviceResources.h"
#include <unordered_map>
#include <string>

class Resources final
{
public:
	//���\�[�X�N���X�̃C���X�^���X�擾
	static Resources* const GetInstance();
	
private:
	// �R���X�g���N�^
	Resources();
	// �C���X�^���X���R�s�[���邱�Ƃ��֎~����
	void operator=(const Resources&) = delete;
	// �C���X�^���X�����[�u���邱�Ƃ��֎~����
	Resources& operator= (Resources&&) = delete;
	// �R�s�[�R���X�g���N�^�͋֎~����
	Resources(const Resources&) = delete;
	// ���[�u�R���X�g���N�^�͋֎~����
	Resources(Resources&&) = delete;

public:
	// �f�X�g���N�^
	~Resources() = default;
	// ���\�[�X��ǂݍ���
	void LoadResources();

	// ���f�����擾����
	DirectX::Model* GetModel(const wchar_t* name);
	// �e�N�X�`�����擾����
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> GetTexture(const wchar_t* name);

private:
	static std::unique_ptr<Resources> m_resources;
	// ���f���i�[
	std::unordered_map<const wchar_t*, std::unique_ptr<DirectX::Model>> m_models;
	// �e�N�X�`���i�[
	std::unordered_map<const wchar_t*, Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>> m_textures;
};

#endif		// Resources_DEFINED
