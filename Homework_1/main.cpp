#include <iostream>
#include <string>
using namespace std;


struct Node {
	string key;
	int value;
	Node* left;
	Node* right;

	Node(string _key, int _val) : key(_key), value(_val), left(nullptr), right(nullptr) {}

	bool insert(string _key, int _value) {
		if (key < _key) {
			if (right == nullptr) {
				right = new	Node(_key, _value);
				return true;
			}
			return right->insert(_key, _value);
		}
		else if (key > _key) {
			if (left == nullptr) {
				left = new Node(_key, _value);
				return true;
			}
			return left->insert(_key, _value);
		}
		return false;
	}

	int get(string _key) {
		if (key == _key)
			return value;
		else if (_key < key && left != nullptr)
			return left->get(_key);
		else if (right != nullptr && _key > key)
			return right->get(_key);
		return -1;
	}

	bool remove(string _key, Node* parent) {
		if (key < _key)
			return right != nullptr && right->remove(_key, this);
		else if (key > _key)
			return left != nullptr && left->remove(_key, this);

		if (left == nullptr && right == nullptr) {
			if (parent->key > key)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete this;
			return true;
		}
		else if (left == nullptr || right == nullptr) {
			Node* child;
			if (!left)
				child = right;
			else child = left;

			if (parent->key > key)
				parent->left = child;
			else
				parent->right = child;
			delete this;
			return true;
		}
		else {
			if (right->left == nullptr) {
				right->left = left;
				if (parent->key > _key)
					parent->left = right;
				else
					parent->right = right;
				delete this;
				return true;
			}
			else {
				Node* curNode = right;
				Node* curPar = this;
				while (curNode->left) {
					curPar = curNode;
					curNode = curNode->left;
				}
				value = curNode->value;
				key = curNode->key;
				curNode->remove(curNode->key, curPar);
				return true;
			}
		}
		return false;
	}

	void print() {
		cout << key << " " << value << endl;
		if (left) left->print();
		if (right) right->print();
	}
};


struct AssociativeArray {
	Node* start;
	int size;

	AssociativeArray() : start(nullptr), size(0) {}

	bool isEmpty() {
		return start == nullptr;
	}

	bool insert(string _key, int _value) {
		if (!isEmpty()) {
			if (start->insert(_key, _value)) {
				size++;
				return true;
			}
			return false;
		}
		start = new Node(_key, _value);
		size++;
		return true;
	}

	int get(string _key) {
		if (isEmpty()) 
			return -1;
		return start->get(_key);
	}

	int length() {
		return size;
	}

	bool remove(string _key) {
		if (start->key == _key) {
			// ”далить корень и полностью пересобрать дерево
		}
		else return !isEmpty() && start->remove(_key, nullptr);
	}

	void print() {
		cout << endl;
		if (!isEmpty()) {
			start->print();
		}
	}
};


AssociativeArray* createMap() {
	AssociativeArray* m = new AssociativeArray();
	cout << "Input number of elements" << endl;
	int l;
	cin >> l;
	cout << "Input elements (string key, int value)" << endl;
	for (int i = 0; i < l; i++) {
		string k;
		int v;
		cin >> k >> v;
		m->insert(k, v);
	}
	return m;
}


int main() {
	AssociativeArray* m = createMap();
	m->print();
	m->insert("d", 10);
	m->print();
	cout << m->get("d");
	m->remove("d");
	m->print();

	return 0;
}