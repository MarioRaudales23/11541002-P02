#pragma once
#include "Object.h"
#include <string>
using std::string;
class Person:public Object{
	protected:
		string name;
		int age;
	public:
		Person(string,int);
		string getName();
		virtual ~Person();
		virtual string toString()const;
		virtual bool equals(Object*)const;
};