//1. 每个结点不是红色就是黑色
//2. 根节点是黑色的
//3. 如果一个根节点是红色的，则它的两个叶子结点是黑色的(没有两个连续的红色结点)
//4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点(每条路径上黑色结点的数量相等)
//5.所有叶子结点为黑（与平时不同，这里的叶子结点是指空的叶子结点，即为NULL）
enum RBTColor { Black, Red };

template<class KeyType>
struct  RBTNode
{
	KeyType key;
	RBTColor color;
	RBTNode<KeyType> * left;
	RBTNode<KeyType> * right;
	RBTNode<KeyType> * parent;
	RBTNode(KeyType k, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r) :
		key(k), color(c), parent(p), left(l), right(r) { };
};