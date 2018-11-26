#include"Generalized_node.h"
/*
enum Nodetype{
HEAD,
VALUE,
SUB,
};
*/
class Generalized_list {
private:
	typedef Generalized_node Node;
	Node* _head;

	Node* createlist(const char *&str);
	//判断传入数据中字符是否有效
	inline bool useful(const char s) {
		if ((s >= '0'&&s <= '9')
			|| (s >= 'a'&&s <= 'z')
			|| (s >= 'A'&&s <= 'Z')) {
			return true;
		}
		return false;
	}
	void _print(Node * node);
	void _destory(Node *_head);
	size_t _depth(Node* _head);
public:
	Generalized_list():_head(NULL) {};
	Generalized_list(const char* str) {
		_head = createlist(str);
	};
	~Generalized_list()
	{
		_destory(_head);
	}
	//递归打印广义表
	void print() {
		_print(_head);
	}
	size_t depth()
	{
		size_t dep=_depth(_head);
		return dep;
	}

};
//构造函数
Generalized_node* Generalized_list::createlist(const char *&str) {
	assert(*str == '(');
	Node* head = new Node(HEAD, *str);
	Node* prev = head;
	head->_type = HEAD;
	++str;
	while (*str)
	{
		if (useful(*str))
		{
			Node* node = new Node(VALUE, *str);
			prev->_next = node;
			prev = prev->_next;
			++str;
		}
		else if (*str == '(') {
			Node *node = new Node(SUB, *str);
			prev->_next = node;
			prev = prev->_next;
			node->_sub = createlist(str);
			++str;
		}
		else if (*str == ')') {
			prev->_next = NULL;
			str++;
			return head;
		}
		else
		{
			++str;
		}
	}
	return head;
}
//打印广义表
void Generalized_list::_print(Node * node) {
	assert(node);
	Node *cur = node;
	while (cur) {
		if (cur->_type == VALUE)
		{
			std::cout << cur->_value;
			if (cur->_next != NULL)
				std::cout << ',';
			cur = cur->_next;
		}
		else if (cur->_type == SUB)
		{
			_print(cur->_sub);
			if (cur->_next != NULL)
				std::cout << ',';
			cur = cur->_next;
		}
		else
		{
			std::cout << '(';
			cur = cur->_next;
		}
	}
	std::cout << ')';
}
//销毁广义表
void Generalized_list::_destory(Node *_head)
{
	Node* cur = _head;
	while (cur)
	{
		Node* del = cur;
		if (cur->_type == SUB)
		{
			_destory(cur->_sub);
		}
		cur = cur->_next;
		delete[] del;
	}
}
//广义表深度
size_t Generalized_list::_depth(Node* _head)
{
	Node* cur = _head;
	size_t maxdep = 1;
	while (cur)
	{
		size_t dep = 1;
		if (cur->_type == SUB)
		{
			dep+=_depth(cur->_sub);
			if (dep > maxdep)
				maxdep = dep;
		}
		cur = cur->_next;
	}
	return maxdep;
}
