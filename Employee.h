#pragma once
#include "Person.h"
#include <string>

class Employee:public Person{
	private:
		double sueldo;
		string cargo;
	public:
		Employee(double,string,string);
		virtual~Employee();
		virtual string toString()const;
		double getSueldo();
		bool inflacion(double aumento);	
		virtual bool equals(Object*)const;
};