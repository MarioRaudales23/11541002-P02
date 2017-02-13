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
	int opcion = 0;
	Tree* arbol = new Tree();
	while(opcion != 3){
		cout<<"1-Llenar Arbol\n2-Imprimir Arbol\n3-Salir\n.....";
		cin>>opcion;
		switch(opcion){
			case 1:{
				arbol->clear();
				arbol = leerArchivo();
				cout<<"Arbol acualizado"<<endl;
				break;
			}
			case 2:{
				arbol->imprimirpro();
				break;
			}
			case 3:{
				break;
			}
			default:{
				cout<<"Opcion No Valida"<<endl;
			}
		}
	}
	return 0;
}
//Metodo de lectura de archivo
Tree* leerArchivo(){
	ifstream TreeFile("empleados.txt");
	Tree* llenar = new Tree();//Se crea el arbol
	Object* neo;
	stringstream ss;
	char delimiter = ',';
	string linea;
	string temp;
	int tabanter;//Temporales de tabs
	int tabdosanter=0;
	int size =0;
	vector<string> empleados;
	vector<Object*> temporales;
	while(!TreeFile.eof()){
		getline(TreeFile,linea);
		if(size == 0){
			// Primera parte se obtiene la primera linea la cual seria el nodo raiz
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
	    	llenar->insert(NULL,neo,0);
	    	temporales.push_back(neo);
	    	//Se inserta al arbol la nueva raiz
	    	size++;
		}else{
			int tabs = 0;
			//while que cuenta los tabs de la linea
			while (linea.at(tabs) == '\t') {
					tabs++;
			}
			if (tabs == 1)
			{
				//Se el tab es uno se hace un substring y se asigna como hijo de la raiz
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
	    		tabanter = tabs;//Se guarda la cantidad de tabs
	    		llenar->insert(llenar->getRaiz()->getData(),neo,1);
	    		temporales.push_back(neo);//mete elemento al vector
			}else{
				//Se hace un substring de la linea con los tabs
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
	    		TreeNode* padre = llenar->getRaiz();//Se tiene un nodo temporal de padres para mantener refencia al nodo anterior
	    		bool termina = true;
	    		//While donde se busca el padre mas cercano
	    		while(termina){
	    			padre = llenar->buscar(llenar->getRaiz(),temporales.back());
	    			if (padre->getTabs() == tabs-1)
	    			{
	    				//si el padre tiene un tab menos que el nuevo hijo se asigna
	    				termina = false;
	    			}else{
	    				//sino se borra del vector de objetos
	    				temporales.pop_back();
	    			}
	    		}
	    		//se inserta el nuevo hijo
	    		llenar->insert(padre->getData(),neo,tabs);
	    		temporales.push_back(neo);
			}
		}
		temp="";
		empleados.clear();
	}
	TreeFile.close();
	return llenar;	
}