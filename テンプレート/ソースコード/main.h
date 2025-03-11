//=====================================================================
//
//�Q�O�Q�T�N�R���P�P���F�e���v���[�g�̊w�K[main.h]
//Author:ShinaTaiyo
// 
// �T�v�F�^��ϊ����Ċ֐���N���X���g�p���邱�Ƃ��\
// 
//=====================================================================

//==================================
//�Q�d�C���N���[�h�h�~
//==================================
#ifndef _MAIN_H_
#define _MAIN_H_
//=====================================================================

//==================================
//�C���N���[�h
//==================================
#include <iostream>
#include <vector>
#include <memory>
//=====================================================================
using namespace std;

//==================================================
//���������[�N���o�p
//==================================================
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK , __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

template <typename T>//�e���v���[�g�̓R���p�C�����e���v���[�g�̎��Ԃ𐶐����邽�߂�
                  //�݌v�}�B�������錾���������ł͂ǂ̂悤�ȏ��������邩���킩��Ȃ��̂�
                  //�R���p�C�����������C���X�^���X�����o���Ȃ��B
                  //�Ȃ̂Ńe���v���[�g���g���O�Ɋ֐���N���X�̒�`���K�v�B
                  //T�Ƃ����������ϐ��̌^��\���e���v���[�g�����ŁA���̍s����̊֐���`������T��int��string�ƌ������f�[�^�^����уN���X�ɑΉ�������
                  //�ϐ��^�̈قȂ�֐����܂Ƃ߂Ē�`���Ă���B�܂�g���Ƃ��͖���錾����
   
//�����Z
T Add(T a, T b)
{
	return a + b;
}

//�����Z
template <typename T>
T Sub(T a, T b)
{
    return a - b;
}

class CComponent
{
public:
    CComponent() {};               //�R���X�g���N�^
    virtual ~CComponent() {};      //�f�X�g���N�^
    virtual void Process() = 0;    //����
};

class CSword : public CComponent
{
public:
    CSword() {};                                               //�R���X�g���N�^
    virtual ~CSword() override {};                             //�f�X�g���N�^
    void Process() override { cout << "���Ő؂�I" << endl; }; //����
    void AtkUp() { cout << "�U���͂�UP�I" << endl; }           //�U���̓A�b�v�I
};

class CMagic : public CComponent
{
public:
    CMagic() {};                                              //�R���X�g���N�^
    ~CMagic() override {};                                    //�f�X�g���N�^
    void Process() override { cout << "���@�U���I" << endl; } //����
    void MpHeal() { cout << "MP���񕜁I" << endl; }           //MP�񕜁I
};

class CLance : public CComponent
{
public:
    CLance() {};                                              //�R���X�g���N�^
    ~CLance() override {};                                    //�f�X�g���N�^
    void Process() override { cout << "�˂��U���I" << endl; } //����
    void Crytical() { cout << "�N���e�B�J���U���I" << endl; } //�N���e�B�J���U���I
};

class CContainer : public CComponent
{
public:
    CContainer() {};                  //�R���X�g���N�^
    ~CContainer() override {};        //�f�X�g���N�^
    void Process() override           
    {
        for (auto & child : m_Child)
        {
            child.get()->Process();//���������@�\�̏������Ă�
        }
    
    };//����

    void AddChild(unique_ptr<CComponent> pComponent)
    {
        m_Child.push_back(move(pComponent));//�@�\��ǉ� 
    }

    template <typename T>
    T* GetChildType()
    {
        for (auto& child : m_Child)
        {
            if (auto castChild = dynamic_cast<T*>(child.get()))//��������l��nullptr����Ȃ����true�ɂȂ�̂ŁA==����Ȃ���=�Bget�Ő��|�C���^���擾
            {
                return castChild;
            }
        }
        return nullptr;
    }
private:
    vector<unique_ptr<CComponent>> m_Child;       //�@�\
};

#endif