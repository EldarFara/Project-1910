#pragma once
#include "Global.h"

Sector::Sector(Point2D L_Point,float L_Visibility,float L_Cover,float L_Radius,string L_Name,string L_InName) {
	X = L_Point.X;
	Y = L_Point.Y;
	Visibility = L_Visibility;
	Cover = L_Cover;
	Radius = L_Radius;
	Name = L_Name;
	InName = L_InName;
	bool IsReliefSpecification = false;
	}
Sector::Sector(Point2D L_Point,float L_Visibility,float L_Cover,float L_Radius,float L_Height,string L_Name,string L_InName) {
	X = L_Point.X;
	Y = L_Point.Y;
	Visibility = L_Visibility;
	Cover = L_Cover;
	Radius = L_Radius;
	Height = L_Height;
	Name = L_Name;
	InName = L_InName;
	bool IsReliefSpecification = false;
	}


Sector::Sector(Point2D L_Point,float L_Height,float L_Radius,string L_Name,string L_InName) {
	X = L_Point.X;
	Y = L_Point.Y;
	Radius = L_Radius;
	Height = L_Height;
	Name = L_Name;
	InName = L_InName;
	bool IsReliefSpecification = true;
	}
