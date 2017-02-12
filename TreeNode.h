#pragma once
#include "Object.h"
#include <string>

class TreeNode:public Object{
	private:
		Object* data;
		TreeNode* father;
		TreeNode* hijoizq;
		TreeNode* hermder;
	public:
		TreeNode();
		TreeNode(Object*);
		TreeNode(Object*,TreeNode*);
		TreeNode(Object*,TreeNode*,TreeNode*);
		~TreeNode();
		bool setHijo(TreeNode*);
		bool setHermano(TreeNode*);
		TreeNode* getHijo();
		TreeNode* getHermano();
		TreeNode* getFather();
		void setFather(TreeNode*);
		Object* getData();
		bool setData(Object*);
};