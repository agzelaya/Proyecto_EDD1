#include "Simbolo.h"

Simbolo::Simbolo(std::string nombre, std::string id){
	this->id = id;
	this->nombre = nombre;
}

Simbolo::~Simbolo(){
	nombre = "";
	id = "";
}

bool Simbolo::equals(Object* objeto){
	return false;
}

string Simbolo::toString(){
	return data;
}