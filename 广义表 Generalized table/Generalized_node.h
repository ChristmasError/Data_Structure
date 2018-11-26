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