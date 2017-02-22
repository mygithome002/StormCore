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

#define MOPMAP = 870
#define WODMAP = 1116
#define LEGIONMAP = 1220

class graveyard : public PlayerScript
{

public:
	graveyard() : PlayerScript("graveyard") {}

	void OnPlayerKilledByCreature(Creature* /*killer*/, Player* player) { 
		
		CustomPlayerLog * PlayerLog = 0;
		player->SaveRecallPosition();
		player->ResurrectPlayer(50.0, false);

	
		//MOP
		if (player->GetMapId() == 870) {
			switch (player->GetTeam())
			{
			case ALLIANCE:
				player->TeleportTo(870,924.90f,328.48f,506.28f,3.76f);
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Resurrect Panda Ally!");
				break;

			case HORDE:
				player->TeleportTo(870, 1576.48f, 889.80f, 473.60f, 0.56f);
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Resurrect Panda Horde!");
				break;
			}
		}
	
		//WOD
		if (player->GetMapId() == 1116) {
			switch (player->GetTeam())
			{
			case ALLIANCE:
				player->TeleportTo(1116, 3678.16f, -3841.15f, 44.92f, 3.91f);   
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Resurrect WOD Ally!");
				break;

			case HORDE:
				player->TeleportTo(1116, 5291.82f,-4009.21f ,14.49f, 3.05f);
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Resurrect WOD Horde!");
				break;
			}
		}

		//LEGION
		if (player->GetMapId() == 1220) {
			player->TeleportTo(1220, -828.9f, 4371.95f, 739.25f, 1.88f);
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Resurrect Legion!");
			return;
		}

	}
	

};





void AddSC_helpscripts()
{
	new graveyard();
}