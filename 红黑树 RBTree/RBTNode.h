//1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
//2. ���ڵ��Ǻ�ɫ��
//3. ���һ�����ڵ��Ǻ�ɫ�ģ�����������Ҷ�ӽ���Ǻ�ɫ��(û�����������ĺ�ɫ���)
//4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ���(ÿ��·���Ϻ�ɫ�����������)
//5.����Ҷ�ӽ��Ϊ�ڣ���ƽʱ��ͬ�������Ҷ�ӽ����ָ�յ�Ҷ�ӽ�㣬��ΪNULL��
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