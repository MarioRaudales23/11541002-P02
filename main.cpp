#include "Object.h"
#include "Tree.h"
#include "TreeNode.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Tree* leerArchivo();

int main(int argc, char const *argv[])
{
	Tree* nuevo = leerArchivo();
	nuevo->imprimirpro();
	return 0;
}

Tree* leerArchivo(){
	ifstream TreeFile("empleados.txt");
	Tree* llenar = new Tree();
	Object* neo;
	Object* actualtemp;
	Object* before;
	Object* before2;
	stringstream ss;
	char delimiter = ',';
	string linea;
	string temp;
	int tabanter;
	int tabdosanter=0;
	int size =0;
	vector<string> empleados;
	vector<vector<Object*>> temporales;
	vector<Object*> estado;
	while(!TreeFile.eof()){
		getline(TreeFile,linea);
		if(size == 0){
			for (int i = 0; i < linea.size(); ++i){
	    		if(linea[i]==delimiter){
	    			empleados.push_back(temp);
	    			temp = "";
	    		}else{
	    			temp+=linea[i];
	    		}
	    	}
	    	double sueldo = atof(temp.c_str());
	    	Employee* neo = new Employee(sueldo,empleados.at(1),empleados.at(0));
	    	llenar->insert(NULL,neo);
	    	size++;
		}else{
			int tabs = 0;
			while (linea.at(tabs) == '\t') {
					tabs++;
			}
			if (tabs == 1)
			{
				linea = linea.substr(tabs,linea.length());
				for (int i = 0; i < linea.size(); ++i){
	    			if(linea[i]==delimiter){
	    				empleados.push_back(temp);
	    				temp = "";
	    			}else{
	    				temp+=linea[i];
	    			}
	    		}
	    		double sueldo = atof(temp.c_str());
	    		Employee* neo = new Employee(sueldo,empleados.at(1),empleados.at(0));
	    		before=neo;
	    		actualtemp=neo;
	    		tabanter = tabs;
	    		llenar->insert(llenar->getRaiz()->getData(),neo);
			}else{
				linea = linea.substr(tabs,linea.length());
				for (int i = 0; i < linea.size(); ++i){
	    			if(linea[i]==delimiter){
	    				empleados.push_back(temp);
	    				temp = "";
	    			}else{
	    				temp+=linea[i];
	    			}
	    		}
	    		double sueldo = atof(temp.c_str());
	    		Employee* neo = new Employee(sueldo,empleados.at(1),empleados.at(0));
	    		TreeNode* padre;
	    		if (tabanter == tabs)
	    		{
	    			llenar->insert(before,neo);
	    			actualtemp = neo;
	    			tabanter = tabs;
	    		}else if(tabanter > tabs){
	    			llenar->insert(before,neo);
	    			tabanter=tabs;
	    			actualtemp = neo;
	    		}else{
	    			if (tabdosanter==1)
	    			{
	    				padre = llenar->buscar(llenar->getRaiz(),actualtemp);
	    				before = padre->getFather()->getData();
	    				tabdosanter=0;
	    			}
	    			llenar->insert(actualtemp,neo);
	    			tabanter=tabs;
	    			actualtemp = neo;
	    			tabdosanter++;
	    		}
			}
		}
		temp="";
		empleados.clear();
	}
	TreeFile.close();
	return llenar;	
}