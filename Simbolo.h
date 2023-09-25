#pragma once
#include "Char.h"
#include "Object.h"
#include <iostream>

class Simbolo : public Object{
public:
	Char* data;
	Simbolo(Char* data);
	~Simbolo();

	virtual bool equals(Object*);
	virtual string toString();
};