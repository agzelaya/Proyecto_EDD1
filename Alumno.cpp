#include "Alumno.h"

Alumno::Alumno(string nombre, string id) {
	this->id = id;
	this->nombre = nombre;
}

bool Alumno::equals(Object* objeto) {
	Alumno* otro = dynamic_cast<Alumno*>(objeto);
	return (this->id == otro->id);
}

string Alumno::toString() {
	return id + " : " + nombre + " ";
}


Alumno::~Alumno() {
	nombre = "";
	id = "";
}