#pragma once
#include "Global.h"

class Soldier {
	public:
	float X, Y, Rotation;
	bool IsKilled = false, IsWounded = false;
	bool IsActive();
	void Shoot(Soldier&,Weapon);
	void MeleeAttack(Soldier&);
	void MeleeAttackNoCounter(Soldier&);
	Unit* SoldierUnit;
	Weapon IndividualWeapon;
	float ShootingSkill = 0.1;
	float MeleeSkill = 0.1;
	string Surname = "Soldier";
	SoldierRank Rank = SoldierRank_Private;
	WarSide Side = WarSide_Enemy;
	void WalkTowardsPosition(int,int,int);
	void WalkFromPosition(int,int,int);
	void GetWounded(Soldier*);
	int AmountOfActiveSoldiers;
	Soldier(Unit*, WeaponType, string, WarSide, SoldierRank, float,float);
	Soldier(Unit*, WeaponType, string, WarSide, float,float);
	Soldier(Unit*, WeaponType, WarSide, float,float);
	};
