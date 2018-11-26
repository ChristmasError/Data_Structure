//广义表是一种非线性的数据结构，是线性表的一种推广
//广义表中放松对表元素的原子限制(表中有表)
//其中元素为原子或者是一个广义表
#include<iostream>
#include<assert.h>
enum Nodetype{
	HEAD,
	VALUE,
	SUB,
};
struct Generalized_node {
	Nodetype _type;
	Generalized_node *_next;

	union {
		char _value;
		Generalized_node *_sub;
	};
	Generalized_node(Nodetype type, const char value=' ') :_type(type),_next(NULL){
		if (type==VALUE||type==HEAD) {
			_value = value;
		}
		else if (_type == SUB) {
			_sub = NULL;
		}
		else 
			assert(false);
	}
};