#pragma once
#include "Global.h"

void Engine::StartChapter_Two() {
	CurrentChapter = 2;
	FinishChapter = 0;
	
	PlayerUnits.push_back(&FirstPlatoon);
	PlayerUnits.push_back(&SecondPlatoon);
	PlayerUnits.push_back(&PionovTeam);
	PlayerUnits.push_back(&GvozdikovTeam);
	PlayerUnits.push_back(&FourthBattery);
	ActiveUnits.push_back(&FirstPlatoon);
	ActiveUnits.push_back(&SecondPlatoon);
	ActiveUnits.push_back(&PionovTeam);
	ActiveUnits.push_back(&GvozdikovTeam);
	ActiveUnits.push_back(&FourthBattery);
	InitializeFirstPlatoon();
	InitializeSecondPlatoon();
	InitializeChapterTwoUnits();
	FirstPlatoon.Initialize(1400, Random::get(1300, 1700));
	SecondPlatoon.Initialize(1400, Random::get(1900, 2400));
	PionovTeam.Initialize(1500, Random::get(1300, 1700));
	GvozdikovTeam.Initialize(1500, Random::get(1900, 2400));
	FourthBattery.Initialize(3300, Random::get(1600, 1900));
	FourthBattery.Ammo = 3000;
	for(int i = 0; i < Random::get(22,25); i++) {
	Unit* Temp = new Unit; Temp = CreateUnit(Random::get(25, 35), WeaponRF_Gewehr98, WarSide_Enemy, Random::get(-400, 800), Random::get(1100, 2700), 0.1, 0.15); AIUnits.push_back(Temp);
	ActiveUnits.push_back(Temp); }
	Sectors.push_back(Sector(GetPointForSector(1650, 2050, 1400, 2200),20,120, "холм","холм"));
	Sectors.push_back(Sector(GetPointForSector(2100, 2500, 1400, 2200),20,120, "холм","холм"));
	Sectors.push_back(Sector(GetPointForSector(2550, 3100, 1400, 2200),20,120, "холм","холм"));
	Sectors.push_back(Sector(GetPointForSector(1650, 2050, 1400, 2200),0.8,0.1,15,90, "окопы","окопы"));
	Sectors.push_back(Sector(GetPointForSector(2100, 2500, 1400, 2200),0.8,0.1,15,90, "окопы","окопы"));
	Sectors.push_back(Sector(GetPointForSector(2550, 3100, 1400, 2200),0.8,0.1,15,90, "окопы","окопы"));
	TimeHour = 10; TimeMinute = 12;
	
cout<<"Глава вторая: Отступление из Галиции. Горлицкий прорыв.";
for(int i = 0; i < Engine::Sectors.size() ; i++) 	{
	cout<<"\n - "<<Sectors[i].Name<<" в точке "<<(Sectors[i].X+5)/10<<"|"<<(Sectors[i].Y+5)/10<<";";
	}; cout<<"'";
	
	while (FinishChapter==0) GameIteration();
	if (FinishChapter==2) cout << "\nГЛАВА УСПЕШНО ЗАВЕРШЕНА"<<endl; else cout<<"ПОРАЖЕНИЕ";
	};
