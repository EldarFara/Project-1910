#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include "Random.hpp"
using Random = effolkronium::random_static;

#define DBP DistanceBetweenPoints
#define ABP AngleBetweenPoints
#define GVEU GetVectorElementUnit
#define ICBP IsControlledByPlayer

enum WeaponType { Weapon_None, WeaponRF_Mosin, WeaponRF_Gewehr98, WeaponHMG_MaximRussian, WeaponFG_76mmFieldGun };
enum SoldierRank { SoldierRank_Private, SoldierRank_PlatoonCommander };
enum WarSide { WarSide_Allies, WarSide_Enemy };
enum OrderType { OrderType_Movement, OrderType_Status, OrderType_Contacts, OrderType_Attack, OrderType_Retreat, OrderType_PositionReport, OrderType_ArtilleryBarrage, OrderType_ShareAmmo};
enum UnitType { Unit_Generic, Unit_Artillery, Unit_AmmoCarriage };

struct Point2D
{
	float X, Y;
};

class Engine;
class Soldier;
class Unit;
class Order;
class Weapon;

#include "Weapon.h"
#include "Sector.h"
#include "Order.h"
#include "Soldier.h"
#include "Unit.h"
#include "Engine.h"
#include "Weapon.cpp"
#include "Sector.cpp"
#include "Order.cpp"
#include "Soldier.cpp"
#include "Unit.cpp"
#include "Engine.cpp"
#include "InitFirstPlatoon.cpp"
#include "InitSecondPlatoon.cpp"
#include "InitChapterTwoUnits.cpp"
#include "StartChapter_One.cpp"
#include "StartChapter_Two.cpp"


