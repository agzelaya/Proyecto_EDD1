#include "Simbolo.h"

Simbolo::Simbolo(char data){
	this->data = data;
}

Simbolo::~Simbolo(){
	data = NULL;
}

bool Simbolo::equals(Object* objeto){
	Simbolo* temp = dynamic_cast<Simbolo*>(objeto);
	if (this->data == temp->data)
		return true;
	else
		return false;
}

string Simbolo::toString(){
	string text = "";
	text += data;
	return text;
}