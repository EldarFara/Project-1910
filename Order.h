#pragma once
#include "Global.h"

class Order {
	public:
	OrderType Type;
	int Parameter1, Parameter2, Parameter3;
	Unit* UnitPointer1;
	bool IsReceived = false;
	Order(OrderType);
	Order(OrderType, int, int);
	Order(OrderType, int, int, int);
	Order(OrderType, Unit*, int);
	};
