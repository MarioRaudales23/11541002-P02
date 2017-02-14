#include "Tree.h"
#include "Object.h"
#include "Employee.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

Tree::Tree(){
	raiz = NULL;
}

Tree::Tree(TreeNode* raiz):raiz(raiz){

}

Tree::~Tree(){
	delete raiz;
}
TreeNode* Tree::getRaiz(){
	return raiz;
}
//Metodo insert
bool Tree::insert(Object* padre,Object* nuevo,int tabs){
	//inserta cuando no hay raiz
	if (raiz == NULL)
	{
		TreeNode* neo = new TreeNode(nuevo,tabs);
		raiz = neo;
		return true;
	}else{
		//Se crea el nuevo nodo
		TreeNode* neo = new TreeNode(nuevo,tabs);
		TreeNode* pneo = buscar(raiz,padre);//se busca el nodo que sera padre del nuevo
		while(pneo!=NULL){
			if (pneo!=NULL)
			{
				//Si el padre existe se evalua si ya tiene hijo, si no tiene se asigna como primer hijo
				if (pneo->getHijo()==NULL)
				{
					pneo->setHijo(neo);
					neo->setFather(pneo);
					return true;
				}else{
					//Sino se crea un temporal hasta llegar al hijo mas a la derecha y se asigna el nuevo nodo
					neo->setFather(pneo);
					pneo = pneo->getHijo();
					while(pneo->getHermano()!=NULL){
						pneo = pneo->getHermano();
					}
					pneo->setHermano(neo);
					return true;
				}
			}else{
				//Si no existe el padre se crea el nodo padre y luego si asigna el nuevo hijo
				TreeNode* temp = raiz->getHijo();
				while(temp->getHermano()!=NULL){
					temp=temp->getHermano();
				}
				TreeNode* padrenuev = new TreeNode(padre,1);
				temp->setHermano(padrenuev);
				temp->getHermano()->setHijo(neo);
				return true;
			}
		}
	}
	return false;
}
//Metodo que busca desde un nodo y revisa sus hijos y hermanos para ver si se encuentra
TreeNode* Tree::buscar(TreeNode* nodo,Object* busca){
	if (nodo != NULL)
	{
		if (nodo->getData()==busca)
		{
			return nodo;
		}else{
			while(nodo->getHermano()!=NULL){
				return buscar(nodo->getHermano(),busca);
			}
			return buscar(nodo->getHijo(),busca);
		}
	}
}
//Metodo que se llama dentro de imprimirpro para imprimir el arbol
void Tree::imprimir(int tab,TreeNode* impri){
	if (impri != NULL)
	{
		for (int i = 0; i < tab; ++i)
		{
			cout<<"\t";
		}
		cout<<"|->"<<impri->getData()->toString()<<endl;
		imprimir(tab+1,impri->getHijo());
		imprimir(tab,impri->getHermano());

	}
}
//Imprime el arbol y asigna tabs
void Tree::imprimirpro(){
	imprimir(0,raiz);
	cout<<endl;
}
//Metodo clear limpia el arbol
void Tree::clear(){
	delete raiz;
	raiz = NULL;
}