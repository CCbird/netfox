#pragma once
/*
注意：
1.位置号，视图号要区分开

修改内容：
1.看牌有标记；
2.下注做了判定；
3.
4.
*/

#include "Stdafx.h"
#include "GameClientView.h"
#define   BOTTOMGOLD          1                //底注为1

//////////////////////////////////////////////////////////////////////////

//游戏对话框
class CGameClientDlg : public CGameFrameDlg
{
private:
	//判断是否超过帐户金额
	//输入：增加钱数
	bool IsOverSelfMoney(int addInt );

	//游戏变量
protected:
	LONG							m_lTurnMaxGold;						//最大下注
	LONG							m_lTurnBasicGold;					//跟注数目
	BYTE							m_bPlayStatus[GAME_PLAYER];					//游戏状态
//	bool                            mArrayKanPai[GAME_PLAYER+1];        //是否看牌状态 ADD
	bool							m_Begin;                            //add
	LONG							AddGold;                            //add

	//辅助变量
protected:
	WORD                            MyCurrentUser;                      //add
	bool							KanPai;							    //是否看牌 ADD
	bool							m_bShowHand;						//是否梭哈
	bool							m_bMeAddGold;						//是否下注
	LONG							m_lGoldShow;						//加注筹码
	TCHAR							m_szName[GAME_PLAYER][NAME_LEN];	//玩家名字

	//控件变量
protected:
	CGameClientView					m_GameClientView;					//游戏视图
	
	//函数定义
public:
	//构造函数
	CGameClientDlg();
	//析构函数
	virtual ~CGameClientDlg();

	//常规继承
private:	
	//初始函数
	virtual bool InitGameFrame();
	//重置框架
	virtual void ResetGameFrame();
	//游戏设置
	virtual void OnGameOptionSet();
	//时间消息
	virtual bool OnTimerMessage(WORD wChairID, UINT nElapse, UINT nTimerID);
	//旁观状态
	virtual void OnLookonChanged(bool bLookonUser, const void * pBuffer, WORD wDataSize);
	//网络消息
	virtual bool OnGameMessage(WORD wSubCmdID, const void * pBuffer, WORD wDataSize);
	//游戏场景
	virtual bool OnGameSceneMessage(BYTE cbGameStatus, bool bLookonOther, const void * pBuffer, WORD wDataSize);

	//消息处理
protected:
	//游戏开始
	bool OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//用户加注
	bool OnSubAddGold(const void * pBuffer, WORD wDataSize);
	//用户放弃
	bool OnSubGiveUp(const void * pBuffer, WORD wDataSize);
	//发牌消息
	bool OnSubSendCard(const void * pBuffer, WORD wDataSize);
	//游戏结束
	bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);
	//看牌
	bool OnSubKanPai(const void * pBuffer, WORD wDataSize);        //add
	bool OnSubOver(const void * pBuffer, WORD wDataSize);        //add

	//消息映射
protected:
	//开始按钮
	LRESULT	OnStart(WPARAM wParam, LPARAM lParam);
	//加注按钮 
	LRESULT	OnAddGold(WPARAM wParam, LPARAM lParam);
	//放弃按钮
	LRESULT OnGiveUp(WPARAM wParam, LPARAM lParam);
	//跟注按钮
	LRESULT OnFollow(WPARAM wParam, LPARAM lParam);
	//梭哈按钮
	LRESULT OnShowHand(WPARAM wParam, LPARAM lParam);
	//看牌按钮
	LRESULT OnShowCard(WPARAM wParam, LPARAM lParam);             //add
	//开牌按钮
	LRESULT KaiPai(WPARAM wParam, LPARAM lParam);				  //add
	//显示跟注按钮
	LRESULT ShowFollow(WPARAM wParam, LPARAM lParam);             //add
	//是否看牌
	LRESULT SetKanPai(WPARAM wParam, LPARAM lParam)	;

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////
