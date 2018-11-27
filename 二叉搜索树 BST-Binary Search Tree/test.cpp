#include"Binary_Search_Tree.h"
#include<iostream>
using namespace std;
int main()
{
	vector<int> vec{8,3,10,1,6,4,7,14,13 };
	BST bstree(vec);
	bstree.inorderprint();
	cout<<"\n";
	bstree.preorderprint();
	cout << "\n";
	bstree.postorderprint();
	cout << "\ndelete node key = 6\n";
	bstree.remove(6);
	bstree.preorderprint();
	cout << "\ndelete node key = 8\n";
	bstree.remove(8);
	bstree.preorderprint();
	cout << "\ndelete node key = 13\n";
	bstree.remove(13);
	bstree.preorderprint();
	cout << "\n";
	system("pause");
	return 0;
}