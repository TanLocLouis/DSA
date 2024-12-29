#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};

struct BST {
	Node* root;

	BST() {
		root = NULL;
	}
};

Node* newNode(int data) {
	Node* newNode = new Node;

	if (newNode == NULL) {
		return NULL;
	}

	newNode->key = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* insert(Node*& root, int data) {
	if (root == NULL) {
		Node* insertNode = newNode(data);
		root = insertNode;
		return root;
	}

	if (data < root->key) {
		root->left = insert(root->left, data);
	}
	else if (data > root->key) {
		root->right = insert(root->right, data);
	}
	return root;
}

Node* search(Node* root, int data) {
	if (root == NULL) return root;

	if (root->key == data) return root;
	else if (data < root->key) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

Node* findMinValue(Node* root) {
	if (root == NULL) return root;
	if (root->left == NULL && root->right == NULL) return root;
	
	return findMinValue(root->left);
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) return root;
	
	// Tim phan tu can xoa
	if (data < root->key) {
		deleteNode(root->left, data);
	} else if(data > root->key) {
		deleteNode(root->right, data);
	} else {

		// Neu chi co mot node trai hoac node phai hoac khong co node nao thi chi can xoa no
		// Chi co node phai
		if (root->left == NULL) {
			Node* tmp = root->right;
			delete root;
			return tmp;
		}
		// Chi co node trai
		else if (root->right == NULL) {
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		
		// Neu co 2 node con thi phai xu ly de quy
		else {
			// Tim node nho nhat ben nhanh phai, do chinh la no trai cung
			Node* tmp = findMinValue(root->right);

			// Gia tri nho nhat cua nhanh phai van LON HON gia tri cua nhanh trai
			root->key = tmp->key;

			// Goi de quy de xu ly nhanh phai
			root->right = deleteNode(root->right, tmp->key);
		}
	}
}

void NLR(Node* root) {
	if (root == NULL) return;

	cout << root->key << char(32);
	NLR(root->left);
	NLR(root->right);
}

void LNR(Node* root) {
	if (root == NULL) return;

	NLR(root->left);
	cout << root->key << char(32);
	NLR(root->right);
}

void LRN(Node* root) {
	if (root == NULL) return;

	NLR(root->left);
	NLR(root->right);
	cout << root->key << char(32);
}

void LevelOrder(Node* root) {
	if (root == NULL) return;

	queue<Node*> q;
	q.push(root);

	int level = 0;
	while (!q.empty()) {
		int sz = q.size();

		// Lay tat ca con trong level hien tai
		cout << "Level " << level << ": ";
		for (int i = 0; i < sz; i++) {
			Node* cur = q.front(); q.pop();
			cout << cur->key << " ";
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
		}
		level++;

		cout << endl;
	}
}

int height(Node* root) {
	if (root == NULL) return 0;
	return max(1 + height(root->left), 1 + height(root->right));
}

int countNode(Node* root) {
	if (root == NULL) return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}

int sumNode(Node* root) {
	if (root == NULL) return 0;
	return root->key + sumNode(root->left) + sumNode(root->right);
}

int countLeaf(Node* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	return countLeaf(root->left) + countLeaf(root->right);
}

int countLess(Node* root, int x) {
	if (root == NULL) return 0;
	
	if (root->key < x)
		return 1 + countLess(root->left, x) + countLess(root->right, x);
	
	// Neu khong nho hon thi chi can duyet nhanh ben trai
	return countLess(root->left, x);
}

int countGreater(Node* root, int x) {
	if (root == NULL) return 0;
	
	if (root->key > x)
		return 1 + countGreater(root->left, x) + countGreater(root->right, x);
	
	// Neu khong lon hon thi chi can duyet nhanh ben phai
	return countGreater(root->right, x);
}

int main() {
	BST* t = new BST;
	insert(t->root, 1);
	insert(t->root, 5);
	insert(t->root, 3);
	insert(t->root, 2);
	insert(t->root, 4);
	cout << "NLR: "; NLR(t->root); cout << endl;
	cout << "LNR: "; LNR(t->root); cout << endl;
	cout << "LRN: "; LRN(t->root); cout << endl;
	cout << "Level Order: ";  LevelOrder(t->root); cout << endl;

	cout << "heigt: " << height(t->root) << endl;
	cout << "countNode: " << countNode(t->root) << endl;
	cout << "sumNode: " << sumNode(t->root) << endl;
	cout << "countLeaf: " << countLeaf(t->root) << endl;
	cout << "countLess: " << countLess(t->root, 3) << endl;
	cout << "countGreater: " << countGreater(t->root, 3) << endl;
	
	cout << endl;
	cout << "After delete node: " << endl;
	deleteNode(t->root, 3);
	cout << "NLR: "; NLR(t->root); cout << endl;
	cout << "LNR: "; LNR(t->root); cout << endl;
	cout << "LRN: "; LRN(t->root); cout << endl;
	cout << "Level Order: ";  LevelOrder(t->root); cout << endl;
	
	return 0;
}