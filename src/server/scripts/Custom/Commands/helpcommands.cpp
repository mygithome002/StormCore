#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "Common.h"
#include "Player.h"
#include "WorldSession.h"
#include "Language.h"
#include "Log.h"
#include "SpellAuras.h"
#include "World.h"
#include "Transport.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "SocialMgr.h"
#include "CreatureGroups.h"
#include "Language.h"
#include "TargetedMovementGenerator.h"                      
#include "CreatureAI.h"
#include "Player.h"
#include "Pet.h"
#include <Custom/Logic/CustomPlayerLog.h>
#include <Custom/Logic/CustomCharacterSystem.h>

class helpcommands : public CommandScript
{
public:
	helpcommands() : CommandScript("helpcommands") { }

	std::vector<ChatCommand> GetCommands()  const override
	{

		static std::vector<ChatCommand> coupontable =
		{

			{ "skipcata", SEC_PLAYER, false, &HandleHelpSkipCataCommand, "" },
			{ "skipmop", SEC_PLAYER, false, &HandleHelpSkipMopCommand, "" },
			{ "skipwod", SEC_PLAYER, false, &HandleHelpSkipWodCommand, "" },
			{ "skiplegion", SEC_PLAYER, false, &HandleHelpSkipLegionCommand, "" },
			{ "startwod", SEC_PLAYER, false, &HandleHelpStartWodCommand, "" },

		};

		static std::vector<ChatCommand> commandTable =
		{
			{ "ex", SEC_ADMINISTRATOR , false, NULL, "" , coupontable },

		};

		return commandTable;
	}


	static bool HandleHelpStartWodCommand(ChatHandler* handler, const char* args)
	{

		Player * player = handler->GetSession()->GetPlayer();
		CustomPlayerLog * PlayerLog = 0;
		switch (player->GetTeam())
		{
		case ALLIANCE:
			player->TeleportTo(1116,1848.46f,221.52f,76.36f,4.24f);
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Alliance Garrison used!");
			break;

		case HORDE:
			player->TeleportTo(1116, 5584.14f,4599.51f,138.14f,4.61f);
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), player->GetGUID().GetCounter(), player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Horde Garrison used!");
			break;
		}
		return true;
	};


	
	static bool HandleHelpSkipCataCommand(ChatHandler* handler, const char* args)
	{
		CustomPlayerLog * PlayerLog = 0;
		Player* player = handler->GetSession()->GetPlayer();
		CustomCharacterSystem * CharacterSystem = 0;
		int guid = CharacterSystem->getGUID(player->GetSession()->GetAccountId());


		if (player->getLevel() < 80 || player->getLevel() > 84) {
			handler->PSendSysMessage("#####################################");
			handler->PSendSysMessage("The Command can only be executed between Level 80 and 84");
			handler->PSendSysMessage("#####################################");
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Cata Command used failed. Level problem!");
			return true;
		}


		player->SetLevel(85);
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Cata Command used successful!");
		return true;
	};

	static bool HandleHelpSkipMopCommand(ChatHandler* handler, const char* args)
	{
		CustomPlayerLog * PlayerLog = 0;
		Player* player = handler->GetSession()->GetPlayer();
		CustomCharacterSystem * CharacterSystem = 0;
		int guid = CharacterSystem->getGUID(player->GetSession()->GetAccountId());
		if (player->getLevel() < 85 || player->getLevel() > 89) {
			handler->PSendSysMessage("#####################################");
			handler->PSendSysMessage("The Command can only be executed between Level 85 and 89");
			handler->PSendSysMessage("#####################################");
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "MOP Command used failed. Level problem!");
			return true;
		}


		player->SetLevel(90);
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "MOP Command used successful!");
		return true;
	};


	static bool HandleHelpSkipWodCommand(ChatHandler* handler, const char* args)
	{
		CustomPlayerLog * PlayerLog = 0;
		Player* player = handler->GetSession()->GetPlayer();
		CustomCharacterSystem * CharacterSystem = 0;
		int guid = CharacterSystem->getGUID(player->GetSession()->GetAccountId());
		if (player->getLevel() < 90 || player->getLevel() > 99) {
			handler->PSendSysMessage("#####################################");
			handler->PSendSysMessage("The Command can only be executed between Level 90 and 99");
			handler->PSendSysMessage("#####################################");
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "WOD Command used failed. Level problem!");
			return true;
		}


		player->SetLevel(100);
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "WOD Command used successful!");
		return true;
	};


	static bool HandleHelpSkipLegionCommand(ChatHandler* handler, const char* args)
	{
		CustomPlayerLog * PlayerLog = 0;
		Player* player = handler->GetSession()->GetPlayer();
		CustomCharacterSystem * CharacterSystem = 0;
		int guid = CharacterSystem->getGUID(player->GetSession()->GetAccountId());
		if (player->getLevel() < 100 || player->getLevel() > 109) {
			handler->PSendSysMessage("#####################################");
			handler->PSendSysMessage("The Command can only be executed between Level 100 and 109");
			handler->PSendSysMessage("#####################################");
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Legion Command used failed. Level problem!");
			return true;
		}


		player->SetLevel(110);
		PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(),guid, player->GetSession()->GetAccountName(), player->GetSession()->GetAccountId(), "Legion Command used successful!");
		return true;
	};


};


void AddSC_helpcommands()
{
	new helpcommands();
}