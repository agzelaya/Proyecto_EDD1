#pragma once
#include "Object.h"

class Alumno : public Object {
public:
	Alumno(string, string);
	~Alumno();
	virtual bool equals(Object*);
	virtual string toString();
protected:
	string nombre, id;
};
