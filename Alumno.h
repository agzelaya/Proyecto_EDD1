#pragma once
#include "Object.h"

class Alumno : public Object {
public:
	Alumno(string, string);
	~Alumno();
	virtual bool equals(Object*);
	virtual string toString();
	string GetID();
	string GetName();
	void SetName(string);
protected:
	string nombre, id;
};
