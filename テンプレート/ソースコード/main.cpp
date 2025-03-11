//=====================================================================
//
//�Q�O�Q�T�N�R���P�P���F�e���v���[�g�̊w�K[main.cpp]
//Author:ShinaTaiyo
// 
// �T�v�F�^��ϊ����Ċ֐���N���X���g�p���邱�Ƃ��\
// 
//=====================================================================

//================================================
//�C���N���[�h
//================================================
#include "main.h"       //���C��
//===================================================================================================

//================================================
//�ÓI�����o�錾
//================================================
static constexpr int s_nAddData1 = 20;//�����Z����f�[�^�P
static constexpr int s_nAddData2 = 10;//�����Z����f�[�^�Q
static constexpr float s_fAddData1 = 1.2f;//�����Z����float�̃f�[�^�P
static constexpr float s_fAddData2 = 2.4f;//�����Z����float�̃f�[�^�Q
static constexpr int s_nSubData1 = 100;//�����Z����f�[�^�P
static constexpr int s_nSubData2 = 20;//�����Z����f�[�^�Q
static constexpr float s_fSubData1 = 5.0f;//�����Z����float�̃f�[�^�P
static constexpr float s_fSubData2 = 3.0f;//�����Z����float�̃f�[�^�Q
//===================================================================================================

//================================================
//���C���֐�
//================================================
int main()
{
	//���������[�N���o�p
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//===================================================
	//�O�ҁF�֐��e���v���[�g���g�p���Ă݂�(Add�ASub)
	//===================================================

	cout << "�w�肵���l��^�ő����Z����������Z�����肷��" << endl;

	int nData = 0;                                                                                  //int����p
	float fData = 0.0f;                                                                             //������������p

	nData = Add(s_nAddData1, s_nAddData2);                                                          //int�^�̃f�[�^�̍��v
	cout << "int�^�̍��v�i�����Z)" << s_nAddData1 <<"+" << s_nAddData2 << "=" << nData << endl;     //int�^�̃f�[�^�̍��v

	fData = Add(s_fAddData1, s_fAddData2);
	cout << "float�^�̍��v�i�����Z)" << s_fAddData1 << "+" << s_fAddData2 << "=" << fData << endl;  //float�^�̃f�[�^�̍��v

	nData = Sub(s_nSubData1, s_nSubData2);
	cout << "int�^�̍��v�i�����Z)" << s_nSubData1 << "-" << s_nSubData2 << "=" << nData << endl;    //int�^�̃f�[�^�̍��v

	fData = Sub(s_fSubData1, s_fSubData2);
	cout << "float�^�̍��v�i�����Z)" << s_fSubData1 << "-" << s_fSubData2 << "=" << fData << endl;  //float�^�̃f�[�^�̍��v
	//========================================================================================================================================

    //======================================================================================
	//��ҁF�w�񂾒m���𗘗p���ăR���|�W�b�g�p�^�[���̃R���e�i����w�肵���@�\���擾����
	//======================================================================================

	cout << "�R���|�W�b�g�p�^�[���̃R���e�i�𐶐�" << endl;
	unique_ptr<CContainer> pContainer = make_unique<CContainer>();//�R���|�W�b�g�p�^�[���̃R���e�i�𐶐�
	
	cout << "���̋@�\��ǉ�" << endl;
	pContainer->AddChild(make_unique<CSword>());                  //����ǉ�
	cout << "���@�̋@�\��ǉ�" << endl;
	pContainer->AddChild(make_unique<CMagic>());                  //���@��ǉ�
	cout << "���̋@�\��ǉ�" << endl;
	pContainer->AddChild(make_unique<CLance>());                  //����ǉ�

	cout << "�R���e�i�������Ă���@�\�S�̂̏���" << endl;
	pContainer->Process();                                        //����

	cout << "���̋@�\�ɃA�N�Z�X" << endl;
	CSword * pSword = pContainer->GetChildType<CSword>();         //�������炵���e���v���[�g�͐��_�ł��Ȃ��̂Ŗ����I�Ɉ������w��
	pSword->AtkUp();                                              //���̍U���͂��グ��
	
	cout << "���@�̋@�\�ɃA�N�Z�X" << endl;
	CMagic* pMagic = pContainer->GetChildType<CMagic>();          //���@�@�\���擾
	pMagic->MpHeal();                                             //MP����

	cout << "���̋@�\�ɃA�N�Z�X" << endl;
	CLance* pLance = pContainer->GetChildType<CLance>();          //���̋@�\���擾
	pLance->Crytical();                                           //�N���e�B�J���U��
    //========================================================================================================================================

	getchar();//ENTER����

	return 0;
}
//===================================================================================================