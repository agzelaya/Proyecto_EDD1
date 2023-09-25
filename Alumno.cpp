#include "Alumno.h"

Alumno::Alumno(std::string nombre, std::string id)
{
	this->id = id;
	this->nombre = nombre;
}

Alumno::~Alumno()
{
	nombre = "";
	id = "";
}

bool Alumno::equals(Object* objeto)
{
	return false;
}

string Alumno::toString()
{
	return "|"+id + " - " + nombre+"|";
}
