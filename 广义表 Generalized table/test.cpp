#include"Generalized_list.h"
using namespace std;
int main() {
	const char *test = "(a,b,(c,d),(e,(f),h))";
	Generalized_list gl1(test);
	gl1.print();
	cout << "\n该表深度为" << gl1.depth();
	cout << endl;
	system("pause");
	return 0;
}