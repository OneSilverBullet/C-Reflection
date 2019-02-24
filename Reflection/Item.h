#pragma once
#include "Object.h"

class Item :public Object {
public:
	Item();
	virtual ~Item();

	virtual void Print() = 0;

};