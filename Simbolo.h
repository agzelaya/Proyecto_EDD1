#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Simbolo : public Object{
public:
	char data;
	Simbolo(char);
	~Simbolo();

	virtual bool equals(Object*);
	virtual string toString();
};