#pragma once
#include "Global.h"

void Unit::PerformIterationActions() {
FindOtherUnits();
EnergyReportTimer--;
Energy = clamp(float(Energy+1), 1.f, 100.f);
if(ICBP && Energy < 40 && EnergyReportTimer < 1)
{ EnergyReportTimer = 30;
	cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_SoldiersAreTired)<<".'\n"; }
Morale -= OldSuspression/10;
Morale = clamp(float(Morale+1), 1.f, 100.f);
	for(int i = 0; i < Orders.size(); i++)
	{
		switch(Orders[i].Type)
		{
			case OrderType_Movement:
		if (OldSuspression < 80) {
			IsMoving = true;
			if (!Orders[i].IsReceived) {
				Orders[i].IsReceived = true;
				if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_ReceivedMovementOrder)<<int(Orders[i].Parameter1/10)<<"|"<<int(Orders[i].Parameter2/10)<<".'\n";
				}
		if (Engine::DBP(Soldiers[0].X, Soldiers[0].Y, Orders[i].Parameter1,  Orders[i].Parameter2) <20) {
	if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_SucceededMovementOrder)<<int(Orders[i].Parameter1/10)<<"|"<<int(Orders[i].Parameter2/10)<<".'\n";
		Orders.erase(Orders.begin()+i); i--;
		IsMoving = false;
			} else {
			for(int j = 0; j < Soldiers.size() ; j++) if (!Soldiers[j].IsKilled) Soldiers[j].WalkTowardsPosition(Orders[i].Parameter1, Orders[i].Parameter2, SpeedModifier*(350/(OldSuspression/5+1))*clamp(Energy/50,float(0.75),1.f));
			Energy -= 2;
				}
	} else
	 {
	 if (ICBP && !Orders[i].IsReceived) cout<<"'"<<GetRandomString(T_AddressToCommanderEngaged)<<GetRandomString(T_CannotMovePinnedDown)<<"'\n";
		Orders.erase(Orders.begin()+i); i--;
		IsMoving = false;
	 }
			break;
			case OrderType_PositionReport:
				if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_PositionReport_P1)<<GetRandomString(T_PositionReport_P2)<<int((Soldiers[0].X+5) / 10)<<"|"<<int((Soldiers[0].Y+5) / 10)<<".'\n";
				Orders.erase(Orders.begin()+i);
				i--;
			break;
			case OrderType_Contacts:
try
{
if (ICBP) {cout<<"'";
if(UnitsInSight.size() == 0)
{
	cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_ContactReportNoSeenUnits)<<"'";
} else {
for(int j = 0; j < UnitsInSight.size() ; j++)
	{
vector <string> L_T_RevealUnit_P4_Direction={""},L_T_RevealUnit_P5_Direction{""};
if (UnitsInSight[j]->IsMoving) { 
L_T_RevealUnit_P4_Direction =T_RevealUnit_P4_Direction;
switch(int((UnitsInSight[j]->Soldiers[0].Rotation+22)/45)) {
case 9: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
case 8: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
case 7: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_8_Direction; break;
case 6: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_7_Direction; break;
case 5: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_6_Direction; break;
case 4: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_5_Direction; break;
case 3: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_4_Direction; break;
case 2: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_3_Direction; break;
case 1: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_2_Direction; break;
case 0: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
	} };
if (j>0) cout<<"Еще "; else cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet);
	cout<<GetRandomString(T_ContactReport)<<int(UnitsInSight[j]->Soldiers[0].X / 10)<<"|"<<int(UnitsInSight[j]->Soldiers[0].Y / 10)<<GetRandomString(T_RevealUnit_P6_Distance)<<int(Engine::DBP(Soldiers[0].X, Soldiers[0].Y, UnitsInSight[j]->Soldiers[0].X,UnitsInSight[j]->Soldiers[0].Y))<<GetRandomString(T_RevealUnit_P7_Distance)<<GetRandomString(T_RevealUnit_P2_Infantry)<<GetRandomString(T_RevealUnit_P3_Amount)<<UnitsInSight[j]->AmountOfActiveSoldiers<<" человек. "<<GetRandomString(L_T_RevealUnit_P4_Direction)<<GetRandomString(L_T_RevealUnit_P5_Direction);
	}
cout<<"'";
} }
		Orders.erase(Orders.begin()+i); i--;
} catch(...) {
cout<<"ОШИБКА";
};
			break;
			case OrderType_Attack:
if(int(Orders[i].Parameter1) == -1)
{
if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_NoEnemiesToAttack)<<".'\n";
	Orders.erase(Orders.begin()+i); i--;
} else {
	vector <string> L_T_ReceivedAttackOrder;
	if (int(Orders[i].Parameter1) == 1) {
	IsMoving = false;
	L_T_ReceivedAttackOrder = T_ReceivedOpenFireOrder; } else {
	Energy -= 2;
	for(int j = 0; j < Soldiers.size() ; j++) if (!Soldiers[j].IsKilled) Soldiers[j].WalkTowardsPosition(Orders[i].UnitPointer1->Soldiers[0].X, Orders[i].UnitPointer1->Soldiers[0].Y, SpeedModifier*(400/(OldSuspression/5+1))*clamp(Energy/50,float(0.75),1.f));
		L_T_ReceivedAttackOrder = T_ReceivedChargeOrder;
	}
	if (!Orders[i].IsReceived) {
		Orders[i].IsReceived = true;
		if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(L_T_ReceivedAttackOrder)<<int(Orders[i].UnitPointer1->Soldiers[0].X/10)<<"|"<<int(Orders[i].UnitPointer1->Soldiers[0].Y/10)<<".'\n";
				}
	int L_Index1 = Engine::GVEU(Orders[i].UnitPointer1, UnitsInSight);
	int L_Index2 = Engine::GVEU(Orders[i].UnitPointer1, Engine::ActiveUnits);
if (L_Index1 != -1 && L_Index2 != -1) {
int L_Index = Engine::GVEU(Orders[i].UnitPointer1, EngagedUnits);
if (L_Index == -1) EngagedUnits.push_back(Orders[i].UnitPointer1);
L_Index = Engine::GVEU(this, Orders[i].UnitPointer1->EngagedUnits);
L_Index1 = Engine::GVEU(this, Orders[i].UnitPointer1->UnitsInSight);
if (L_Index == -1 && L_Index1 != -1) Orders[i].UnitPointer1->EngagedUnits.push_back(this);
} else { Orders.erase(Orders.begin()+i); i--; }
}
			break;
			case OrderType_Retreat:
	if (EngagedUnits.size() != 0)
	{
	IsMoving = true;
	Energy -= 2;
	for(int j = 0; j < Soldiers.size() ; j++) if (!Soldiers[j].IsKilled) Soldiers[j].WalkFromPosition(EngagedUnits[0]->Soldiers[0].X, EngagedUnits[0]->Soldiers[0].Y, SpeedModifier*(500/(OldSuspression/30+1))*clamp(Energy/50,float(0.75),1.f));
	if (!Orders[i].IsReceived) {
		Orders[i].IsReceived = true;
		if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_RetreatOrderReceived)<<"'\n";
			}
	} else {
	IsMoving = false;
	Orders.erase(Orders.begin()+i); i--;
		}
			break;
			case OrderType_Status:
	{vector <string> L_T_Status_P6 = {"ждем приказов. "},L_T_Status_P8,L_T_Status_P9,L_T_Status_P11,L_T_Status_P12,L_T_Status_P13,L_T_Status_P15,L_T_Status_P16={""},L_T_Status_P17={""},L_T_Status_P18={""};
	string L_T_Status_P16_Number="";
	for(int j = 0; j < Orders.size() ; j++) {switch(Orders[j].Type) {
			case OrderType_Movement:
	L_T_Status_P6 = T_Status_P6_1; break;
			case OrderType_Attack:
	if (Orders[j].Parameter1 == 1) L_T_Status_P6 = T_Status_P6_2; else L_T_Status_P6 = T_Status_P6_3; break;
			case OrderType_Retreat:
	L_T_Status_P6 = T_Status_P6_4; break;
	} };
if(OldSuspression>1) 
	switch(int(OldSuspression/15)) {
case 0: L_T_Status_P18 = T_Status_P18_2; break;
case 1: L_T_Status_P18 = T_Status_P18_3; break;
case 2: L_T_Status_P18 = T_Status_P18_4; break;
default: L_T_Status_P18 = T_Status_P18_5; break;
	};
	switch(int(Visibility*5)) {
case 0: L_T_Status_P8 = T_Status_P8_1; break;
case 1: L_T_Status_P8 = T_Status_P8_2; break;
case 2: L_T_Status_P8 = T_Status_P8_3; break;
case 3: L_T_Status_P8 = T_Status_P8_4; break;
case 4: L_T_Status_P8 = T_Status_P8_5; break;
case 5: L_T_Status_P8 = T_Status_P8_5; break;
	};
	switch(int(Cover*5)) {
case 0: L_T_Status_P9 = T_Status_P9_1; break;
case 1: L_T_Status_P9 = T_Status_P9_2; break;
case 2: L_T_Status_P9 = T_Status_P9_3; break;
case 3: L_T_Status_P9 = T_Status_P9_4; break;
case 4: L_T_Status_P9 = T_Status_P9_5; break;
case 5: L_T_Status_P9 = T_Status_P9_5; break;
	};
	switch(int(Morale/25)) {
case 4: L_T_Status_P11 = T_Status_P11_1; break;
case 3: L_T_Status_P11 = T_Status_P11_2; break;
case 2: L_T_Status_P11 = T_Status_P11_3; break;
case 1: L_T_Status_P11 = T_Status_P11_4; break;
case 0: L_T_Status_P11 = T_Status_P11_4; break;
	};
	switch(int(Energy/20)) {
case 5: L_T_Status_P13 = T_Status_P13_1; break;
case 4: L_T_Status_P13 = T_Status_P13_1; break;
case 3: L_T_Status_P13 = T_Status_P13_2; break;
case 2: L_T_Status_P13 = T_Status_P13_3; break;
case 1: L_T_Status_P13 = T_Status_P13_4; break;
case 0: L_T_Status_P13 = T_Status_P13_5; break;
	};
	switch(int((Ammo/MaxAmmo)*100/12.5)) {
case 8: L_T_Status_P15 = T_Status_P15_1; break;
case 7: L_T_Status_P15 = T_Status_P15_1; break;
case 6: L_T_Status_P15 = T_Status_P15_2; break;
case 5: L_T_Status_P15 = T_Status_P15_3; break;
case 4: L_T_Status_P15 = T_Status_P15_4; break;
case 3: L_T_Status_P15 = T_Status_P15_5; break;
case 2: L_T_Status_P15 = T_Status_P15_6; break;
case 1: L_T_Status_P15 = T_Status_P15_7; break;
case 0: L_T_Status_P15 = T_Status_P15_8; break;
	};
	if (Height>5) {L_T_Status_P16=T_Status_P16; L_T_Status_P17=T_Status_P17;L_T_Status_P16_Number=to_string(int(Height));}
	if ((Morale-Energy)>31 || (Morale-Energy)<-31) L_T_Status_P12 = T_Status_P12_1; else L_T_Status_P12 = T_Status_P12_2;
	if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_Status_P1)<<AmountOfActiveSoldiers<<GetRandomString(T_Status_P2)<<AmountOfWoundedSoldiers<<GetRandomString(T_Status_P3)<<AmountOfKilledSoldiers<<GetRandomString(T_Status_P4)<<GetRandomString(T_Status_P5)<<GetRandomString(L_T_Status_P6)<<GetRandomString(T_Status_P7)<<GetRandomString(L_T_Status_P8)<<GetRandomString(L_T_Status_P9)<<GetRandomString(T_Status_P10)<<GetRandomString(L_T_Status_P11)<<GetRandomString(L_T_Status_P12)<<GetRandomString(L_T_Status_P13)<<GetRandomString(T_Status_P14)<<GetRandomString(L_T_Status_P15)<<GetRandomString(L_T_Status_P16)<<L_T_Status_P16_Number<<GetRandomString(L_T_Status_P17)<<GetRandomString(L_T_Status_P18)<<"'\n";
	Orders.erase(Orders.begin()+i); i--; };
			break;
			case OrderType_ArtilleryBarrage:
if (!Orders[i].IsReceived) {
Orders[i].IsReceived = true;
IsMoving = false;
if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_ArtilleryBarrageOrderReceived)<<"'\n";
}
if (IsMoving == true) { Orders.erase(Orders.begin()+i); i--; };
int GroupWeaponsOperators=AmountOfActiveSoldiers,L_EnemySoldiersHit=0;
Soldier* SoldierThatWasHit = nullptr;
int L_Distance = Engine::DBP(Orders[i].Parameter1,Orders[i].Parameter2,Soldiers[0].X,Soldiers[0].Y);
for(int j = 0; j < GroupWeapons.size() ; j++) {
if (GroupWeaponsOperators>=GroupWeapons[j].OperatorsAmount) {
GroupWeaponsOperators-=GroupWeapons[j].OperatorsAmount;
	for(int k = 0; k < GroupWeapons[j].RPM ; k++) {
if (Orders[i].Parameter3>0) { Orders[i].Parameter3--; 
if (Ammo>0) { cout<<Ammo<<endl;
Ammo--;
SoldierThatWasHit = Engine::Explosion(Orders[i].Parameter1+Random::get(((-1*L_Distance)/10-60),(L_Distance/10+60)),Orders[i].Parameter2+Random::get(((-1*L_Distance)/10-60),(L_Distance/10+60)),GroupWeapons[j].HERadius,GroupWeapons[j].HEPower);
if (SoldierThatWasHit != nullptr) if (Soldiers[0].Side==SoldierThatWasHit->Side) { if (ICBP) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_AllyWasHitByArtyShell)<<"'\n"; } else L_EnemySoldiersHit++;
				}
			}
		}
	}
}
if(ICBP && L_EnemySoldiersHit>0) if (L_EnemySoldiersHit>1) cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_EnemyWasHitByArtyShellMultiple_P1)<<L_EnemySoldiersHit<<GetRandomString(T_EnemyWasHitByArtyShellMultiple_P2)<<"'\n"; else cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_EnemyWasHitByArtyShell)<<"'\n"; 
if (Orders[i].Parameter3==0) { Orders.erase(Orders.begin()+i); i--; 
cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_ArtilleryBarrageOrderSucceed)<<"'\n";
	} else if (Ammo==0) { Orders.erase(Orders.begin()+i); i--; 
cout<<"'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_ArtilleryBarrageOrderInterruptedNoAmmo)<<"'\n";
	};
			break;
		}
	};
EngageEnemyUnits();
}
string Unit::GetRandomString(vector <string> L_Vector) {
	if (L_Vector.size() == 0) return "";
	int Index = Random::get(0, int(L_Vector.size())-1);
	return L_Vector[Index];
	}

void Unit::FindOtherUnits() {
	vector <Unit*> L_RevealedUnits;
	for(int i = 0; i < Engine::ActiveUnits.size() ; i++)
	{
	bool AlreadyWasRevealed = false;
	float L_Distance;
		if (this!=Engine::ActiveUnits[i]) {
if (Engine::GVEU(Engine::ActiveUnits[i], UnitsInSight) != -1)AlreadyWasRevealed = true;
	L_Distance = Engine::DBP(Soldiers[0].X,Soldiers[0].Y,Engine::ActiveUnits[i]->Soldiers[0].X,Engine::ActiveUnits[i]->Soldiers[0].Y);
	if ((L_Distance/(Engine::ActiveUnits[i]->Visibility*clamp(double(sqrt(Engine::ActiveUnits[i]->AmountOfActiveSoldiers))/double(5), 0.75, 1.1))*((int(AlreadyWasRevealed)+2)/2)*((int(Engine::ActiveUnits[i]->IsMoving)+2)/2))*((int(Engine::AreUnitsEngaged(this,Engine::ActiveUnits[i]))+2)/2)/((Height/20)+1) < 320) {
		L_RevealedUnits.push_back(Engine::ActiveUnits[i]);

		if (ICBP && !AlreadyWasRevealed) {
	string L_T_RevealUnit_P1;
vector <string> L_T_RevealUnit_P4_Direction={""},L_T_RevealUnit_P5_Direction{""};
	if(Engine::ActiveUnits[i]->IsMoving) {L_T_RevealUnit_P1 = GetRandomString(T_RevealUnit_P1_Movement);
L_T_RevealUnit_P4_Direction =T_RevealUnit_P4_Direction;
switch(int((Engine::ActiveUnits[i]->Soldiers[0].Rotation+22)/45)) {
case 9: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
case 8: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
case 7: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_8_Direction; break;
case 6: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_7_Direction; break;
case 5: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_6_Direction; break;
case 4: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_5_Direction; break;
case 3: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_4_Direction; break;
case 2: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_3_Direction; break;
case 1: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_2_Direction; break;
case 0: L_T_RevealUnit_P5_Direction = T_RevealUnit_P5_1_Direction; break;
	};
} else L_T_RevealUnit_P1 = GetRandomString(T_RevealUnit_P1_Idle);
	cout << "'"<<GetRandomString(T_AddressToCommanderQuiet)<<L_T_RevealUnit_P1<<int(Engine::ActiveUnits[i]->Soldiers[0].X / 10)<<"|"<<int(Engine::ActiveUnits[i]->Soldiers[0].Y / 10)<<GetRandomString(T_RevealUnit_P6_Distance)<<int(Engine::DBP(Soldiers[0].X, Soldiers[0].Y, Engine::ActiveUnits[i]->Soldiers[0].X,Engine::ActiveUnits[i]->Soldiers[0].Y))<<GetRandomString(T_RevealUnit_P7_Distance)<<GetRandomString(T_RevealUnit_P2_Infantry)<<GetRandomString(T_RevealUnit_P3_Amount)<<Engine::ActiveUnits[i]->Soldiers.size()<<" человек. "<<GetRandomString(L_T_RevealUnit_P4_Direction)<<GetRandomString(L_T_RevealUnit_P5_Direction)<<"'\n";
			}
		} else if (AlreadyWasRevealed) {
	if (ICBP) cout << "'"<<GetRandomString(T_AddressToCommanderQuiet)<<GetRandomString(T_LostSightOnAnEnemyUnit)<<int(Engine::ActiveUnits[i]->Soldiers[0].X / 10)<<"|"<<int(Engine::ActiveUnits[i]->Soldiers[0].Y / 10)<<".'\n";
	int L_Index = Engine::GVEU(Engine::ActiveUnits[i], EngagedUnits);
if (L_Index != -1) {
	EngagedUnits.erase(EngagedUnits.begin()+L_Index);
	if (ICBP) cout << "'"<<GetRandomString(T_CancellingAttackLostSight)<<"'"; else if (Engine::ActiveUnits[i]->ICBP) cout << GetRandomString(Engine::ActiveUnits[i]->T_AddressToCommanderQuiet)<<GetRandomString(Engine::ActiveUnits[i]->T_NoLongerUnderFire_P1)<<int(Soldiers[0].X / 10)<<"|"<<int(Soldiers[0].Y / 10)<<GetRandomString(Engine::ActiveUnits[i]->T_NoLongerUnderFire_P2)<<"'\n";
	}
			}
		}
	};
	UnitsInSight = L_RevealedUnits;
}

void Unit::EngageEnemyUnits() {
for(int i = 0; i < Soldiers.size() ; i++) {
if (Soldiers[i].IsActive()) {
Soldier* SoldierToAttack = FindSoldierToAttack();
if (SoldierToAttack != nullptr) Soldiers[i].Shoot(*SoldierToAttack,Soldiers[i].IndividualWeapon);
		}
	}
int GroupWeaponsOperators=AmountOfActiveSoldiers;
for(int i = 0; i < GroupWeapons.size() ; i++) {
if (GroupWeaponsOperators>=GroupWeapons[i].OperatorsAmount) {
GroupWeaponsOperators-=GroupWeapons[i].OperatorsAmount;
for(int j = 0; j < GroupWeapons[i].RPM; j++) {
Soldier* SoldierToAttack = FindSoldierToAttack();
if (SoldierToAttack != nullptr) Soldiers[0].Shoot(*SoldierToAttack, GroupWeapons[i]);
			}
		}
	}
}

Soldier* Unit::FindSoldierToAttack() {
Unit* L_UnitToAttack = nullptr;
Soldier* P_SoldierToAttack = nullptr;
	for(int j = 0; j < Engine::ActiveUnits.size() ; j++) {
int L_Index = Engine::GVEU(Engine::ActiveUnits[j], EngagedUnits);
if (Engine::ActiveUnits[j]->Soldiers[0].Side !=Soldiers[0].Side && L_Index != -1) {
	if (L_UnitToAttack == nullptr || Random::get(1,2) == 1) L_UnitToAttack = Engine::ActiveUnits[j];
}
		}
if(L_UnitToAttack != nullptr && L_UnitToAttack->Soldiers.size() > 0)
{
while (P_SoldierToAttack == nullptr && L_UnitToAttack->AmountOfActiveSoldiers > 0) for (int j = 0; j < L_UnitToAttack->Soldiers.size() ; j++) {
if (L_UnitToAttack->AmountOfActiveSoldiers > 1 && j==0) j++;
if (L_UnitToAttack->Soldiers[j].IsActive() && Random::get(1,int(L_UnitToAttack->AmountOfActiveSoldiers)) == 1) P_SoldierToAttack = &L_UnitToAttack->Soldiers[j]; }
	}
return P_SoldierToAttack;
};

void Unit::Initialize(float L_X, float L_Y) {
	for(int i = 0; i < Soldiers.size() ; i++)
	{
		Soldiers[i].X = Random::get(int(L_X) - 10, int(L_X) + 10);
		Soldiers[i].Y = Random::get(int(L_Y) - 10, int(L_Y) + 10);
	};
	Ammo = Soldiers.size()*10;
	MaxAmmo = Ammo;
};

Unit::Unit() {
	T_PositionReport_P1.push_back("Сейчас... ");
	T_PositionReport_P1.push_back("Сейчас посмотрю... ");
	T_PositionReport_P1.push_back("Докладываю... ");
	T_PositionReport_P1.push_back("... ");
	T_PositionReport_P1.push_back("Так... ");
	T_PositionReport_P1.push_back("Сейчас... Докладываю: ");
	T_PositionReport_P2.push_back("Мы находимся в точке ");
	T_PositionReport_P2.push_back("Мы сейчас в точке ");
	T_PositionReport_P2.push_back("Мы в точке ");
	T_PositionReport_P2.push_back("Мы находимся на позиции ");
	T_PositionReport_P2.push_back("Мои бойцы сейчас в точке ");
	T_ReceivedMovementOrder.push_back("Приказ принят. Отправляемся на позицию ");
	T_ReceivedMovementOrder.push_back("Приказ принят. Выдвигаемся на позицию ");
	T_ReceivedMovementOrder.push_back("Приказ принят. Идем к позиции ");
	T_ReceivedMovementOrder.push_back("Приказ понял. Отправляемся на позицию ");
	T_ReceivedMovementOrder.push_back("Приказ понял. Выдвигаемся на позицию ");
	T_ReceivedMovementOrder.push_back("Приказ понял. Идем к позиции ");
	T_SucceededMovementOrder.push_back("Мы прибыли в точку ");
	T_SucceededMovementOrder.push_back("Мы добрались до позиции ");
	T_SucceededMovementOrder.push_back("Мы дошли до точки назначения ");
	T_RevealUnit_P1_Movement.push_back("Обнаружено движение в точке  ");
	T_RevealUnit_P1_Movement.push_back("Заметили движение в точке ");
	T_RevealUnit_P1_Movement.push_back("Мы видим движение... это в точке ");
	T_RevealUnit_P1_Idle.push_back("Тут кто-то есть в точке ");
	T_RevealUnit_P1_Idle.push_back("Мы кого-то видим на позиции ");
	T_RevealUnit_P1_Idle.push_back("Поблизости кто-то есть. Мы видим солдат в точке ");
	T_RevealUnit_P1_Idle.push_back("Мы видим кого-то рядом... Точка ");
	T_RevealUnit_P2_Infantry.push_back("Похоже, пехота... ");
	T_RevealUnit_P2_Infantry.push_back("Это пехота. ");
	T_RevealUnit_P2_Infantry.push_back("Похоже, это пехота. ");
	T_RevealUnit_P3_Amount.push_back("Около ");
	T_RevealUnit_P3_Amount.push_back("Где-то ");
	T_RevealUnit_P3_Amount.push_back("Наверное, где-то ");
	T_RevealUnit_P4_Direction.push_back("Они идут на ");
	T_RevealUnit_P5_1_Direction.push_back("север. ");
	T_RevealUnit_P5_2_Direction.push_back("северо-восток. ");
	T_RevealUnit_P5_3_Direction.push_back("восток. ");
	T_RevealUnit_P5_4_Direction.push_back("юго-восток. ");
	T_RevealUnit_P5_5_Direction.push_back("юг. ");
	T_RevealUnit_P5_6_Direction.push_back("юго-запад. ");
	T_RevealUnit_P5_7_Direction.push_back("запад. ");
	T_RevealUnit_P5_8_Direction.push_back("северо-запад. ");
	T_RevealUnit_P6_Distance.push_back(", это в ");
	T_RevealUnit_P7_Distance.push_back(" метрах от нас. ");
	T_LostSightOnAnEnemyUnit.push_back("Мы потеряли из виду чужой отряд, он бы в точке ");
	T_LostSightOnAnEnemyUnit.push_back("Мы больше не видим отряд, который был в точке ");
	T_LostSightOnAnEnemyUnit.push_back("Чужой отряд скрылся из виду, при последнем визуальном контакте мы видели их в точке ");
	T_LostSightOnAnEnemyUnit.push_back("Мы потеряли контакт с тем отрядом, они были на позиции ");
	T_CancellingAttackLostSight.push_back("Мы больше не можем вести по ним огонь.");
	T_CancellingAttackLostSight.push_back("Мы прекратили вести по ним огонь.");
	T_ContactReport.push_back("Мы видим отряд в точке ");
	T_ContactReport.push_back("Мы видим кого-то в точке ");
	T_ContactReportNoSeenUnits.push_back("Отсюда нам никого не видно.");
	T_ContactReportNoSeenUnits.push_back("Мы никого не видим.");
	T_IsUnderFire.push_back("Мы под огнем! Противник стреляет из точки ");
	T_IsUnderFire.push_back("По нам стреляют! Они в точке ");
	T_IsUnderFire.push_back("По нам открыли огонь! Неприятель стреляет из позиции ");
	T_NoLongerUnderFire_P1.push_back("Неприятель в точке ");
	T_NoLongerUnderFire_P1.push_back("Противник в точке ");
	T_NoLongerUnderFire_P1.push_back("Враг на позиции ");
	T_NoLongerUnderFire_P2.push_back(" больше по нам не стреляет.");
	T_NoLongerUnderFire_P2.push_back(" прекратил вести по нам огонь.");
	T_OneWasWounded.push_back("У нас одного ранило!");
	T_OneWasWounded.push_back("Тут одного ранило!");
	T_OneWasWounded.push_back("У нас раненый!");
	T_OneWasWounded.push_back("Нашего ранили!");
	T_OneEnemyWasShot.push_back("Мы подстрелили одного!");
	T_OneEnemyWasShot.push_back("Мы попали в неприятельского солдата!");
	T_OneEnemyWasShot.push_back("Кажется, наши попали в одного!");
	T_OneEnemyWasShot.push_back("Наши подстрелили неприятельского солдата!");
	T_OneEnemyWasStabbed.push_back("Мы достали одного в ближнем бою!");
	T_OneEnemyWasStabbed.push_back("Мы ранили неприятельского солдата в ближнем бою!");
	T_ReceivedChargeOrder.push_back("Есть. Переходим в наступление на врага в точке ");
	T_ReceivedChargeOrder.push_back("Приказ ясен. Мы будем атаковать противника в точке ");
	T_ReceivedChargeOrder.push_back("Ясно, господин капитан. Идем в атаку против вражеских солдат в точке ");
	T_ReceivedChargeOrder.push_back("Хорошо, мы атакуем неприятеля в точке ");
	T_ReceivedOpenFireOrder.push_back("Есть. Мы открываем огонь по противнику в точке ");
	T_ReceivedOpenFireOrder.push_back("Вас понял. Я приказываю бойцам открыть огонь по солдатам неприятеля в точке ");
	T_ReceivedOpenFireOrder.push_back("Приказ понял. Мы начинаем пальбу по врагу в точке ");
	T_NoEnemiesToAttack.push_back("Мы не видим никого, чтобы атаковать");
	T_NoEnemiesToAttack.push_back("У нас нет визуального контакта с противником");
	T_CannotMovePinnedDown.push_back("Мы не можем двигаться, бойцы прижаты огнем!");
	T_CannotMovePinnedDown.push_back("Мы не можем маневрировать под таким обстрелом!");
	T_CannotMovePinnedDown.push_back("Солдатам не сдвинуться, они под сильным огнем!");
	T_EnemyUnitFragged.push_back("Мы уничтожили вражеский отряд!");
	T_RetreatOrderReceived.push_back("Хорошо, мы отходим.");
	T_RetreatOrderReceived.push_back("Понял, мы отступаем.");
	T_RetreatOrderReceived.push_back("Приказ ясен, выходим из под обстрела.");

	T_Status_P1.push_back("Докладываю: у нас ");
	T_Status_P2.push_back(" боеспособных солдат, ");
	T_Status_P3.push_back(" раненых и ");
	T_Status_P4.push_back(" убитых. ");
	T_Status_P5.push_back("Сейчас мы ");
	T_Status_P6_1.push_back("передислоцируемся в другую точку. ");
	T_Status_P6_2.push_back("стреляем в противника. ");
	T_Status_P6_3.push_back("атакуем противника. ");
	T_Status_P7.push_back("Бойцы ");
	T_Status_P8_1.push_back("отлично замаскированы и ");
	T_Status_P8_2.push_back("хорошо замаскированы и ");
	T_Status_P8_3.push_back("неплохо замаскированы и ");
	T_Status_P8_4.push_back("кое-как замаскированы и ");
	T_Status_P8_5.push_back("никак не замаскированы и ");
	T_Status_P9_1.push_back("отлично укрыты. ");
	T_Status_P9_2.push_back("хорошо укрыты. ");
	T_Status_P9_3.push_back("неплохо укрыты. ");
	T_Status_P9_4.push_back("кое-как укрыты. ");
	T_Status_P9_5.push_back("никак не укрыты. ");
	T_Status_P10.push_back("Солдаты ");
	T_Status_P11_1.push_back("рвутся в бой");
	T_Status_P11_2.push_back("уверены в победе");
	T_Status_P11_3.push_back("сомневаются в победе");
	T_Status_P11_4.push_back("паникуют");
	T_Status_P12_1.push_back(", но ");
	T_Status_P12_2.push_back(" и ");
	T_Status_P13_1.push_back("полны сил. ");
	T_Status_P13_2.push_back("все еще полны сил. ");
	T_Status_P13_3.push_back("немного утомились. ");
	T_Status_P13_4.push_back("устали. ");
	T_Status_P13_5.push_back("сильно устали. ");
	T_Status_P13_6.push_back("уже совсем истощились. ");
	T_Status_P14.push_back("Боезапас ");
	T_Status_P15_1.push_back("полон. ");
	T_Status_P15_2.push_back("почти полон. ");
	T_Status_P15_3.push_back("полон более, чем на половину. ");
	T_Status_P15_4.push_back("полон более, чем на половину. ");
	T_Status_P15_5.push_back("полон менее, чем на половину. ");
	T_Status_P15_6.push_back("уже заканчивается. ");
	T_Status_P15_7.push_back("почти иссяк. ");
	T_Status_P15_8.push_back("пуст.");
	T_Status_P16.push_back(" Мы находимся на возвышенности около ");
	T_Status_P17.push_back(" метров. ");
	T_Status_P18_1.push_back("Мы сейчас не находимся под огнем.");
	T_Status_P18_2.push_back("Мы находимся под слабым огнем.");
	T_Status_P18_3.push_back("Мы находимся под огнем средней интенсивности.");
	T_Status_P18_4.push_back("Мы находимся под сильным огнем.");
	T_Status_P18_5.push_back("Мы находимся под ураганным огнем.");
	T_SoldiersAreTired.push_back("Солдаты устали, господин капитан. Им не помешал бы отдых...");
	T_HasEnteredSector.push_back("Мы вошли в ");
	T_ArtilleryBarrageOrderReceived.push_back("Приказ принят. Мы начинаем артиллерийский обстрел.");
	T_ArtilleryBarrageOrderReceived.push_back("Приказ ясен. Мы открываем огонь артиллерии.");
	T_ArtilleryBarrageOrderReceived.push_back("Есть. Мы начинаем артиллерийский обстрел.");
	T_EnemyWasHitByArtyShell.push_back("Наблюдатели сообщили, что вражеского солдата накрыло нашим снарядом.");
	T_EnemyWasHitByArtyShell.push_back("Согласно информации наблюдателей, наш снаряд накрыл неприятельского солдата.");
	T_EnemyWasHitByArtyShell.push_back("Наблюдалети передали, что разрыв нашего снаряда ранил солдата противника.");
	T_EnemyWasHitByArtyShell.push_back("Наблюдатели говорят, что наш артиллерийский обстрел накрыл неприятельского солдата.");
	T_AllyWasHitByArtyShell.push_back("Наблюдатели сказали, что наш артиллерийский обстрел попадает по своим!");
	T_EnemyWasHitByArtyShellMultiple_P1.push_back("По данным наблюдателей, мы накрыли ");
	T_EnemyWasHitByArtyShellMultiple_P1.push_back("Наш артиллерийский обстрел только что накрыл ");
	T_EnemyWasHitByArtyShellMultiple_P1.push_back("Только что выстрелами из орудий мы попали в ");
	T_EnemyWasHitByArtyShellMultiple_P2.push_back(" солдат противника.");
	T_EnemyWasHitByArtyShellMultiple_P2.push_back(" солдат неприятеля.");
	T_EnemyWasHitByArtyShellMultiple_P2.push_back(" вражеских солдат.");
	T_ArtilleryBarrageOrderInterruptedNoAmmo.push_back("У нас зкончились снаряды. Мы не можем больше стрелять.");
	T_ArtilleryBarrageOrderInterruptedNoAmmo.push_back("У нас больше нет снарядов. Мы не можем больше стрелять.");
	T_ArtilleryBarrageOrderSucceed.push_back("Мы выполнили приказ об обстреле.");
	T_ArtilleryBarrageOrderSucceed.push_back("Мы выпустили снаряды в указанную точку.");
	T_ArtilleryBarrageOrderSucceed.push_back("Мы завершили артиллерийский обстрел.");
	T_ArtilleryBarrageOrderSucceed.push_back("Артиллерийский обстрел завершен.");
	
	};
