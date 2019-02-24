#pragma once
#include "Item.h"

class ConsoleItem : public Item {
public:
	ConsoleItem();
	~ConsoleItem();

	virtual void Print() override;
};