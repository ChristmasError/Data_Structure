#include"RBTree.h"
#include<iostream>
#include<vector>
using namespace std;
int main() 
{
	vector<int> nums{ 10,40,30,60,90,70,20,50,80,100};
	RBTree<int> tree;
	for (auto num : nums)
		tree.insert(num);
	tree.preOrder();
	cout << endl;
	tree.inOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	cout << "查找key为30的结点:\n";
	cout << endl<<tree.search(30)->key<<endl;
	cout << "删除key为100的结点\n";
	tree.remove(100);
	tree.preOrder();
	cout << endl;
	cout << "\n红黑树详细信息：\n";
	tree.print();
	cin.get();
	return 0;
}
