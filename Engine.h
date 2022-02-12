#pragma once
#include "Global.h"

class Engine {
	public:
	void GameIteration();
	void PreIterationCalculations();
	void AIIteration();
	void StartChapter_One();
	void StartChapter_Two();
	void AnalyzeOrderCode(string);
	static int GetVectorElementUnit(Unit*,vector <Unit*>);
	static Unit* CreateUnit(int,WeaponType,WarSide,float,float,float,float);
	static void ReverseInteger(long long&);
	static void ReverseString (string&);
	static float DistanceBetweenPoints(float,float,float,float);
	static float AngleBetweenPoints(float,float,float,float);
	static bool AreUnitsEngaged(Unit*,Unit*);
	Point2D GetPointForSector(int,int,int,int);
	static Soldier* Explosion(int,int,float,float);
	bool SkipOutput = 0;
	int TimeHour, TimeMinute;
	int CurrentChapter;
	static vector <Unit*> ActiveUnits;
	static vector <Unit*> AIUnits;
	static vector <Unit*> PlayerUnits;
	static vector <Sector> Sectors;
	static float GetModulus(float);
	Unit FirstPlatoon, SecondPlatoon, FourthBattery, GvozdikovTeam, PionovTeam, AmmoCarriage;
	void InitializeFirstPlatoon();
	void InitializeSecondPlatoon();
	void InitializeChapterTwoUnits();
	void SelectChapter();
	int StoryLineParameter1 = 0;
	int FinishChapter = 0;
	vector <string> T_OrderMovement = {"Отправляйтесь на позицию ", "Выдвигайтесь на позицию ", "Идите в точку ", "Двигайтесь в точку "};
	vector <string> T_AskPosition = {"Где вы находитесь? ", "Доложите о вашем местонахождении. ", "Где вы? ", "В какой точке вы находитесь? ", "Сообщите свои координаты. ", "Скажи мне, где вы?","Мне нужно узнать, где вы находитесь","В каком вы сейчас месте?", "Где вы сейчас? Доложите."};
	vector <string> T_AskContacts = {"Вы видите кого-нибудь?", "Доложите у наличии вражеских солдат поблизости.", "Кого вы можете наблюдать поблизости?", "Есть ли кто-то рядом с вашей позицией?"};
	vector <string> T_AskStatus = {"Оцените обстановку.", "Доложите обстановку."};
	vector <string> T_OrderOpenFire = {"Приказываю открыть огонь по противнику.", "Откройте огонь по неприятелю."};
	vector <string> T_OrderCharge = {"Атакуйте противника.", "Перейдите в наступление."};
	vector <string> T_OrderRetreat = {"Вам нужно выйти из боя.", "Отдаю приказ об отступлении.", "Приказываю выйти из боя."};
	vector <string> T_OrderArtilleryBarrage_P1= {"Начните артиллерийский обстрел. Выпустите ","Пора начать артиллерийский обстрел. Выстрелите ","Приказываю начать артиллерийский обстрел. Выпустите "};
	vector <string> T_OrderArtilleryBarrage_P2= {" снарядов в точку "," снарядов по точке "};
	};
