#pragma once
#include "Object.h"
#include "TreeNode.h"
#include <string>

class Tree:public Object{
	private:
		TreeNode* raiz;
		void imprimir(int,TreeNode*);
	public:
		Tree();
		Tree(TreeNode*);
		~Tree();
		bool insert(Object*,Object*);
		TreeNode* buscar(TreeNode*,Object*);
		int profundidad(TreeNode*);
		TreeNode* getRaiz();
		void imprimirpro();
};