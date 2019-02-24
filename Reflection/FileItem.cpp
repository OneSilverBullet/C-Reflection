#include "FileItem.h"

FileItem::FileItem():Item()
{
	className = "FileItem";
}

FileItem::~FileItem()
{
}

void FileItem::Print()
{
	cout << className << endl;
}
