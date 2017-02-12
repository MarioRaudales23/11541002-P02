#include "TreeNode.h"
#include "Object.h"
#include <string>

TreeNode::TreeNode(){
	data = NULL;
	hijoizq = NULL;
	hermder = NULL;
}

TreeNode::TreeNode(Object* data):data(data){
	hijoizq = NULL;
	hermder = NULL;
}

TreeNode::TreeNode(Object* data,TreeNode* hermder):data(data),hermder(hermder){
	hijoizq=NULL;
}
TreeNode::TreeNode(Object* data,TreeNode* hijoizq,TreeNode* hermder):data(data),hermder(hermder),hijoizq(hijoizq){

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
}

TreeNode* TreeNode::getHijo(){
	return hijoizq;
}
TreeNode* TreeNode::getHermano(){
	return hermder;
}

Object* TreeNode::getData(){
	return data;
}
bool TreeNode::setData(Object* ndata){
	data = ndata;
}

TreeNode* TreeNode::getFather(){
	return father;
}

void TreeNode::setFather(TreeNode* nfather){
	father = nfather;
}