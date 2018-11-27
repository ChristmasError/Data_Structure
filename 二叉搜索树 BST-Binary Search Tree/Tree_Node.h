//二叉搜索树只能为空树，或者是具有下列性质的二叉树
//1.若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
//2.若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
//3.它的左、右子树也分别为二叉排序树。
#pragma once
struct TreeNode
{
	int val;
	TreeNode* left = nullptr;
	TreeNode* right=nullptr;
	TreeNode* parent = nullptr;
	TreeNode(int v) :val(v) {  };
};
