#include <iostream>
#include <vector>
#include "ClassFactory.h"
#include "FileItem.h"
#include "ConsoleItem.h"
#include "REGISTERCLASS.h"

//����ע�ᣬע��֮��ſ���ʹ��
//��ע�᲻�ᶯ̬������Ҫ�����ʵ��
REGISTCLASS(FileItem)
REGISTCLASS(ConsoleItem)


using namespace std;

//�÷������ÿһ��CreateItem�ͻᴴ���µ���ʵ����
//���ж�ʹ��������ֶ�����delete���ͷŵ�����
//����ʵ����

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