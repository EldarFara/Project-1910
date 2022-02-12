#pragma once
#include "Global.h"

Weapon::Weapon(WeaponType L_Type) {
Type = L_Type;
	switch (L_Type)
		{
		case WeaponRF_Mosin:
		break;
		case WeaponRF_Gewehr98:
		break;
		case WeaponHMG_MaximRussian:
		RangeIncrease = 100;
		AccuracyModifier=3;
		SuspressionModifier=10;
		OperatorsAmount=2;
		RPM=5;
		break;
		case WeaponFG_76mmFieldGun:
		RPM=5;
		OperatorsAmount=5;
		HERadius = 30;
		HEPower=4;
		break;
		}
	};

Weapon::Weapon() {};
