#include "ClassFactory.h"

static int test = 0;

ClassFactory::ClassFactory()
{
}

ClassFactory::~ClassFactory()
{
	for(auto it : objectItems)
	{
		if (it.second == nullptr)
		{
			delete it.second;
			it.second = nullptr;
		}
	}
	objectItems.clear();
}

void * ClassFactory::CreateItem(string className)
{
	ItemObject constructor = nullptr;
	if (objectItems.find(className) != objectItems.end())
	{
		constructor = objectItems.find(className)->second->itemObject;
	}
	if (constructor == nullptr)
	{
		return nullptr;
	}
	return (*constructor)();
}

//ItemObject相当于一个回调函数
void ClassFactory::RegisterItem(const string & className, ItemObject item)
{
	map<string, ItemObjectClass*>::iterator it = objectItems.find(className);
	if (it != objectItems.end())
	{
		objectItems[className]->itemObject = item;
	}
	else
	{
		objectItems.insert(make_pair(className, new ItemObjectClass(item)));
	}
}
