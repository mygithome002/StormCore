#include "Config.h"
#include <Custom/Logic/CustomCharacterSystem.h>
#include <Custom/Logic/CustomPlayerLog.h>

class ex_customxpcommands : public CommandScript
{
public:
	ex_customxpcommands() : CommandScript("ex_customxpcommands") { }

	std::vector<ChatCommand> GetCommands() const
	{

		static std::vector<ChatCommand> commandTable =
		{
			{ "xprate", SEC_ADMINISTRATOR , false, &HandleXPRate, "" },

			

		};

		return commandTable;
	}


	static bool HandleXPRate(ChatHandler* handler, const char* args) {
		if (sConfigMgr->GetBoolDefault("Custom.XP", 1)) {
			CustomXP *CustomXP = 0;
			CustomCharacterSystem* CharacterSystem = 0;
			CustomPlayerLog * PlayerLog = 0;
			Player* player = handler->GetSession()->GetPlayer();
			int guid = CharacterSystem->getGUID(player->GetSession()->GetAccountId());
			char* px = strtok((char*)args, " ");

			int playerxp = CustomXP->getCustomXPValue(guid);

			if (!px) {
				std::string accountname = "";
				accountname = CharacterSystem->getAccountName(player->GetSession()->GetAccountId());
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), guid, accountname, player->GetSession()->GetAccountId(), "Show XP Rate");
				handler->PSendSysMessage("##########################################################");
				handler->PSendSysMessage("Your XP Multiplier is currently: %u", playerxp);
				handler->PSendSysMessage("To change your Multiplier just type '.xprate 2' for a 2x Multiplier.");
				handler->PSendSysMessage("Valid Values are between 1 and 5.");
				handler->PSendSysMessage("Have fun with it, %s.", player->GetSession()->GetPlayerName());
				handler->PSendSysMessage("##########################################################");
				return true;
			}


			int32 newxpvalue = (uint32)atoi(px);
			int32 minxprate = sConfigMgr->GetIntDefault("Custom.XP.MinRate", 1);
			int32 maxxprate = sConfigMgr->GetIntDefault("Custom.XP.MaxRate", 5);
			if (newxpvalue == 0 || newxpvalue > maxxprate) {
				handler->PSendSysMessage("Your Values are invalid. Use only values between %u and %u!",minxprate, maxxprate);
				return true;
			}


			std::string charactername = CustomXP->getCustomXPExntry(guid);
			if (player->GetSession()->GetSecurity() <= 2) {
				handler->PSendSysMessage("Debug: XPValue: %s", charactername);
				handler->PSendSysMessage("Debug: GUID: %u", player->GetGUID().GetCounter());
			}


			if (charactername == "0") {
				std::string accountname = "";
				accountname = CharacterSystem->getAccountName(player->GetSession()->GetAccountId());
				PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), guid, accountname, player->GetSession()->GetAccountId(), "Change XP Rate");
				CustomXP->setCustomXPEntry(player->GetSession()->GetPlayerName(), guid, newxpvalue);
				handler->PSendSysMessage("##########################################################");
				handler->PSendSysMessage("Your XP Multiplier is set to %u", newxpvalue);
				handler->PSendSysMessage("##########################################################");
				return true;
			}

			std::string accountname = "";
			accountname = CharacterSystem->getAccountName(player->GetSession()->GetAccountId());
			PlayerLog->insertNewPlayerLog(player->GetSession()->GetPlayerName(), guid, accountname, player->GetSession()->GetAccountId(), "Change XP Rate");
			CustomXP->updateCustomXPEntry(newxpvalue, guid);
			handler->PSendSysMessage("##########################################################");
			handler->PSendSysMessage("Your XP Multiplier is set to %u", newxpvalue);
			handler->PSendSysMessage("##########################################################");
			return true;
		}

		else {
			return true;
		}
	}

	
};

void AddSC_ex_customxpcommands()
{
	new ex_customxpcommands();
}
