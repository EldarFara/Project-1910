#pragma once
#include "Global.h"

void Engine::InitializeChapterTwoUnits() {
FourthBattery.Type = Unit_Artillery;
AmmoCarriage.Type = Unit_AmmoCarriage;
FourthBattery.GroupWeapons.push_back(WeaponFG_76mmFieldGun);
FourthBattery.GroupWeapons.push_back(WeaponFG_76mmFieldGun);
FourthBattery.GroupWeapons.push_back(WeaponFG_76mmFieldGun);
PionovTeam.GroupWeapons.push_back(WeaponHMG_MaximRussian);
PionovTeam.GroupWeapons.push_back(WeaponHMG_MaximRussian);
GvozdikovTeam.GroupWeapons.push_back(WeaponHMG_MaximRussian);
GvozdikovTeam.GroupWeapons.push_back(WeaponHMG_MaximRussian);
	AmmoCarriage.Soldiers.push_back(Soldier(&AmmoCarriage, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	AmmoCarriage.Soldiers.push_back(Soldier(&AmmoCarriage, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	AmmoCarriage.Soldiers.push_back(Soldier(&AmmoCarriage, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, SoldierRank_PlatoonCommander, 0.7, 0.6));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	FourthBattery.Soldiers.push_back(Soldier(&FourthBattery, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	
	FourthBattery.T_AddressFromCommander.push_back("Четвертая батарея. ");
	FourthBattery.T_AddressFromCommander.push_back("Командиру четвертой батареи. ");
	FourthBattery.T_AddressFromCommander.push_back("Командиру четвертой батареи от командира телефонной команды. ");
	FourthBattery.T_AddressToCommanderEngaged.push_back("Говорит четвертая батарея! ");
	FourthBattery.T_AddressToCommanderEngaged.push_back("Это четвертая батарея! ");
	FourthBattery.T_AddressToCommanderEngaged.push_back("Артиллерия на связи! ");
	FourthBattery.T_AddressToCommanderEngaged.push_back("Василий Иваныч, это артиллеристы! ");
	FourthBattery.T_AddressToCommanderQuiet.push_back("Василий Иваныч, это четвертая батарея. ");
	FourthBattery.T_AddressToCommanderQuiet.push_back("Четвертая батарея на связи. ");
	FourthBattery.T_AddressToCommanderQuiet.push_back("Говорит четвертая батарея. ");
	FourthBattery.T_AddressToCommanderQuiet.push_back("Артиллерия на связи. ");
	
	
	FourthBattery.IsControlledByPlayer = true;
	PionovTeam.IsControlledByPlayer = true;
	GvozdikovTeam.IsControlledByPlayer = true;
	

	
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	PionovTeam.Soldiers.push_back(Soldier(&PionovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));

	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, WeaponRF_Mosin, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));
	GvozdikovTeam.Soldiers.push_back(Soldier(&GvozdikovTeam, Weapon_None, " ", WarSide_Allies, 0.6, 0.7));

	GvozdikovTeam.T_AddressFromCommander.push_back("Гвоздиков. ");
	GvozdikovTeam.T_AddressFromCommander.push_back("Команде Гвоздикова. ");
	GvozdikovTeam.T_AddressFromCommander.push_back("Команде Гвоздикова от командира телефонной команды. ");
	GvozdikovTeam.T_AddressToCommanderEngaged.push_back("Говорит Гвоздиков! ");
	GvozdikovTeam.T_AddressToCommanderEngaged.push_back("Это Гвоздиков! ");
	GvozdikovTeam.T_AddressToCommanderEngaged.push_back("Гвоздиков на связи! ");
	GvozdikovTeam.T_AddressToCommanderQuiet.push_back("Говорит вторая пулеметная команда. ");
	GvozdikovTeam.T_AddressToCommanderQuiet.push_back("Это вторая пулеметная команда. ");
	GvozdikovTeam.T_AddressToCommanderQuiet.push_back("Говорит Гвоздиков. ");
	GvozdikovTeam.T_AddressToCommanderQuiet.push_back("Гвоздиков на связи. ");
	PionovTeam.T_AddressFromCommander.push_back("Пионов. ");
	PionovTeam.T_AddressFromCommander.push_back("Команде Пионова. ");
	PionovTeam.T_AddressFromCommander.push_back("Команде Пионова от командира телефонной команды. ");
	PionovTeam.T_AddressToCommanderEngaged.push_back("Говорит Пионов! ");
	PionovTeam.T_AddressToCommanderEngaged.push_back("Это Пионов! ");
	PionovTeam.T_AddressToCommanderEngaged.push_back("Пионов на связи! ");
	PionovTeam.T_AddressToCommanderQuiet.push_back("Говорит первая пулеметная команда. ");
	PionovTeam.T_AddressToCommanderQuiet.push_back("Это первая пулеметная команда. ");
	PionovTeam.T_AddressToCommanderQuiet.push_back("Говорит Пионов. ");
	PionovTeam.T_AddressToCommanderQuiet.push_back("Пионов на связи. ");
	AmmoCarriage.T_AddressFromCommander.push_back("Обоз. ");
	AmmoCarriage.T_AddressFromCommander.push_back("Обозу. ");
	AmmoCarriage.T_AddressFromCommander.push_back("Обозу от командира телефонной команды. ");
	AmmoCarriage.T_AddressToCommanderEngaged.push_back("Говорит обоз! ");
	AmmoCarriage.T_AddressToCommanderEngaged.push_back("Это обоз! ");
	AmmoCarriage.T_AddressToCommanderEngaged.push_back("Обоз на связи! ");
	AmmoCarriage.T_AddressToCommanderQuiet.push_back("Говорит обоз. ");
	AmmoCarriage.T_AddressToCommanderQuiet.push_back("Это обоз. ");
	AmmoCarriage.T_AddressToCommanderQuiet.push_back("Обоз на связи. ");
	}
