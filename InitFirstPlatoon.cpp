#pragma once
#include "Global.h"

void Engine::InitializeFirstPlatoon() {
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Ландышев", WarSide_Allies, SoldierRank_PlatoonCommander, 0.7, 0.6));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Стеблев", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Смирнов", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Котов", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Домашев", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Ясенев", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Меликов", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Курпатов", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Кузьмин", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Карчагин", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, "Астахов", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	FirstPlatoon.Soldiers.push_back(Soldier(&FirstPlatoon, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	
	FirstPlatoon.T_AddressFromCommander.push_back("Слушай, первый взвод. ");
	FirstPlatoon.T_AddressFromCommander.push_back("Командиру первого взвода. ");
	FirstPlatoon.T_AddressFromCommander.push_back("Командиру первого взвода от командира телефонной команды. ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Говорит первый взвод! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Это первый взвод! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Говорит Ландышев! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Командиру от первого взвода! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Первый взвод у аппарата! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Это Ландышев! ");
	FirstPlatoon.T_AddressToCommanderEngaged.push_back("Командир, это Ландышев! ");
	FirstPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды от командира первого взвода. ");FirstPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды от первого взвода. ");
	FirstPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды, это командир первого взвода. ");
	FirstPlatoon.T_AddressToCommanderQuiet.push_back("Командиру телефонной команды, это первый взвод. ");
	
	
	FirstPlatoon.IsControlledByPlayer = true;
	}
