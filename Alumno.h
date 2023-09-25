#ifndef ALUMNO_H
#define AlUMNO_H
#include "iostream"
#include "Object.h"

class Alumno : public Object
{
public:
	Alumno(string nombre, string id);
	~Alumno();
	virtual bool equals(Object*);
	virtual string toString();
protected:
	string nombre, id; 

};
#endif

