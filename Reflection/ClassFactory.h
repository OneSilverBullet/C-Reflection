#pragma once
#include "Singleton.h"
#include <map>
#include <string>

using namespace std;

class Item;

//定义一个返回值为void*的，参数为null的函数指针
typedef void* (*ItemObject)();

struct ItemObjectClass 
{
	explicit ItemObjectClass(ItemObject item) :
		itemObject(item)
	{

	}

	ItemObject itemObject;
};

//作为所有类的工厂，如果需要某一个类的工厂可以继承该类
class ClassFactory :public Singleton<ClassFactory>
{
public:
	ClassFactory();
	~ClassFactory();

	//用于创建类，其中返回void*用于减少类的耦合
	void* CreateItem(string className);

	//用于注册
	void RegisterItem(const string& className, ItemObject item);

private:
	//缓存类名和生成类实例函数指针的map。
	map<string, ItemObjectClass*> objectItems;
};