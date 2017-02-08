#include "Object.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	Tree* nuevo = new Tree();
	Employee* hola = new Employee(1000.0,"Hola",15);
	Employee* Mario = new Employee(100.0,"Mario",15);
	Employee* jefe = new Employee(1050.0,"Daniel",15);
	Employee* Hrai = new Employee(1056.0,"Raiz",15);
	Employee* HHrai = new Employee(1089.0,"Hrai",15);
		Employee* sd = new Employee(1889.0,"sd",15);
		Employee* re = new Employee(189.0,"re",15);
			Employee* po = new Employee(189.0,"po",15);

	nuevo->insert(NULL,jefe);
	nuevo->insert(jefe,Mario);
	nuevo->insert(Mario,hola);
	nuevo->insert(Mario,po);
	nuevo->insert(jefe,Hrai);
	nuevo->insert(Hrai,re);
	nuevo->insert(jefe,HHrai);
	nuevo->insert(HHrai,sd);
	nuevo->imprimirpro();
	return 0;
}