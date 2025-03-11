//=====================================================================
//
//２０２５年３月１１日：テンプレートの学習[main.cpp]
//Author:ShinaTaiyo
// 
// 概要：型を変換して関数やクラスを使用することが可能
// 
//=====================================================================

//================================================
//インクルード
//================================================
#include "main.h"       //メイン
//===================================================================================================

//================================================
//静的メンバ宣言
//================================================
static constexpr int s_nAddData1 = 20;//足し算するデータ１
static constexpr int s_nAddData2 = 10;//足し算するデータ２
static constexpr float s_fAddData1 = 1.2f;//足し算するfloatのデータ１
static constexpr float s_fAddData2 = 2.4f;//足し算するfloatのデータ２
static constexpr int s_nSubData1 = 100;//引き算するデータ１
static constexpr int s_nSubData2 = 20;//引き算するデータ２
static constexpr float s_fSubData1 = 5.0f;//引き算するfloatのデータ１
static constexpr float s_fSubData2 = 3.0f;//引き算するfloatのデータ２
//===================================================================================================

//================================================
//メイン関数
//================================================
int main()
{
	//メモリリーク検出用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//===================================================
	//前編：関数テンプレートを使用してみる(Add、Sub)
	//===================================================

	cout << "指定した値や型で足し算したり引き算したりする" << endl;

	int nData = 0;                                                                                  //int代入用
	float fData = 0.0f;                                                                             //浮動小数代入用

	nData = Add(s_nAddData1, s_nAddData2);                                                          //int型のデータの合計
	cout << "int型の合計（足し算)" << s_nAddData1 <<"+" << s_nAddData2 << "=" << nData << endl;     //int型のデータの合計

	fData = Add(s_fAddData1, s_fAddData2);
	cout << "float型の合計（足し算)" << s_fAddData1 << "+" << s_fAddData2 << "=" << fData << endl;  //float型のデータの合計

	nData = Sub(s_nSubData1, s_nSubData2);
	cout << "int型の合計（引き算)" << s_nSubData1 << "-" << s_nSubData2 << "=" << nData << endl;    //int型のデータの合計

	fData = Sub(s_fSubData1, s_fSubData2);
	cout << "float型の合計（引き算)" << s_fSubData1 << "-" << s_fSubData2 << "=" << fData << endl;  //float型のデータの合計
	//========================================================================================================================================

    //======================================================================================
	//後編：学んだ知識を利用してコンポジットパターンのコンテナから指定した機能を取得する
	//======================================================================================

	cout << "コンポジットパターンのコンテナを生成" << endl;
	unique_ptr<CContainer> pContainer = make_unique<CContainer>();//コンポジットパターンのコンテナを生成
	
	cout << "剣の機能を追加" << endl;
	pContainer->AddChild(make_unique<CSword>());                  //剣を追加
	cout << "魔法の機能を追加" << endl;
	pContainer->AddChild(make_unique<CMagic>());                  //魔法を追加
	cout << "槍の機能を追加" << endl;
	pContainer->AddChild(make_unique<CLance>());                  //槍を追加

	cout << "コンテナが持っている機能全体の処理" << endl;
	pContainer->Process();                                        //処理

	cout << "剣の機能にアクセス" << endl;
	CSword * pSword = pContainer->GetChildType<CSword>();         //引数からしかテンプレートは推論できないので明示的に引数を指定
	pSword->AtkUp();                                              //剣の攻撃力を上げる
	
	cout << "魔法の機能にアクセス" << endl;
	CMagic* pMagic = pContainer->GetChildType<CMagic>();          //魔法機能を取得
	pMagic->MpHeal();                                             //MPを回復

	cout << "槍の機能にアクセス" << endl;
	CLance* pLance = pContainer->GetChildType<CLance>();          //槍の機能を取得
	pLance->Crytical();                                           //クリティカル攻撃
    //========================================================================================================================================

	getchar();//ENTER押下

	return 0;
}
//===================================================================================================