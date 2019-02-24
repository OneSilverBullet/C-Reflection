#pragma once
#include "Singleton.h"
#include <map>
#include <string>

using namespace std;

class Item;

//����һ������ֵΪvoid*�ģ�����Ϊnull�ĺ���ָ��
typedef void* (*ItemObject)();

struct ItemObjectClass 
{
	explicit ItemObjectClass(ItemObject item) :
		itemObject(item)
	{

	}

	ItemObject itemObject;
};

//��Ϊ������Ĺ����������Ҫĳһ����Ĺ������Լ̳и���
class ClassFactory :public Singleton<ClassFactory>
{
public:
	ClassFactory();
	~ClassFactory();

	//���ڴ����࣬���з���void*���ڼ���������
	void* CreateItem(string className);

	//����ע��
	void RegisterItem(const string& className, ItemObject item);

private:
	//����������������ʵ������ָ���map��
	map<string, ItemObjectClass*> objectItems;
};