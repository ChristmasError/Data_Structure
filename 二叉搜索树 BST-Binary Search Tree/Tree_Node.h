//����������ֻ��Ϊ�����������Ǿ����������ʵĶ�����
//1.���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� 
//2.���������������գ��������������н���ֵ���������ĸ�����ֵ��
//3.������������Ҳ�ֱ�Ϊ������������
#pragma once
struct TreeNode
{
	int val;
	TreeNode* left = nullptr;
	TreeNode* right=nullptr;
	TreeNode* parent = nullptr;
	TreeNode(int v) :val(v) {  };
};
