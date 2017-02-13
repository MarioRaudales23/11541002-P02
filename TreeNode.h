#pragma once
#include "Object.h"
#include <string>

class TreeNode:public Object{
	private:
		Object* data;
		int tabs;
		TreeNode* father;
		TreeNode* hijoizq;
		TreeNode* hermder;
	public:
		TreeNode();
		TreeNode(Object*,int);
		TreeNode(Object*,TreeNode*,int);
		TreeNode(Object*,TreeNode*,TreeNode*,int);
		~TreeNode();
		bool setHijo(TreeNode*);
		bool setHermano(TreeNode*);
		TreeNode* getHijo();
		TreeNode* getHermano();
		TreeNode* getFather();
		void setFather(TreeNode*);
		Object* getData();
		bool setData(Object*);
		int getTabs();
};