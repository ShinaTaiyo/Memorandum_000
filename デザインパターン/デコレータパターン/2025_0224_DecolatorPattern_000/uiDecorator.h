//=====================================================================
//
//２０２５年２月２４日：デコレータパターンを確かめる[main.h]
//Author:ShinaTaiyo
// 
// 概要：元のオブジェクトの振る舞いを変更せず、装飾的な機能を後付けできる。継承ではなく、コンポジションを利用して機能を拡張する。
// 利点：・既存のクラスを変更せずに拡張できる
//       ・柔軟に異なる機能を組み合わせられる
//=====================================================================


//=======================================
//２重インクルード防止
//=======================================
#ifndef _UIDECORATOR_H_
#define _UIDECORATOR_H_
//=====================================================================

//=======================================
//インクルード
//=======================================
#include "main.h"
//=====================================================================

//=======================================
//クラス
//=======================================

//*UIコンポーネントクラス
class CUiComponent
{
public:
	//*関数
	CUiComponent();                              //コンストラクタ
	virtual ~CUiComponent();                     //デストラクタ
	virtual void Draw() = 0;                     //描画処理
};

//*BasicUIクラス（基底の処理)
class CBasicUi : public CUiComponent
{
public:
	//*関数
	CBasicUi();                                  //コンストラクタ
	~CBasicUi() override;                        //デストラクタ
	void Draw() override;                        //描画処理
};

//*UIデコレータークラス（機能の追加)
class CUiDecorator : public CUiComponent
{
protected:
	CUiComponent* m_pComponent;  //持たせる機能
public:						    
	//*関数					    
	CUiDecorator(CUiComponent * Comp);           //コンストラクタ
	~CUiDecorator() override;                    //デストラクタ
	void Draw() override;                        //描画処理
};

//*数字表示クラス
class CNumberDisplay : public CUiDecorator
{
public:
	CNumberDisplay(CUiComponent * Comp);         //コンストラクタ
	~CNumberDisplay() override;                  //デストラクタ
	void Draw() override;                        //描画処理
};

//*軌跡をつけるクラス
class CTrailEffect : public CUiDecorator
{
public:
	CTrailEffect(CUiComponent * Comp);           //コンストラクタ
	~CTrailEffect() override;                    //デストラクタ
	void Draw() override;                        //描画処理
};

//爆発クラス
class CExplosion : public CUiDecorator
{
public:
	CExplosion(CUiComponent* Comp);              //コンストラクタ
	~CExplosion() override;                      //デストラクタ
	void Draw() override;                        //描画処理
};

#endif // !_UIDECORATOR_H_
