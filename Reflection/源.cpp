#include <iostream>
#include <vector>
#include "ClassFactory.h"
#include "FileItem.h"
#include "ConsoleItem.h"
#include "REGISTERCLASS.h"

//进行注册，注册之后才可以使用
//不注册不会动态生成需要的类的实例
REGISTCLASS(FileItem)
REGISTCLASS(ConsoleItem)


using namespace std;

//该反射机制每一次CreateItem就会创建新的类实例，
//所有都使用完后，再手动调用delete来释放掉该类
//所有实例。

int main()
{
	FileItem* fileItem = static_cast<FileItem*>(ClassFactory::instance()->CreateItem("FileItem"));
	fileItem->Print();
	delete fileItem;

	ConsoleItem* consoleItem = static_cast<ConsoleItem*>(ClassFactory::instance()->CreateItem("ConsoleItem"));
	consoleItem->Print();
	delete consoleItem;


	system("pause");
	return 0;
}