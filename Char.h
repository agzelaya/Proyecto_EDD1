#ifndef CHAR_H
#define CHAR_H

#include "Object.h"

class Char : public Object
{
	public:
		Char();
		~Char();
		virtual bool equals(Object*);
		//virtual string toString();
	protected:
};

#endif