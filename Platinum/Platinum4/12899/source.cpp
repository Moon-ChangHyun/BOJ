// 776ms, 49028KB

#include<iostream>
#include<random>

using namespace std;

random_device rd;

template<typename T>
struct node {
	T key;
	int priority, size;
	node<T> *left, *right;

	node(const T& _key) : key(_key), priority(rd()), size(1), left(nullptr), right(nullptr) {}
	void setLeft(node<T> *_left)
	{
		left = _left;
		calcSize();
	}
	void setRight(node<T> *_right)
	{
		right = _right;
		calcSize();
	}
	void calcSize()
	{
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

template<typename T>
class treap {
	typedef pair<node<T>*, node<T>*> nodePair;
	node<T>* root = nullptr;
	nodePair split(node<T> *parent, T key) 
	{
		if (parent == nullptr) return nodePair{ nullptr, nullptr };
		if (parent->key < key)
		{
			nodePair rs = split(parent->right, key);
			parent->setRight(rs.first);
			return nodePair(parent, rs.second);
		}
		nodePair ls = split(parent->left, key);
		parent->setLeft(ls.second);
		return nodePair(ls.first, parent);
	}
	node<T>* insert(node<T> *parent, node<T> *newNode)
	{
		if (parent == nullptr) return newNode;
		if (parent->priority < newNode->priority)
		{
			nodePair splitted = split(parent, newNode->key);
			newNode->setLeft(splitted.first);
			newNode->setRight(splitted.second);
			return newNode;
		}
		else if (newNode->key < parent->key)
			parent->setLeft(insert(parent->left, newNode));
		else
			parent->setRight(insert(parent->right, newNode));
		return parent;
	}
	// a트립 최대값 < b트립 최소값
	node<T>* merge(node<T> *a, node<T> *b)
	{
		if (a == nullptr) return b;
		if (b == nullptr) return a;
		if (a->priority < b->priority)
		{
			b->setLeft(merge(a, b->left));
			return b;
		}
		a->setRight(merge(a->right, b));
		return a;
	}
	node<T>* erase(node<T> *parent, T key)
	{
		if (parent == nullptr) return parent;
		if (parent->key == key) {
			auto ret = merge(parent->left, parent->right);
			delete parent;
			return ret;
		}
		if (key < parent->key)
			parent->setLeft(erase(parent->left, key));
		else
			parent->setRight(erase(parent->right, key));
		return parent;
	}
	void eraseTree(node<T> *parent)
	{
		if (parent == nullptr) return;
		eraseTree(parent->left);
		parent->left = nullptr;
		eraseTree(parent->right);
		parent->right = nullptr;
		delete parent;
	}
	node<T>* findKth(node<T> *parent, int k)
	{
		int leftSize = 0;
		if (parent->left) leftSize = parent->left->size;
		if (k <= leftSize) return findKth(parent->left, k);
		if (k == leftSize + 1) return parent;
		return findKth(parent->right, k - leftSize - 1);
	}
public:
	void insert(T val)
	{
		root = insert(root, new node(val));
	}
	void erase(T val)
	{
		root = erase(root, val);
	}
	T findKthAndErase(int k)
	{
		node<T>* res = findKth(root, k);
		T ret = res->key;
		erase(ret);
		return ret;
	}
	~treap()
	{
		eraseTree(root);
		root = nullptr;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	treap<int> tp;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			tp.insert(x);
		}
		else
		{
			cout << tp.findKthAndErase(x) << '\n';
		}
	}
}
