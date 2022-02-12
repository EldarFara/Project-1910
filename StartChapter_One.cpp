#pragma once
#include "Global.h"

void Engine::StartChapter_One() {
	CurrentChapter = 1;
	StoryLineParameter1 = 0;
	FinishChapter = 0;
	
	InitializeFirstPlatoon();
	FirstPlatoon.Initialize(1100, Random::get(1500, 2000));
	ActiveUnits.push_back(&FirstPlatoon);
	PlayerUnits.push_back(&FirstPlatoon);
	InitializeSecondPlatoon();
	SecondPlatoon.Initialize(1100, Random::get(2000, 2500));
	ActiveUnits.push_back(&SecondPlatoon);
	PlayerUnits.push_back(&SecondPlatoon);
	for(int i = 0; i < Random::get(5,6); i++) {
	Unit* Temp = new Unit; Temp = CreateUnit(Random::get(21, 26), WeaponRF_Gewehr98, WarSide_Enemy, Random::get(1400, 2600), Random::get(1200, 2600), 0.1, 0.1); AIUnits.push_back(Temp);
	ActiveUnits.push_back(Temp); }
	for(int i = 0; i < 2; i++) 
	Sectors.push_back(Sector(GetPointForSector(1300,3000,1050,2600),0.8,0.6,60, "деревня","деревню"));
	for(int i = 0; i < 2; i++) 
	Sectors.push_back(Sector(GetPointForSector(1300, 3000, 1050, 2600),0.8,0.6,120, "большая деревня","большую деревню"));
	for(int i = 0; i < 4; i++) 
	Sectors.push_back(Sector(GetPointForSector(1300, 3000, 1050, 2600),0.5,0.6,60, "лес","лес"));
	for(int i = 0; i < 4; i++) 
	Sectors.push_back(Sector(GetPointForSector(1300, 3000, 1050, 2600),0.5,0.6,120, "большой лес","большой лес"));
	for(int i = 0; i < 3; i++) 
	Sectors.push_back(Sector(GetPointForSector(1300, 3000, 1050, 2600),20,110, "холм","холм"));
	TimeHour = 5; TimeMinute = 21;
	
cout<<"Глава первая: Кампания в Восточной Пруссии. Гумбиннен-Гольдапское сражение\n20 августа 1914 года, Восточная Пруссия.\n'Поручик Ландышев у аппарата... Первый взвод телефонной команды прибыл на позицию "<<int(FirstPlatoon.Soldiers[0].X/10)<<"|"<<int(FirstPlatoon.Soldiers[0].Y/10)<<" и ждет указаний. Тюльпанов со своим вторым взводом тоже где-то неподалеку.'\n'Слушай сюда, Ландышев. Вчера Волжский полк 28 дивизии прорвал линию фронта в окрестностях Гумбиннена и, преследуя немцев, ушел далеко на запад, настолько, что потерял всякую связь с командованием дивизии. Ваша цель - найти расположение штаба Волжского полка и протянуть к ним телефонный провод от штаба дивизии, чтобы с ними могли связаться. Волжцы должны быть где-то в этом районе. Скорее всего, они находятся в одной из деревень. Проверьте каждую из них.'\n'Понял вас, господин капитан.'\n'У меня нет карты местности, в которой вы находитесь, поэтому вам нужно будет доложить о том, что вы видите вокруг.'\n'Здесь есть:";
for(int i = 0; i < Engine::Sectors.size() ; i++) 	{
	cout<<"\n - "<<Sectors[i].Name<<" в точке "<<(Sectors[i].X+5)/10<<"|"<<(Sectors[i].Y+5)/10<<";";
	}; cout<<"'";
	
	while (FinishChapter==0) GameIteration();
	if (FinishChapter==2) cout << "\nГЛАВА УСПЕШНО ЗАВЕРШЕНА"<<endl<<"'Мы обыскали все населенные пункты в окрестностях, но так и не нашли волжцев... Наверное, они покинули это место, потому что теперь оно просто кишит немцами. Похоже, что немцы нанесли удар и штаб Волжского полка отступил дальше на восток - в этой местности не осталось наших.'\n'Возможно, так и есть, Ландышев. Пора вам уходить из этого района.'"; else cout<<"ПОРАЖЕНИЕ";
	};
