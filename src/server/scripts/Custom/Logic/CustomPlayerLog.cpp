#include "CustomPlayerLog.h"

void CustomPlayerLog::insertNewPlayerLog(std::string charactername,std::string accountname, int accountid, std::string action_done)
{
	PreparedStatement * stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PLAYERLOG);
	stmt->setString(0, charactername);
	stmt->setString(1, accountname);
	stmt->setInt32(2, accountid);
	stmt->setString(3, action_done);
	CharacterDatabase.Execute(stmt);

}


