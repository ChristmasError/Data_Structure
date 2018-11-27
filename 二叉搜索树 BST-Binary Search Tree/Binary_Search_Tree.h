#pragma once
#include"Tree_Node.h"
#include<vector>
#include<iostream>
class BST 
{
private:
	TreeNode* _root=nullptr;
	//typedef TreeNode Node;

	void _createBST( std::vector<int>vec);
	TreeNode* _find(int k);
	void _insertnode(int a);
	void _removenode( int a);
	void _inorderprint(TreeNode * node);
	void _preorderprint(TreeNode * node);
	void _postorderprint(TreeNode * node);
	//void _destory();
	TreeNode* Predecessor(int a);//寻找前驱节点
	TreeNode* Successor(int a);//寻找后继节点
	
public:
	BST() {};
	BST(std::vector<int>vec) { _createBST( vec); };
	
	//~BST() { _destory(); };
	void inorderprint() { _inorderprint(_root); };
	void preorderprint() { _preorderprint(_root); };
	void postorderprint() { _postorderprint(_root); };
	void insert(int a) { _insertnode(a); };
	void remove(int a) { _removenode( a); };
};
//vector<int>构造BST
void BST::_createBST(std::vector<int>vec)
{
	for (int val : vec)
		_insertnode(val);
}
//查找key的结点
TreeNode* BST::_find(int key)
{
	TreeNode* cur=_root;
	while (cur->val!=key && cur!=nullptr)
	{
		if (key > cur->val)
			cur = cur->right;
		else
			cur = cur->left;
	}
	if(cur!=nullptr)
		return cur;
	else
	{
		std::cout << "BST do not have this node!\n ";
		return nullptr;
	}
}
//插入结点
void BST::_insertnode(int a)
{
	TreeNode* node = new TreeNode(a);
	if (_root == nullptr)
	{
		_root = node;
		return;
	}
	else
	{
		TreeNode* cur = _root;
		while (true)
		{
			//新结点的值大于当前结点cur
			if (node->val > cur->val)
			{
				if(cur->right!=nullptr)
					cur = cur->right;
				else
				{
					cur->right = node;
					node->parent = cur;
					return;
				}
			}
			//新结点的值小于当前结点cur
			else
			{
				if (cur->left!= nullptr)
					cur = cur->left;
				else
				{
					cur->left = node;
					node->parent = cur;
					return;
				}
			}
		}
	}
}
//寻找前驱节点
TreeNode* BST::Predecessor(int a)
{
	TreeNode* cur = _find(a);
	if (cur->left != nullptr)
	{
		cur = cur->left;
		while (cur->right != nullptr)
			cur = cur->right;
		return cur;
	}
	while (cur->parent != nullptr && cur->parent->left == cur)
		cur = cur->parent;
	return cur->parent;
}

//寻找后继节点
TreeNode* BST::Successor(int a)
{
	TreeNode* cur = _find(a);
	//cur右结点不为空，则cur后继结点为右子树最靠左的结点
	if (cur->right != nullptr)
	{
		cur = cur->right;
		//存在左子树
		while (cur->left != nullptr)
			cur = cur->left;
		return cur;
	}
	//cur的右结点不存在左子树，向上找父节点第一个有右孩子且不存在cur的祖先
	while (cur->parent != nullptr && cur->parent->right != cur)
		cur = cur->parent;
	return cur->parent;
}
//删除值为a的结点
void BST::_removenode(int a)
{
	if (_root == nullptr)
		throw("error : it's an empty BSTtree!\n");
	TreeNode* dnode = _find(a);//找出需要删除的结点dnode
	TreeNode* temp;//temp为取代dnode的结点
	if (dnode->left == nullptr && dnode->right == nullptr)//情况1，删除节点为子节点
		temp = nullptr;
	else if (dnode->left == nullptr || dnode->right == nullptr)//情况2，删除节点只有左或者右子树
	{
		temp = (dnode->left == nullptr) ? dnode->right : dnode->left;
		temp->parent = dnode->parent;
	}
	else
	{
		temp = Successor(a);
		TreeNode* temp_right;
		if (temp->right == nullptr)
			temp_right = nullptr;
		else
		{
			temp_right = temp->right;
			temp_right->parent = temp->parent;
		}

		if (temp->parent->right == temp)
			temp->parent->right = temp_right;
		else
			temp->parent->left = temp_right;

		//temp取代dnode，注意dnode为根节点情况
		if (dnode->parent == nullptr)
		{
			temp->right = dnode->right;
			temp->left = dnode->left;
			_root = temp;
			delete dnode;
		}
		else if (dnode->parent->right == dnode)
		{
			dnode->parent->right = temp;
			temp->parent = dnode->parent;
			temp->right = dnode->right;
			temp->left = dnode->left;
			delete dnode;
		}
		else
		{
			dnode->parent->left = temp;
			temp->parent = dnode->parent;
			temp->right = dnode->right;
			temp->left = dnode->left;
			delete dnode;
		}

		//或者不取代dnode，将temp和dnode进行数据交换
		//dnode->val = temp->val;
		//delete temp;
		return;
	}
	//情况1,2余下操作，注意删除节点为根节点的特殊情况
	if (dnode->parent != nullptr)
	{
		if (dnode->parent->right == dnode)
			dnode->parent->right = temp;
		else
			dnode->parent->left = temp;
	}
	else
		_root = temp;
	delete dnode;
	return;
}
//前中后序打印BST
void BST::_inorderprint(TreeNode * node)
{
	if (node == nullptr)
		return;
	std:: cout << node->val << ' ';
	_inorderprint(node->left);
	_inorderprint(node->right);
}
void BST::_preorderprint(TreeNode * node)
{
	if (node == nullptr)
		return;
	_preorderprint(node->left);
	std::cout << node->val << ' ';
	_preorderprint(node->right);
}
void BST::_postorderprint(TreeNode * node)
{
	if (node == nullptr)
		return;
	_postorderprint(node->left);
	_postorderprint(node->right);
	std::cout << node->val<<' ';
}
