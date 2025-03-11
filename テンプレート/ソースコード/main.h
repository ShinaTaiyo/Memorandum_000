//=====================================================================
//
//２０２５年３月１１日：テンプレートの学習[main.h]
//Author:ShinaTaiyo
// 
// 概要：型を変換して関数やクラスを使用することが可能
// 
//=====================================================================

//==================================
//２重インクルード防止
//==================================
#ifndef _MAIN_H_
#define _MAIN_H_
//=====================================================================

//==================================
//インクルード
//==================================
#include <iostream>
#include <vector>
#include <memory>
//=====================================================================
using namespace std;

//==================================================
//メモリリーク検出用
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

template <typename T>//テンプレートはコンパイラがテンプレートの実態を生成するための
                  //設計図。しかし宣言しただけではどのような処理をするかがわからないので
                  //コンパイラが正しくインスタンス化が出来ない。
                  //なのでテンプレートを使う前に関数やクラスの定義が必要。
                  //Tという文字が変数の型を表すテンプレート引数で、次の行からの関数定義部分のTをintやstringと言ったデータ型およびクラスに対応させて
                  //変数型の異なる関数をまとめて定義している。つまり使うときは毎回宣言する
   
//足し算
T Add(T a, T b)
{
	return a + b;
}

//引き算
template <typename T>
T Sub(T a, T b)
{
    return a - b;
}

class CComponent
{
public:
    CComponent() {};               //コンストラクタ
    virtual ~CComponent() {};      //デストラクタ
    virtual void Process() = 0;    //処理
};

class CSword : public CComponent
{
public:
    CSword() {};                                               //コンストラクタ
    virtual ~CSword() override {};                             //デストラクタ
    void Process() override { cout << "剣で切る！" << endl; }; //処理
    void AtkUp() { cout << "攻撃力がUP！" << endl; }           //攻撃力アップ！
};

class CMagic : public CComponent
{
public:
    CMagic() {};                                              //コンストラクタ
    ~CMagic() override {};                                    //デストラクタ
    void Process() override { cout << "魔法攻撃！" << endl; } //処理
    void MpHeal() { cout << "MPを回復！" << endl; }           //MP回復！
};

class CLance : public CComponent
{
public:
    CLance() {};                                              //コンストラクタ
    ~CLance() override {};                                    //デストラクタ
    void Process() override { cout << "突き攻撃！" << endl; } //処理
    void Crytical() { cout << "クリティカル攻撃！" << endl; } //クリティカル攻撃！
};

class CContainer : public CComponent
{
public:
    CContainer() {};                  //コンストラクタ
    ~CContainer() override {};        //デストラクタ
    void Process() override           
    {
        for (auto & child : m_Child)
        {
            child.get()->Process();//持たせた機能の処理を呼ぶ
        }
    
    };//処理

    void AddChild(unique_ptr<CComponent> pComponent)
    {
        m_Child.push_back(move(pComponent));//機能を追加 
    }

    template <typename T>
    T* GetChildType()
    {
        for (auto& child : m_Child)
        {
            if (auto castChild = dynamic_cast<T*>(child.get()))//代入した値がnullptrじゃなければtrueになるので、==じゃなくて=。getで生ポインタを取得
            {
                return castChild;
            }
        }
        return nullptr;
    }
private:
    vector<unique_ptr<CComponent>> m_Child;       //機能
};

#endif