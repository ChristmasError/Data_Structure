//��Ҳ�����ȶ��У�����һ���������ȫ���������ݽ�
//�ѷ�Ϊ���֣����ѣ���С�ѡ�
//���ѣ����ڵ�������������ӽڵ����ȫ������
//��С�ѣ����ڵ�С�����������ӽڵ����ȫ������
//�ѿ������������洢��
//a[i]������ڵ㣬a[2 * i]���������ĸ��ڵ� ; a[2 * i + 1]���������ĸ��ڵ㡣i��1��ʼ!!

#include<iostream>
#include"Myheap.h"

using namespace std;
int main() 
{
	int minheapbuffer[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int maxheapbuffer[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Myheap<int>minheap(minheapbuffer,10,MINHEAP);
	Myheap<int>maxheap(maxheapbuffer, 10,MAXHEAP);
	//С����
	minheap.print();
	minheap.pop(1);
	minheap.print();
	minheap.push(1);
	minheap.print();
	cout << endl;
	//�󶥶�
	maxheap.print();
	maxheap.pop(0);
	maxheap.print();
	maxheap.push(10);
	maxheap.print();
	system("pause");
	return 0;
}