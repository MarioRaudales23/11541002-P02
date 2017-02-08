#pragma once
#include "Object.h"
#include <string>

class TreeNode:public Object{
	private:
		Object* data;
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
		Object* getData();
		bool setData(Object*);
};