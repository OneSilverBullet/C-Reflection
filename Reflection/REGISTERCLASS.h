#pragma once

//�ú궨��ʵ��һ����̬��Ĵ���
// 1. ## �ϲ������������������ߵ��ַ��ϲ���һ���µı�ʶ�����ϲ������
//��ʶ�������ַ�����
// 2. # ��������������ʵ�ε��ַ����У�������ʵ�δ����ֵ)ת��Ϊһ����
//����������ת����ʹһ���ַ���

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

//����һ������