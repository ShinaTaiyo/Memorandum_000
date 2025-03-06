//=====================================================================
//
//�Q�O�Q�T�N�R���Q���F�R���|�W�b�g�p�^�[�����m���߂�[composite.h]
//Author:ShinaTaiyo
// 
// �T�v�F�R���|�W�b�g�p�^�[���iComposite Pattern�j�́A�I�u�W�F�N�g�̃c���[�\�����쐬���A�X�̃I�u�W�F�N�g�Ƃ��̏W���i�R���|�W�b�g�j�𓯂��C���^�[�t�F�[�X�ň�����悤�ɂ���f�U�C���p�^�[���ł��B
//       UI�R���|�[�l���g���_��ɍ\�����A�@�\��ǉ��E�擾���₷�����邽�߂ɗL���ł��B
// ���_�F�E�_��Ȋg�������V�����v�f��ǉ����₷��
//       �E����I�ȊǗ����X��UI�v�f�Ƃ��̏W���𓯂��悤�Ɉ�����B
//       �E�ė��p����UI�R���|�[�l���g���ʂɎg�p������A�R���e�i�ɂ܂Ƃ߂���ł���B
//=====================================================================

//==================================
//�Q�d�C���N���[�h�h�~
//==================================
#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
//=====================================================================

//==================================
//�C���N���[�h
//==================================
#include "main.h"
//=====================================================================

//==================================
//�N���X
//==================================

//���ʃC���^�[�t�F�C�X
class CUIComponent
{
public:
	CUIComponent();           //�R���X�g���N�^
	virtual ~CUIComponent();  //�f�X�g���N�^
	virtual void Update() = 0;//�X�V����
	virtual void Draw() = 0;  //�`�揈��
};

//������\������N���X
class CNumberDisplay : public CUIComponent
{
private:
	int m_nValue;     //�������鐔�l
public:
	CNumberDisplay(int nValue); //�R���X�g���N�^
	~CNumberDisplay();          //�f�X�g���N�^
	void Update() override;     //�X�V����
	void Draw() override;       //�`�揈��
};

//�O�Ղ�`�悷��N���X
class CTrailEffect : public CUIComponent
{
public:
	CTrailEffect();         //�R���X�g���N�^
	~CTrailEffect();        //�f�X�g���N�^
	void Update() override; //�X�V����
	void Draw() override;   //�`�揈��
};

//��]���������N���X
class CRotatingProcess : public CUIComponent
{
public:
	CRotatingProcess();         //�R���X�g���N�^
	~CRotatingProcess();        //�f�X�g���N�^
	void Update() override;     //�X�V����
	void Draw() override;       //�`�揈��
};

//������UIComponent�����R���|�W�b�g�N���X
class CUIContainer : public CUIComponent
{
private:
	vector<unique_ptr<CUIComponent>> m_Children;//�������Ă��鏈��
public:
	CUIContainer();                               //�R���X�g���N�^
	~CUIContainer();                              //�f�X�g���N�^
	void Add(unique_ptr<CUIComponent> Component); //�����̒ǉ�
	void Update();                                //�X�V����
	void Draw();                                  //�`�揈��
};

#endif