#ifndef _INCLUDE_SIGSEGV_STUB_TFPLAYER_H_
#define _INCLUDE_SIGSEGV_STUB_TFPLAYER_H_


#include "stub/baseanimating.h"
#include "prop/prop.h"


class CBaseCombatCharacter : public CBaseFlex {};

class CBasePlayer : public CBaseCombatCharacter
{
public:
	bool IsBot() const { return (vt_IsBot.Get(this))(this); }
	
private:
	static VFuncThunk<bool (*)(const CBasePlayer *)> vt_IsBot;
};

class CBaseMultiplayerPlayer : public CBasePlayer {};


enum
{
	TF_CLASS_UNDEFINED = 0,
	
	TF_CLASS_SCOUT,
	TF_CLASS_SNIPER,
	TF_CLASS_SOLDIER,
	TF_CLASS_DEMOMAN,
	TF_CLASS_MEDIC,
	TF_CLASS_HEAVYWEAPONS,
	TF_CLASS_PYRO,
	TF_CLASS_SPY,
	TF_CLASS_ENGINEER,
	
	TF_CLASS_COUNT,
};

class CTFPlayerClassShared
{
	
};

class CTFPlayerShared
{
	
};


class CTFPlayer : public CBaseMultiplayerPlayer
{
public:
	// TODO: CTFPlayerClassShared *GetPlayerClass()
	
	bool IsPlayerClass(int iClass) const { return (*ft_IsPlayerClass)(this, iClass); }
	
private:
	PROP_STR(CTFPlayer);
	
	PROP_SENDPROP(CTFPlayerShared, CTFPlayer, m_Shared);
	
	static FuncThunk<bool (*)(const CTFPlayer *, int)> ft_IsPlayerClass;
};


#endif