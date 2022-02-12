#pragma once
#include "Global.h"

vector <Unit*> Engine::ActiveUnits;
vector <Unit*> Engine::AIUnits;
vector <Sector> Engine::Sectors;
vector <Unit*> Engine::PlayerUnits;

void Engine::AnalyzeOrderCode(string L_Input) {
//for(int i;i< L_Input.size();i++) if (L_Input.substr(i, 1)!="0" && L_Input.substr(i, 1)!="1" && L_Input.substr(i, 1)!="2" && L_Input.substr(i, 1)!="3" && L_Input.substr(i, 1)!="4" && L_Input.substr(i, 1)!="5" && L_Input.substr(i, 1)!="6" && L_Input.substr(i, 1)!="7" && L_Input.substr(i, 1)!="8" && L_Input.substr(i, 1)!="9") L_Input == "";
	if(L_Input == "")
	{
		SkipOutput = true;
		return;
	};
	int L_OrderParameter1, L_OrderParameter2, L_OrderParameter3;
	long long L_OrderCode = stoll(L_Input);
	Engine::ReverseInteger(L_OrderCode);
	Unit* ChosenUnit;
	OrderType ChosenOrderType;
	ChosenUnit = PlayerUnits[(L_OrderCode % 10)-1];
	vector <string> L_T_OrderAttack;
	int L_NumberOfAttacks = 0;
	switch((L_OrderCode / 10) % 10)
	{
		case 1:
		ChosenOrderType = OrderType_Movement;
		if (L_Input.size() < 8) return;
	for(int j = 0; j < ChosenUnit->Orders.size() ; j++) if (ChosenUnit->Orders[j].Type ==	OrderType_Attack || ChosenUnit->Orders[j].Type ==	OrderType_Movement || ChosenUnit->Orders[j].Type ==	OrderType_Retreat) ChosenUnit->Orders.erase(ChosenUnit->Orders.begin()+j);
L_OrderParameter1 = stoi(L_Input.substr(2, 3));
		L_OrderParameter2 = stoi(L_Input.substr(5, 3));
		ChosenUnit->Orders.push_back(Order(ChosenOrderType, L_OrderParameter1 * 10, L_OrderParameter2 * 10));
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(Engine::T_OrderMovement)<<L_OrderParameter1<<"|"<<L_OrderParameter2<<".'";
		break;
		case 2:
		ChosenOrderType = OrderType_PositionReport;
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(Engine::T_AskPosition)<<"'";
		break;
		case 3:
		ChosenOrderType = OrderType_Status;
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(Engine::T_AskStatus)<<"'";
		break;
		case 4:
		ChosenOrderType = OrderType_Contacts;
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(Engine::T_AskContacts)<<"'";
		break;
		case 5:
		if(ChosenUnit->Type==Unit_AmmoCarriage)
		{
		ChosenOrderType = OrderType_ShareAmmo;
} else if(ChosenUnit->Type==Unit_Artillery)
		{
if (L_Input.size() < 9) return;
ChosenUnit->IsMoving = false;
for(int j = 0; j < ChosenUnit->Orders.size() ; j++) if (ChosenUnit->Orders[j].Type ==	OrderType_ArtilleryBarrage || ChosenUnit->Orders[j].Type ==	OrderType_Attack || ChosenUnit->Orders[j].Type ==	OrderType_Movement || ChosenUnit->Orders[j].Type ==	OrderType_Retreat) ChosenUnit->Orders.erase(ChosenUnit->Orders.begin()+j);
ChosenOrderType = OrderType_ArtilleryBarrage;
L_OrderParameter1 = stoi(L_Input.substr(2, 3));
L_OrderParameter2 = stoi(L_Input.substr(5, 3));
L_OrderParameter3 = stoi(L_Input.substr(8, L_Input.size()-8));
ChosenUnit->Orders.push_back(Order(ChosenOrderType, L_OrderParameter1 * 10, L_OrderParameter2 * 10,L_OrderParameter3));
cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(T_OrderArtilleryBarrage_P1)<<L_OrderParameter3<<Unit::GetRandomString(T_OrderArtilleryBarrage_P2)<<L_OrderParameter1<<"|"<<L_OrderParameter2<<".'";
		} else {
		ChosenOrderType = OrderType_Attack;
	for(int j = 0; j < ChosenUnit->Orders.size() ; j++) if (ChosenUnit->Orders[j].Type ==	OrderType_Attack || ChosenUnit->Orders[j].Type ==	OrderType_Movement || ChosenUnit->Orders[j].Type ==	OrderType_Retreat) ChosenUnit->Orders.erase(ChosenUnit->Orders.begin()+j);
	L_OrderParameter1 = stoi(L_Input.substr(2, 1));
for (int j = 0; j < ChosenUnit->UnitsInSight.size() ; j++) {
if (ChosenUnit->Soldiers[0].Side != ChosenUnit->UnitsInSight[j]->Soldiers[0].Side) {
L_NumberOfAttacks++;ChosenUnit->Orders.push_back(Order(
OrderType_Attack, ChosenUnit->UnitsInSight[j], L_OrderParameter1));
int L_Index = Engine::GVEU(ChosenUnit->UnitsInSight[j], ChosenUnit->EngagedUnits);
if (L_Index == -1) { 
ChosenUnit->EngagedUnits.push_back(ChosenUnit->UnitsInSight[j]);
ChosenUnit->UnitsInSight[j]->EngagedUnits.push_back(ChosenUnit);
		}
	}
}
if (L_NumberOfAttacks==0) ChosenUnit->Orders.push_back(Order(
OrderType_Attack, nullptr, -1));
	if(L_OrderParameter1 == 1) L_T_OrderAttack = T_OrderOpenFire; else L_T_OrderAttack = T_OrderCharge;
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(L_T_OrderAttack)<<"'";
}
		break;
		case 6:
		ChosenOrderType = OrderType_Retreat;
	for(int j = 0; j < ChosenUnit->Orders.size() ; j++) if (ChosenUnit->Orders[j].Type ==	OrderType_Attack || ChosenUnit->Orders[j].Type ==	OrderType_Movement || ChosenUnit->Orders[j].Type ==	OrderType_Retreat) ChosenUnit->Orders.erase(ChosenUnit->Orders.begin()+j);
		cout<<"'"<<Unit::GetRandomString(ChosenUnit->T_AddressFromCommander)<<Unit::GetRandomString(T_OrderRetreat)<<"'";
		break;
	}
if (ChosenOrderType != OrderType_Attack && ChosenOrderType != OrderType_ArtilleryBarrage && ChosenOrderType != OrderType_Movement) ChosenUnit->Orders.push_back(Order(ChosenOrderType));
	};

void Engine::GameIteration() {
	PreIterationCalculations();
	AIIteration();
	TimeMinute++;
		if (TimeMinute >= 60) {
			TimeMinute = 0;
			TimeHour++;
			}
	cout<<endl<<TimeHour<<":"<<TimeMinute<<" ";
	SkipOutput = false;
	while(!SkipOutput)
	{
		string L_OrderCode;
		getline(cin, L_OrderCode);
		AnalyzeOrderCode(L_OrderCode);
	}
	for(int i = 0; i < ActiveUnits.size() ; i++)
	{
		ActiveUnits[i]->PerformIterationActions();
	};
	};
	
void Engine::ReverseInteger(long long& L_Integer) {
	long L_NewInteger = 0, Temp;
    while(L_Integer!=0)    
  {    
     Temp=L_Integer%10;      
     L_NewInteger=L_NewInteger*10+Temp;    
     L_Integer/=10;    
  }    
    	L_Integer = L_NewInteger;
         }

void Engine::ReverseString(string& L_String) {
	int n = L_String.length();
    for (int i = 0; i < n / 2; i++) 
        swap(L_String[i], L_String[n - i - 1]);
	}

float Engine::DistanceBetweenPoints(float L_X1, float L_Y1, float L_X2, float L_Y2) {
	return sqrt((L_X1-L_X2)*(L_X1-L_X2) + (L_Y1-L_Y2)*(L_Y1-L_Y2));
	}

float Engine::AngleBetweenPoints(float L_X1, float L_Y1, float L_X2, float L_Y2) {
L_X2+=10; L_Y2+=10;
	float L_Result = (atan2(GetModulus(L_X1 - L_X2)*(L_Y2 - L_Y1)/GetModulus(L_Y2 - L_Y1), GetModulus(L_Y2 - L_Y1)*(L_X1 - L_X2)/GetModulus(L_X1 - L_X2))*180/3.14);
	if (L_Result<0) L_Result=360+L_Result; else if ((L_X2-L_X1)<0 && (L_Y1-L_Y2)<0)L_Result=180+L_Result;
	if ((L_X2-L_X1)>0 && (L_Y1-L_Y2)>0)L_Result=L_Result-180;
	return L_Result;
	}

Unit* Engine::CreateUnit(int L_Amount,WeaponType L_Weapon,WarSide L_Side,float L_X,float L_Y, float L_ShootingSkill, float L_MeleeSkill) {
	Unit* L_Unit = new Unit;
	for(int i = 0; i < L_Amount; i++) L_Unit->Soldiers.push_back(Soldier(L_Unit, L_Weapon, L_Side, L_ShootingSkill, L_MeleeSkill));
	L_Unit->Initialize(L_X, L_Y);
	return L_Unit;
	}

void Engine::PreIterationCalculations() {
	for(int i = 0; i < ActiveUnits.size() ; i++)
	{ bool L_IsInSector = false;
	ActiveUnits[i]->Visibility = ActiveUnits[i]->VisibilityModifier;
	ActiveUnits[i]->Cover = ActiveUnits[i]->CoverModifier;
	ActiveUnits[i]->Height = 0;
		for(int j = 0; j < Engine::Sectors.size() ; j++) 	{
float L_Distance = Engine::DBP(ActiveUnits[i]->Soldiers[0].X,ActiveUnits[i]->Soldiers[0].Y,Sectors[j].X,Sectors[j].Y);
if (Sectors[j].Radius > L_Distance) {
L_IsInSector = true;
if (ActiveUnits[i]->CurrentSector == nullptr) {
	ActiveUnits[i]->CurrentSector = &Engine::Sectors[j];
	if (ActiveUnits[i]->ICBP) { cout<<"'"<<Unit::GetRandomString(ActiveUnits[i]->T_AddressToCommanderQuiet)<<Unit::GetRandomString(ActiveUnits[i]->T_HasEnteredSector)<<Engine::Sectors[j].InName<<".'\n";
	if(ActiveUnits[i]->ICBP && CurrentChapter==1 && !Engine::Sectors[j].IsChecked && (Engine::Sectors[j].Name=="деревня"||Engine::Sectors[j].Name=="большая деревня")) {
		Engine::Sectors[j].IsChecked = true;
	cout<<"'"<<Unit::GetRandomString(ActiveUnits[i]->T_AddressToCommanderQuiet)<<"Похоже, здесь нет расположения волжского полка. Поищем в другом месте.'\n";
		StoryLineParameter1++;
		if (StoryLineParameter1>3) FinishChapter=2;
		}
	}
}
ActiveUnits[i]->Visibility = ActiveUnits[i]->Visibility*Sectors[j].Visibility;
ActiveUnits[i]->Cover = ActiveUnits[i]->Cover*Sectors[j].Cover;
ActiveUnits[i]->Height += Sectors[j].Height-Sectors[j].Height*(L_Distance/Sectors[j].Radius);
		} }
	if(!L_IsInSector) ActiveUnits[i]->CurrentSector = nullptr;
	ActiveUnits[i]->OldSuspression = ActiveUnits[i]->Suspression*sqrt(float(ActiveUnits[i]->AmountOfActiveSoldiers+1))/3.6;
	ActiveUnits[i]->Suspression = 0;
	ActiveUnits[i]->AmountOfActiveSoldiers = 0;
	ActiveUnits[i]->AmountOfWoundedSoldiers = 0;
	ActiveUnits[i]->AmountOfKilledSoldiers = 0;
	for (int j = 0; j < ActiveUnits[i]->Soldiers.size() ; j++) if (!ActiveUnits[i]->Soldiers[j].IsKilled*!ActiveUnits[i]->Soldiers[j].IsWounded) ActiveUnits[i]->AmountOfActiveSoldiers++; else if (!ActiveUnits[i]->Soldiers[j].IsKilled) ActiveUnits[i]->AmountOfWoundedSoldiers++; else ActiveUnits[i]->AmountOfKilledSoldiers++;
	};
}

void Engine::AIIteration() {
switch(CurrentChapter)
{
	case 1:
for (int i = 0; i < AIUnits.size() ; i++) {
for (int j = 0; j < AIUnits[i]->UnitsInSight.size() ; j++) {
if (AIUnits[i]->Soldiers[0].Side != AIUnits[i]->UnitsInSight[j]->Soldiers[0].Side) {
if (!Engine::AreUnitsEngaged(AIUnits[i], AIUnits[i]->UnitsInSight[j])) {
for(int k = 0; k < AIUnits[i]->Orders.size() ; k++) if (AIUnits[i]->Orders[k].Type ==	OrderType_Attack || AIUnits[i]->Orders[k].Type ==	OrderType_Movement || AIUnits[i]->Orders[k].Type ==	OrderType_Retreat) AIUnits[i]->Orders.erase(AIUnits[i]->Orders.begin()+k);
AIUnits[i]->Orders.push_back(Order(
OrderType_Attack, AIUnits[i]->UnitsInSight[j], 1));
AIUnits[i]->EngagedUnits.push_back(AIUnits[i]->UnitsInSight[j]);
AIUnits[i]->UnitsInSight[j]->EngagedUnits.push_back(AIUnits[i]);
cout<<"'"<<Unit::GetRandomString(AIUnits[i]->UnitsInSight[j]->T_AddressToCommanderEngaged)<<Unit::GetRandomString(AIUnits[i]->UnitsInSight[j]->T_IsUnderFire)<<int((AIUnits[i]->Soldiers[0].X+5) /10)<<"|"<<int((AIUnits[i]->Soldiers[0].Y+5)/10)<<".'\n";
	}
}
		}
if(AIUnits[i]->EngagedUnits.size() == 0 && AIUnits[i]->IsMoving == false && Random::get(1,12)==1) {
	AIUnits[i]->Orders.push_back(Order(
OrderType_Movement, Random::get(1300, 2600),Random::get(1300, 2600)));
		}
	};
	break;
	case 2:
for (int i = 0; i < AIUnits.size() ; i++) {
if(AIUnits[i]->EngagedUnits.size() == 0 && AIUnits[i]->IsMoving == false) {
	AIUnits[i]->Orders.push_back(Order(
OrderType_Movement, 3300,AIUnits[i]->Soldiers[0].Y));
	} else for (int j = 0; j < AIUnits[i]->UnitsInSight.size() ; j++) {
if (AIUnits[i]->Soldiers[0].Side != AIUnits[i]->UnitsInSight[j]->Soldiers[0].Side) {
if (!Engine::AreUnitsEngaged(AIUnits[i], AIUnits[i]->UnitsInSight[j])) {
for(int k = 0; k < AIUnits[i]->Orders.size() ; k++) if (AIUnits[i]->Orders[k].Type ==	OrderType_Attack || AIUnits[i]->Orders[k].Type ==	OrderType_Movement || AIUnits[i]->Orders[k].Type ==	OrderType_Retreat) AIUnits[i]->Orders.erase(AIUnits[i]->Orders.begin()+k);
AIUnits[i]->Orders.push_back(Order(
OrderType_Attack, AIUnits[i]->UnitsInSight[j], 2));
AIUnits[i]->EngagedUnits.push_back(AIUnits[i]->UnitsInSight[j]);
AIUnits[i]->UnitsInSight[j]->EngagedUnits.push_back(AIUnits[i]);
cout<<"'"<<Unit::GetRandomString(AIUnits[i]->UnitsInSight[j]->T_AddressToCommanderEngaged)<<Unit::GetRandomString(AIUnits[i]->UnitsInSight[j]->T_IsUnderFire)<<int((AIUnits[i]->Soldiers[0].X+5) /10)<<"|"<<int((AIUnits[i]->Soldiers[0].Y+5)/10)<<".'\n";
	}
}
}}
	break;
}
}
	
int Engine::GetVectorElementUnit(Unit* L_Pointer, vector <Unit*> L_Vector) {
std::vector<Unit*>::iterator it = std::find(L_Vector.begin(), L_Vector.end(), L_Pointer);
if (it == L_Vector.end()) return -1; else
return std::distance(L_Vector.begin(), it);
	};

bool Engine::AreUnitsEngaged(Unit* L_Unit1,Unit*L_Unit2) {
	int L_Index1 = Engine::GVEU(L_Unit1, L_Unit2->EngagedUnits);
	int L_Index2 = Engine::GVEU(L_Unit2, L_Unit1->EngagedUnits);
if (L_Index1 == -1 && L_Index2 == -1) return false; else return true;
	}
	
Point2D Engine::GetPointForSector(int L_X1, int L_X2, int L_Y1, int L_Y2) {
	bool L_Done = false; int L_Y, L_X;
	while (!L_Done) {
		L_X = Random::get(L_X1, L_X2);
		L_Y = Random::get(L_Y1, L_Y2);
		L_Done = true;
		for (int i = 0; i < Engine::Sectors.size(); i++) {
			if (Engine::DBP(L_X, L_Y, Engine::Sectors[i].X, Engine::Sectors[i].Y) < 100) L_Done = false;
		}
	}
	Point2D L_Point; L_Point.X = L_X; L_Point.Y = L_Y;
	return L_Point;
}

float Engine::GetModulus(float L_Number) {
if (L_Number >= 0) return L_Number; else return L_Number*(-1);
	};

void Engine::SelectChapter() {
int L_Chapter;
cout<<"Выберите главу: ";
cin>>L_Chapter;
switch(L_Chapter) {
	case 1:
	StartChapter_One();
	case 2:
	StartChapter_Two();
	break;
}
SelectChapter();
	};

Soldier* Engine::Explosion(int L_X, int L_Y, float L_Radius, float L_HEPower) {
for (int i = 0; i < ActiveUnits.size() ; i++) {
for (int j = 0; j < ActiveUnits[i]->Soldiers.size() ; j++) {
float L_Distance=DBP(ActiveUnits[i]->Soldiers[j].X,ActiveUnits[i]->Soldiers[j].Y,L_X,L_Y);
if (L_Distance<100) ActiveUnits[i]->Suspression+=1;
	if (Random::get(int(100*L_HEPower*ActiveUnits[i]->Cover), 1000)>100 && ActiveUnits[i]->Soldiers[j].IsActive() && L_Distance < L_Radius) {
	ActiveUnits[i]->Soldiers[j].GetWounded(nullptr);
	return &ActiveUnits[i]->Soldiers[j];
		}
	};};
return nullptr;
}
