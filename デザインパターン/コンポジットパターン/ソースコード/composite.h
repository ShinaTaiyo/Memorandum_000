//=====================================================================
//
//２０２５年３月２日：コンポジットパターンを確かめる[composite.h]
//Author:ShinaTaiyo
// 
// 概要：コンポジットパターン（Composite Pattern）は、オブジェクトのツリー構造を作成し、個々のオブジェクトとその集合（コンポジット）を同じインターフェースで扱えるようにするデザインパターンです。
//       UIコンポーネントを柔軟に構成し、機能を追加・取得しやすくするために有効です。
// 利点：・柔軟な拡張性→新しい要素を追加しやすい
//       ・統一的な管理→個々のUI要素とその集合を同じように扱える。
//       ・再利用性→UIコンポーネントを個別に使用したり、コンテナにまとめたりできる。
//=====================================================================

//==================================
//２重インクルード防止
//==================================
#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
//=====================================================================

//==================================
//インクルード
//==================================
#include "main.h"
//=====================================================================

//==================================
//クラス
//==================================

//共通インターフェイス
class CUIComponent
{
public:
	CUIComponent();           //コンストラクタ
	virtual ~CUIComponent();  //デストラクタ
	virtual void Update() = 0;//更新処理
	virtual void Draw() = 0;  //描画処理
};

//数字を表示するクラス
class CNumberDisplay : public CUIComponent
{
private:
	int m_nValue;     //持たせる数値
public:
	CNumberDisplay(int nValue); //コンストラクタ
	~CNumberDisplay();          //デストラクタ
	void Update() override;     //更新処理
	void Draw() override;       //描画処理
};

//軌跡を描画するクラス
class CTrailEffect : public CUIComponent
{
public:
	CTrailEffect();         //コンストラクタ
	~CTrailEffect();        //デストラクタ
	void Update() override; //更新処理
	void Draw() override;   //描画処理
};

//回転処理を持つクラス
class CRotatingProcess : public CUIComponent
{
public:
	CRotatingProcess();         //コンストラクタ
	~CRotatingProcess();        //デストラクタ
	void Update() override;     //更新処理
	void Draw() override;       //描画処理
};

//複数のUIComponentを持つコンポジットクラス
class CUIContainer : public CUIComponent
{
private:
	vector<unique_ptr<CUIComponent>> m_Children;//所持している処理
public:
	CUIContainer();                               //コンストラクタ
	~CUIContainer();                              //デストラクタ
	void Add(unique_ptr<CUIComponent> Component); //処理の追加
	void Update();                                //更新処理
	void Draw();                                  //描画処理
};

#endif