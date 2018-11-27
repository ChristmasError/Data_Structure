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
	TreeNode* Predecessor(int a);//Ѱ��ǰ���ڵ�
	TreeNode* Successor(int a);//Ѱ�Һ�̽ڵ�
	
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
//vector<int>����BST
void BST::_createBST(std::vector<int>vec)
{
	for (int val : vec)
		_insertnode(val);
}
//����key�Ľ��
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
//������
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
			//�½���ֵ���ڵ�ǰ���cur
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
			//�½���ֵС�ڵ�ǰ���cur
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
//Ѱ��ǰ���ڵ�
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

//Ѱ�Һ�̽ڵ�
TreeNode* BST::Successor(int a)
{
	TreeNode* cur = _find(a);
	//cur�ҽ�㲻Ϊ�գ���cur��̽��Ϊ���������Ľ��
	if (cur->right != nullptr)
	{
		cur = cur->right;
		//����������
		while (cur->left != nullptr)
			cur = cur->left;
		return cur;
	}
	//cur���ҽ�㲻�����������������Ҹ��ڵ��һ�����Һ����Ҳ�����cur������
	while (cur->parent != nullptr && cur->parent->right != cur)
		cur = cur->parent;
	return cur->parent;
}
//ɾ��ֵΪa�Ľ��
void BST::_removenode(int a)
{
	if (_root == nullptr)
		throw("error : it's an empty BSTtree!\n");
	TreeNode* dnode = _find(a);//�ҳ���Ҫɾ���Ľ��dnode
	TreeNode* temp;//tempΪȡ��dnode�Ľ��
	if (dnode->left == nullptr && dnode->right == nullptr)//���1��ɾ���ڵ�Ϊ�ӽڵ�
		temp = nullptr;
	else if (dnode->left == nullptr || dnode->right == nullptr)//���2��ɾ���ڵ�ֻ�������������
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

		//tempȡ��dnode��ע��dnodeΪ���ڵ����
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

		//���߲�ȡ��dnode����temp��dnode�������ݽ���
		//dnode->val = temp->val;
		//delete temp;
		return;
	}
	//���1,2���²�����ע��ɾ���ڵ�Ϊ���ڵ���������
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
//ǰ�к����ӡBST
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
