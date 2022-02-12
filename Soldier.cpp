#pragma once
#include "Global.h"

Soldier::Soldier(Unit* L_Unit, WeaponType L_Weapon, string L_Surname, WarSide L_Side, SoldierRank L_Rank, float L_ShootingSkill, float L_MeleeSkill) {
	IndividualWeapon = Weapon(L_Weapon); Rank = L_Rank;
	Surname = L_Surname; Side = L_Side;
	SoldierUnit = L_Unit;
	ShootingSkill = L_ShootingSkill;
	MeleeSkill = L_MeleeSkill;
	}
Soldier::Soldier(Unit* L_Unit, WeaponType L_Weapon, string L_Surname, WarSide L_Side, float L_ShootingSkill, float L_MeleeSkill) {
	IndividualWeapon = Weapon(L_Weapon);
	Surname = L_Surname; Side = L_Side;
	SoldierUnit = L_Unit;
	ShootingSkill = L_ShootingSkill;
	MeleeSkill = L_MeleeSkill;
	}

Soldier::Soldier(Unit* L_Unit, WeaponType L_Weapon, WarSide L_Side, float L_ShootingSkill, float L_MeleeSkill) {
	IndividualWeapon = Weapon(L_Weapon); Side = L_Side;
	SoldierUnit = L_Unit;
	ShootingSkill = L_ShootingSkill;
	MeleeSkill = L_MeleeSkill;
	}
	
void Soldier::WalkTowardsPosition(int L_X, int L_Y, int L_Speed) {
	if (&SoldierUnit->Soldiers[0] == this) Rotation = Engine::ABP(X, Y, L_X, L_Y);
	L_X = L_X + X - SoldierUnit->Soldiers[0].X;
	L_Y = L_Y + Y - SoldierUnit->Soldiers[0].Y;
	float L_Distance = sqrt((X-L_X)*(X-L_X) + (Y-L_Y)*(Y-L_Y));
	X = X + ((L_X-X) / L_Distance) * Random::get(L_Speed-30,L_Speed+30)/10;
	Y = Y + ((L_Y-Y) / L_Distance) * Random::get(L_Speed-30,L_Speed+30)/10;
	}
	
void Soldier::WalkFromPosition(int L_X, int L_Y, int L_Speed) {
	if (&SoldierUnit->Soldiers[0] == this) Rotation = Engine::ABP(L_X, L_Y, X, Y);
	L_X = L_X + X - SoldierUnit->Soldiers[0].X;
	L_Y = L_Y + Y - SoldierUnit->Soldiers[0].Y;
	float L_Distance = sqrt((X-L_X)*(X-L_X) + (Y-L_Y)*(Y-L_Y));
	X = X - ((L_X-X) / L_Distance) * Random::get(L_Speed-30,L_Speed+30)/10;
	Y = Y - ((L_Y-Y) / L_Distance) * Random::get(L_Speed-30,L_Speed+30)/10;
	}

bool Soldier::IsActive() {
	if (!IsWounded && !IsKilled) return true; else return false;
	}

void Soldier::Shoot(Soldier& L_TargetSoldier, Weapon L_Weapon) {
if(L_Weapon.Type != Weapon_None)
{
float L_Distance = Engine::DBP(X, Y, L_TargetSoldier.X,L_TargetSoldier.Y);
L_TargetSoldier.SoldierUnit->Suspression += L_Weapon.SuspressionModifier*10/sqrt(L_Distance);
if (L_Distance < 20) MeleeAttack(L_TargetSoldier); else {
if(SoldierUnit->Ammo>0) { if (Random::get(0,2000) < (20000*L_Weapon.AccuracyModifier*L_TargetSoldier.SoldierUnit->Cover*sqrt(L_TargetSoldier.SoldierUnit->Visibility)*ShootingSkill*((SoldierUnit->Height-L_TargetSoldier.SoldierUnit->Height)/15+1))/(clamp(int(L_Distance-L_Weapon.RangeIncrease),20,2000)*((SoldierUnit->OldSuspression/50)+1)*((int(SoldierUnit->IsMoving)+1.5)/1.5))) {
	if (SoldierUnit->ICBP) {
	cout<<"'"<<Unit::GetRandomString(SoldierUnit->T_AddressToCommanderEngaged)<<Unit::GetRandomString(SoldierUnit->T_OneEnemyWasShot)<<"'\n";
	}
	L_TargetSoldier.GetWounded(this);
}
SoldierUnit->Ammo -= 0.1; }
}
}
}

void Soldier::MeleeAttack(Soldier& L_TargetSoldier) {
if (MeleeSkill*75+Random::get(1,99) > 100) {
	if (SoldierUnit->ICBP) {
	cout<<"'"<<Unit::GetRandomString(SoldierUnit->T_AddressToCommanderEngaged)<<Unit::GetRandomString(SoldierUnit->T_OneEnemyWasStabbed)<<"'\n";
	} else L_TargetSoldier.MeleeAttackNoCounter(*this);
	L_TargetSoldier.GetWounded(this);
}
}

void Soldier::MeleeAttackNoCounter(Soldier& L_TargetSoldier) {
if (MeleeSkill*75+Random::get(1,99) > 100) {
	if (SoldierUnit->ICBP) {
	cout<<"'"<<Unit::GetRandomString(SoldierUnit->T_AddressToCommanderEngaged)<<Unit::GetRandomString(SoldierUnit->T_OneEnemyWasStabbed)<<"'\n";
	};
	L_TargetSoldier.GetWounded(this);
}
}

void Soldier::GetWounded(Soldier* Killer) {
IsWounded = true;
SoldierUnit->AmountOfActiveSoldiers = SoldierUnit->AmountOfActiveSoldiers - 1;
SoldierUnit->AmountOfWoundedSoldiers = SoldierUnit->AmountOfWoundedSoldiers + 1;
if (SoldierUnit->ICBP) {
	cout<<"'"<<Unit::GetRandomString(SoldierUnit->T_AddressToCommanderEngaged)<<Unit::GetRandomString(SoldierUnit->T_OneWasWounded)<<"'\n";
	}
if (SoldierUnit->AmountOfActiveSoldiers == 0) {
	int L_Index = Engine::GVEU(SoldierUnit, Engine::ActiveUnits);
	if (L_Index != -1) Engine::ActiveUnits.erase(Engine::ActiveUnits.begin()+L_Index);
	if (Killer!= nullptr && Killer->SoldierUnit->ICBP) {
	cout<<"'"<<Unit::GetRandomString(Killer->SoldierUnit->T_AddressToCommanderEngaged)<<Unit::GetRandomString(Killer->SoldierUnit->T_EnemyUnitFragged)<<"'\n";
	}
	}
}
