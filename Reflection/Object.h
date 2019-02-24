#pragma once
#include <string>
#include <iostream>
using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	const string & GetClassName() const { return className; }

protected:
	string className;

};