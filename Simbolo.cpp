#include "Simbolo.h"

Simbolo::Simbolo(char data){
	this->data = data;
}

Simbolo::~Simbolo(){
	delete data;
}

bool Simbolo::equals(Object* objeto){
	Simbolo* temp = dynamyc_cast<Simbolo*>(objeto);
	if (this->data == temp->data)
		return true;
	else
		return false;
}

string Simbolo::toString(){
	string text = data;
	return text;
}