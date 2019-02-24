#include "ConsoleItem.h"

ConsoleItem::ConsoleItem():Item()
{
	className = "ConsoleItem";
}

ConsoleItem::~ConsoleItem()
{
}

void ConsoleItem::Print()
{
	cout << className << endl;
}
