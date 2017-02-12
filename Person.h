#pragma once
#include "Object.h"
#include <string>
using std::string;
class Person:public Object{
	protected:
		string name;
	public:
		Person(string);
		string getName();
		virtual ~Person();
		virtual string toString()const;
		virtual bool equals(Object*)const;
};