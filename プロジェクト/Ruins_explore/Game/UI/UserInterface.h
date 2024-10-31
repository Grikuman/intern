//--------------------------------------------------------------------------------------
// File: UserInterface.h
//
// ���[�U�[�C���^�[�t�F�[�X�N���X
//
//-------------------------------------------------------------------------------------

#pragma once

#include "StepTimer.h"
#include "WorkTool/DeviceResources.h"
#include <SimpleMath.h>
#include <Effects.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <WICTextureLoader.h>
#include <CommonStates.h>
#include <vector>
class UserInterface
{
public:
	//UI�̃A���J�[�|�C���g�̗񋓐�
	enum ANCHOR
	{
		TOP_LEFT = 0,
		TOP_CENTER,
		TOP_RIGHT,

		MIDDLE_LEFT,
		MIDDLE_CENTER,
		MIDDLE_RIGHT,

		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT

	};
public:
	//�f�[�^�󂯓n���p�R���X�^���g�o�b�t�@(���M��)
	struct ConstBuffer
	{
		DirectX::SimpleMath::Vector4	windowSize;
	};

	//�֐�
public:
	static const std::vector<D3D11_INPUT_ELEMENT_DESC> INPUT_LAYOUT;

	// �R���X�g���N�^
	UserInterface();
	// �f�X�g���N�^
	~UserInterface();
	// �e�N�X�`����ǂݍ���
	void LoadTexture(const wchar_t* path);
	
	void Create(DX::DeviceResources* pDR
		, const wchar_t* path
		, DirectX::SimpleMath::Vector2 position
		, DirectX::SimpleMath::Vector2 scale
		, ANCHOR anchor);
	// �`�悷��
	void Render();
	// ��ʃT�C�Y��ݒ肷��
	void SetWindowSize(const int& width, const int& height);

public:
	// �X�P�[����ݒ肷��
	void SetScale(DirectX::SimpleMath::Vector2 scale);
	// �ʒu��ݒ肷��
	void SetPosition(DirectX::SimpleMath::Vector2 position);
	// �A���J�[��ݒ肷��
	void SetAnchor(ANCHOR anchor);
	// �`��䗦��ݒ肷��
	void SetRenderRatio(float ratio);
	// �`��䗦�ł̃I�t�Z�b�g��ݒ肷��(�ǂꂾ�����炷��)
	void SetRenderRatioOffset(float offset);

public:
	// �X�P�[�����擾����
	DirectX::SimpleMath::Vector2 GetScale()        { return m_scale; }
	// ��b�̃X�P�[�����擾����
	DirectX::SimpleMath::Vector2 GetBaseScale()    { return m_baseScale; }
	// �ʒu���擾����
	DirectX::SimpleMath::Vector2 GetPosition()     { return m_position; }
	// �A���J�[���擾����
	ANCHOR GetAnchor()                             { return m_anchor; }
	// �`��䗦���擾����
	float GetRenderRatio()                         { return m_renderRatio; }
	// �`��䗦�ł̃I�t�Z�b�g���擾����
	float GetRenderRatioOffset()                   { return m_renderRatioOffset; }

private:

	void CreateShader();
	//�ϐ�
private:
	DX::DeviceResources*                             m_pDR;

	Microsoft::WRL::ComPtr<ID3D11Buffer>	         m_CBuffer;

	DX::StepTimer                                    m_timer;
	// ���̓��C�A�E�g
	Microsoft::WRL::ComPtr<ID3D11InputLayout>        m_inputLayout;

	// �v���~�e�B�u�o�b�`
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColorTexture>> m_batch;
	//�R�����X�e�[�g
	std::unique_ptr<DirectX::CommonStates>           m_states;
	// �e�N�X�`���n���h��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	Microsoft::WRL::ComPtr<ID3D11Resource>           m_res;
	// ���_�V�F�[�_
	Microsoft::WRL::ComPtr<ID3D11VertexShader>       m_vertexShader;
	// �s�N�Z���V�F�[�_
	Microsoft::WRL::ComPtr<ID3D11PixelShader>        m_pixelShader;
	// �W�I���g���V�F�[�_
	Microsoft::WRL::ComPtr<ID3D11GeometryShader>     m_geometryShader;

	// ��ʂ̕��ƍ���
	int m_windowWidth, m_windowHeight;
	// �e�N�X�`���̕��ƍ���
	int m_textureWidth, m_textureHeight;

	// �X�P�[��
	DirectX::SimpleMath::Vector2                     m_scale;
	// ��b�X�P�[��
	DirectX::SimpleMath::Vector2                     m_baseScale;
	// �ʒu
	DirectX::SimpleMath::Vector2                     m_position;
	// �A���J�[
	ANCHOR m_anchor;
	// �`��䗦
	float m_renderRatio;
	// �`��䗦�̃I�t�Z�b�g
	float m_renderRatioOffset;

};