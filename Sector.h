#pragma once
#include "Global.h"

class Sector {
	public:
	int X, Y;
	float Radius, Cover = 1, Visibility = 1;
	string Name;
	string InName;
	float Height = 0;
	bool IsChecked = false;
	bool IsReliefSpecification;
	Sector(Point2D,float,float,float,float,string,string);
	Sector(Point2D,float,float,float,string,string);
	Sector(Point2D, float,float,string,string);
	};
