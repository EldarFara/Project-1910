#pragma once
#include "Global.h"

void Engine::InitializeSecondPlatoon() {
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, "Тюльпанов", WarSide_Allies, SoldierRank_PlatoonCommander, 0.7, 0.6));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	SecondPlatoon.Soldiers.push_back(Soldier(&SecondPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	
	SecondPlatoon.T_AddressFromCommander.push_back("Слушай, второй взвод. ");
	SecondPlatoon.T_AddressFromCommander.push_back("Командиру второй взвода. ");
	SecondPlatoon.T_AddressFromCommander.push_back("Командиру второго взвода от командира телефонной команды. ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Говорит второй! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Это второй взвод! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Тюльпанов на связи! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Второй взвод говорит! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Тюльпанов у аппарата! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Это Тюльпанов! ");
	SecondPlatoon.T_AddressToCommanderEngaged.push_back("Капитан, это Тюльпанов! ");
	SecondPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды от командира второго взвода. ");SecondPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды от второго взвода. ");
	SecondPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды, это командир второго взвода. ");
	SecondPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды, это второй взвод. ");
	
	SecondPlatoon.IsControlledByPlayer = true;
	}
