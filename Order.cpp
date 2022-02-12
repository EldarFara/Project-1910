#pragma once
#include "Global.h"

Order::Order(OrderType L_Type) {
	Type = L_Type;
	}
Order::Order(OrderType L_Type, int L_Parameter1, int L_Parameter2) {
	Type = L_Type;
	Parameter1 = L_Parameter1;
	Parameter2 = L_Parameter2;
	}
Order::Order(OrderType L_Type, int L_Parameter1, int L_Parameter2, int L_Parameter3) {
	Type = L_Type;
	Parameter1 = L_Parameter1;
	Parameter2 = L_Parameter2;
	Parameter3 = L_Parameter3;
	}
Order::Order(OrderType L_Type, Unit* L_Parameter1, int L_Parameter2) {
	Type = L_Type;
	UnitPointer1 = L_Parameter1;
	Parameter1 = L_Parameter2;
	}
