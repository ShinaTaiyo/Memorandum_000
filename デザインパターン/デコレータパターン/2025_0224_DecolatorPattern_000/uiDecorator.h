//=====================================================================
//
//�Q�O�Q�T�N�Q���Q�S���F�f�R���[�^�p�^�[�����m���߂�[main.h]
//Author:ShinaTaiyo
// 
// �T�v�F���̃I�u�W�F�N�g�̐U�镑����ύX�����A�����I�ȋ@�\����t���ł���B�p���ł͂Ȃ��A�R���|�W�V�����𗘗p���ċ@�\���g������B
// ���_�F�E�����̃N���X��ύX�����Ɋg���ł���
//       �E�_��ɈقȂ�@�\��g�ݍ��킹����
//=====================================================================


//=======================================
//�Q�d�C���N���[�h�h�~
//=======================================
#ifndef _UIDECORATOR_H_
#define _UIDECORATOR_H_
//=====================================================================

//=======================================
//�C���N���[�h
//=======================================
#include "main.h"
//=====================================================================

//=======================================
//�N���X
//=======================================

//*UI�R���|�[�l���g�N���X
class CUiComponent
{
public:
	//*�֐�
	CUiComponent();                              //�R���X�g���N�^
	virtual ~CUiComponent();                     //�f�X�g���N�^
	virtual void Draw() = 0;                     //�`�揈��
};

//*BasicUI�N���X�i���̏���)
class CBasicUi : public CUiComponent
{
public:
	//*�֐�
	CBasicUi();                                  //�R���X�g���N�^
	~CBasicUi() override;                        //�f�X�g���N�^
	void Draw() override;                        //�`�揈��
};

//*UI�f�R���[�^�[�N���X�i�@�\�̒ǉ�)
class CUiDecorator : public CUiComponent
{
protected:
	CUiComponent* m_pComponent;  //��������@�\
public:						    
	//*�֐�					    
	CUiDecorator(CUiComponent * Comp);           //�R���X�g���N�^
	~CUiDecorator() override;                    //�f�X�g���N�^
	void Draw() override;                        //�`�揈��
};

//*�����\���N���X
class CNumberDisplay : public CUiDecorator
{
public:
	CNumberDisplay(CUiComponent * Comp);         //�R���X�g���N�^
	~CNumberDisplay() override;                  //�f�X�g���N�^
	void Draw() override;                        //�`�揈��
};

//*�O�Ղ�����N���X
class CTrailEffect : public CUiDecorator
{
public:
	CTrailEffect(CUiComponent * Comp);           //�R���X�g���N�^
	~CTrailEffect() override;                    //�f�X�g���N�^
	void Draw() override;                        //�`�揈��
};

//�����N���X
class CExplosion : public CUiDecorator
{
public:
	CExplosion(CUiComponent* Comp);              //�R���X�g���N�^
	~CExplosion() override;                      //�f�X�g���N�^
	void Draw() override;                        //�`�揈��
};

#endif // !_UIDECORATOR_H_
