#include <iostream>
#include <queue>


using namespace std;


class Node {

public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int d) : data{ d }, left{ nullptr }, right{ nullptr }, parent{ nullptr } {}
	void print() {
		cout << data;
	}
};

class Tree {
	Node* root = nullptr;
	void removeNode(int key);
	Node* removeNode(Node* root, int key);
	Node* minValueNode(Node* node);
	void remove(int key);
	Node* add(Node*& y, Node* node, Node* parent);


	void print(Node* Node);

public:
	void addNode(Node* n) {
		add(root, n, nullptr);
	}
	void print() {
		print(root);
	}
};
void Tree::removeNode(int key) {
	root = removeNode(root, key);
}

Node* Tree::removeNode(Node* root, int key) {
	if (root == nullptr) {
		return root;
	}

	if (key < root->data) {
		root->left = removeNode(root->left, key);
	}
	else if (key > root->data) {
		root->right = removeNode(root->right, key);
	}
	else {
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = removeNode(root->right, temp->data);
	}
	return root;
}

Node* Tree::minValueNode(Node* node) {
	Node* current = node;
	while (current && current->left != nullptr) {
		current = current->left;
	}
	return current;
}
//Node* Tree::removeNode(Node* root, int key) {
//	if (!root) {
//		return root;
//	}
//	if (key < root->data) {
//		root->left = removeNode(root->left, key);
//	}
//	else if (key > root->data) {
//		root->right = removeNode(root->right, key);
//	}
//	else {
//		if (root->left == nullptr) {
//			Node* temp = root->right;
//			delete root;
//			return temp;
//		}
//		else if (root->right == nullptr) {
//			Node* temp = root->left;
//			delete root;
//			return temp;
//		}
//		Node* temp = minValueNode(root->right);
//		root->data = temp->data;
//		root->right = removeNode(root->right, temp->data);
//	}
//	return root;
//}

//Node* Tree::minValueNode(Node* node) {
//	Node* current = node;
//	while (current && current->left != nullptr) {
//		current = current->left;
//	}
//	return current;
//}

void Tree::remove(int key) {
	root = removeNode(root, key);
}


Node* Tree::add(Node*& y, Node* z,Node* parent) {

	if (!y) {
		y = z;
		y->parent = parent;
		return z;
	}
	if (z->data < y->data) {
		y->left = add(y->left, z,parent);

	}
	else if (z->data >= y->data) {
		y->left = add(y->right, z,parent);

	}

	return  y;
}

//Рекурсивный обход дерева (в глубину)
void Tree::print(Node* node) {
	if (node != 0) {
		print(node->right);
		node->print();
		print(node->left);
	}
}

int main() {

	Tree t;
	t.addNode(new Node(7));
	t.addNode(new Node(3));
	t.addNode(new Node(9));
	t.addNode(new Node(5));
	t.addNode(new Node(9));
	

	t.print();

	return 0;
}