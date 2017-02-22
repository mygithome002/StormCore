#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include <Custom\Logic\CustomPlayerLog.h>


class QuestLog : public PlayerScript
{

public:
	QuestLog() : PlayerScript("QuestLog") {}

		
	void OnQuestStatusChange(Player* player, uint32 questId, QuestStatus status) {
		CustomPlayerLog * PlayerLog = 0;
		
		
		if (status == QUEST_STATUS_COMPLETE) {
			std::ostringstream tt;
			tt << "Completed Quest with id " << questId;
			std::string reason = tt.str().c_str();
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
			return;
		}

		if (status == QUEST_STATUS_FAILED) {
			std::ostringstream tt;
			tt << "Failed Quest with id " << questId;
			std::string reason = tt.str().c_str();
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
			return;
		}



		if (status == QUEST_STATUS_REWARDED) {
			std::ostringstream tt;
			tt << "Rewarded Quest with id " << questId;
			std::string reason = tt.str().c_str();
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
			return;
		}

		if (status == QUEST_STATUS_INCOMPLETE) {
			std::ostringstream tt;
			tt << "Incompplete Quest with id " << questId;
			std::string reason = tt.str().c_str();
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
			return;
		}

		return;
	
	}


};


class LevelLog : public PlayerScript
{
public:
	LevelLog() : PlayerScript("LevelLog") {}

	void OnLevelChanged(Player* player, uint8 oldLevel) { 
		CustomPlayerLog * PlayerLog = 0;
		std::ostringstream tt;
		tt << "Level changed to " << oldLevel+1;
		std::string reason = tt.str().c_str();
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
		return;
	
	}

};


class CreatureKillLog : public PlayerScript {
public:
	CreatureKillLog() : PlayerScript("CreatureKillLog") {}

	void OnCreatureKill(Player* player, Creature* killed) { 
		CustomPlayerLog * PlayerLog = 0;
		std::ostringstream tt;
		tt <<"Killed: " << killed;
		std::string reason = tt.str().c_str();
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), reason);
		return;
	}

};


void AddSC_logscript()
{
	new QuestLog();
	new LevelLog();
	new CreatureKillLog();
}