//堆也叫优先队列，堆是一种特殊的完全二叉树数据结
//堆分为两种，最大堆，最小堆。
//最大堆：根节点大于左右两个子节点的完全二叉树
//最小堆：根节点小于左右两个子节点的完全二叉树
//堆可以用数组来存储，
//a[i]处存根节点，a[2 * i]存左子树的根节点 ; a[2 * i + 1]存右子树的根节点。i从1开始!!

#include<iostream>
#include"Myheap.h"

using namespace std;
int main() 
{
	int minheapbuffer[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int maxheapbuffer[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Myheap<int>minheap(minheapbuffer,10,MINHEAP);
	Myheap<int>maxheap(maxheapbuffer, 10,MAXHEAP);
	//小顶堆
	minheap.print();
	minheap.pop(1);
	minheap.print();
	minheap.push(1);
	minheap.print();
	cout << endl;
	//大顶堆
	maxheap.print();
	maxheap.pop(0);
	maxheap.print();
	maxheap.push(10);
	maxheap.print();
	system("pause");
	return 0;
}