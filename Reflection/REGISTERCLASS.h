#pragma once

//该宏定义实现一个动态类的创建
// 1. ## 合并操作符，将操作两边的字符合并成一个新的标识符，合并后的新
//标识符不是字符串。
// 2. # 构串操作符，将实参的字符序列（而不是实参代表的值)转换为一个字
//符串常量，转换后使一个字符串

#define REGISTCLASS(className)\
class className##Helper\
{\
public:\
	className##Helper()\
	{\
		ClassFactory::instance()->RegisterItem(#className, className##Helper::\
		CreateObjFunc);\
    }\
	static void* CreateObjFunc()\
	{\
		return new className;\
    }\
};\
className##Helper className##helper;

//定义一个变量