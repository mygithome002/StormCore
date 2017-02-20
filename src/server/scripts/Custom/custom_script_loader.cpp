/*
 * Copyright (C) 2014-2017 StormCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is where scripts' loading functions should be declared:


// The name of this function should match:
// void Add${NameOfDirectory}Scripts()

//Custom NPC
void AddSC_helpscripts();

//CUstom Reportcommands
void AddSC_ex_reportcommands();

//Custom XP Commands
void AddSC_ex_customxpcommands();
//Custom commands
void AddSC_helpcommands();

//Custom XP Script
void AddSC_XPScripts();

void AddCustomScripts()
{
	AddSC_helpscripts();

	AddSC_ex_reportcommands();

	AddSC_ex_customxpcommands();

	AddSC_XPScripts();

	AddSC_helpcommands();

}
