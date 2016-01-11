#ifndef _INCLUDE_SIGSEGV_RE_NEXTBOT_H_
#define _INCLUDE_SIGSEGV_RE_NEXTBOT_H_


#if defined _WIN32
//#error NextBot classes have not been checked against the VC++ build!
#endif


#include "stub/stub.h"
#include "util/util.h"


class INextBot;
class Path;
class PathFollower;
class animevent_t;
class AI_Response;
class CBaseCombatWeapon;
class INextBotEntityFilter;
class INextBotReply;
class CNavLadder;
class NextBotCombatCharacter;
template<class T> class Action;
#define CUtlVectorAutoPurge CUtlVector

// TODO: NextBot/Path/Path.h
// TODO: NextBot/Path/PathFollower.h
// TODO: NextBot/Path/ChasePath.h
#include "mvm-reversed/server/NextBot/NextBotKnownEntity.h"
#include "mvm-reversed/server/NextBot/NextBotEventResponderInterface.h"
#include "mvm-reversed/server/NextBot/NextBotContextualQueryInterface.h"
#include "mvm-reversed/server/NextBot/NextBotComponentInterface.h"
#include "mvm-reversed/server/NextBot/NextBotIntentionInterface.h"
#include "mvm-reversed/server/NextBot/NextBotBodyInterface.h"
#include "mvm-reversed/server/NextBot/NextBotLocomotionInterface.h"
#include "mvm-reversed/server/NextBot/NextBotVisionInterface.h"
#include "mvm-reversed/server/NextBot/NextBotInterface.h"
#include "mvm-reversed/server/NextBot/NextBotBehavior.h"
// TODO: NextBot/Player/PlayerBody.h
// TODO: NextBot/Player/PlayerLocomotion.h


SIZE_CHECK(CKnownEntity,               0x30); // 0x2d
SIZE_CHECK(INextBotEventResponder,     0x04);
SIZE_CHECK(IContextualQuery,           0x04);
SIZE_CHECK(INextBotComponent,          0x14);
SIZE_CHECK(IIntention,                 0x18);
SIZE_CHECK(IBody,                      0x14);
SIZE_CHECK(ILocomotion,                0x58);
SIZE_CHECK(IVision,                    0xc4);
SIZE_CHECK(INextBot,                   0x60);
SIZE_CHECK(Behavior<CTFBot>,           0x50);
SIZE_CHECK(Action<CTFBot>,             0x34); // 0x32
SIZE_CHECK(ActionResult<CTFBot>,       0x0c);
SIZE_CHECK(EventDesiredResult<CTFBot>, 0x10);


/* from NextBotBehavior.cpp */
template<class T> inline Action<T>::Action() :
	m_ActionParent(nullptr), m_ActionChild(nullptr),
	m_ActionWeSuspended(nullptr), m_ActionSuspendedUs(nullptr),
	m_Actor(nullptr)
{
	this->m_Behavior = nullptr;
	this->m_bStarted = false;
	this->m_bSuspended = false;
	
	memset((void *)&this->m_Result, 0x00, 0x10);
}


#endif
