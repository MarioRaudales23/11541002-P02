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

bool Tree::insert(Object* padre,Object* nuevo){
	if (raiz == NULL)
	{
		TreeNode* neo = new TreeNode(nuevo);
		raiz = neo;
		return true;
	}else{
		TreeNode* neo = new TreeNode(nuevo);
		TreeNode* pneo = buscar(raiz,padre);
		while(pneo!=NULL){
			if (pneo!=NULL)
			{
				if (pneo->getHijo()==NULL)
				{
					pneo->setHijo(neo);
					return true;
				}else{
					pneo = pneo->getHijo();
					while(pneo->getHermano()!=NULL){
						pneo = pneo->getHermano();
					}
					pneo->setHermano(neo);
					return true;
				}
			}else{
				TreeNode* temp = raiz->getHijo();
				while(temp->getHermano()!=NULL){
					temp=temp->getHermano();
				}
				TreeNode* padrenuev = new TreeNode(padre);
				temp->setHermano(padrenuev);
				temp->getHermano()->setHijo(neo);
				return true;
			}
		}
	}
	return false;
}
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
void Tree::imprimir(int tab,TreeNode* impri){
	if (impri != NULL)
	{
		for (int i = 0; i < tab; ++i)
		{
			cout<<"\t";
		}
		cout<<impri->getData()->toString()<<endl;
		imprimir(tab+1,impri->getHijo());
		imprimir(tab,impri->getHermano());

	}
}

void Tree::imprimirpro(){
	imprimir(0,raiz);
	cout<<endl;
}