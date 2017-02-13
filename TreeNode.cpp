#include "TreeNode.h"
#include "Object.h"
#include <string>

TreeNode::TreeNode(){
	data = NULL;
	hijoizq = NULL;
	hermder = NULL;
}

TreeNode::TreeNode(Object* data,int tabs):data(data),tabs(tabs){
	hijoizq = NULL;
	hermder = NULL;
}

TreeNode::TreeNode(Object* data,TreeNode* hermder,int tabs):data(data),hermder(hermder),tabs(tabs){
	hijoizq=NULL;
}
TreeNode::TreeNode(Object* data,TreeNode* hijoizq,TreeNode* hermder,int tabs):data(data),hermder(hermder),hijoizq(hijoizq),tabs(tabs){

}

TreeNode::~TreeNode(){
	delete data;
	delete hermder;
	delete hijoizq;
}

bool TreeNode::setHijo(TreeNode* hijo){
	hijoizq = hijo;
	return true;
}

bool TreeNode::setHermano(TreeNode* herm){
	hermder = herm;
	return true;
}
//devuelve  el hijo izquierdo
TreeNode* TreeNode::getHijo(){
	return hijoizq;
}
//Devuelve el hermano derecho
TreeNode* TreeNode::getHermano(){
	return hermder;
}
//Devuelve la data
Object* TreeNode::getData(){
	return data;
}
//asigna nueva data
bool TreeNode::setData(Object* ndata){
	data = ndata;
	return true;
}
///Regresa el nodo padre
TreeNode* TreeNode::getFather(){
	return father;
}
//Asigna un nodo como padre
void TreeNode::setFather(TreeNode* nfather){
	father = nfather;
}
int TreeNode::getTabs(){
	return tabs;
}