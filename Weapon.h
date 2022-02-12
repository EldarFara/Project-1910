#pragma once
#include "Global.h"

class Weapon {
	public:
	WeaponType Type = Weapon_None;
	float AccuracyModifier = 1;
	float SuspressionModifier = 1;
	float RangeIncrease = 1;
	float HERadius=1;
	int RPM = 1, HEPower = 1;
	int OperatorsAmount = 0;
	Weapon();
	Weapon(WeaponType);
	};
