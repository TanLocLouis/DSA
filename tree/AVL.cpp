#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
};

struct AVL {
	Node* root;

	AVL() {
		root = NULL;
	}
};

Node* createNode(int data) {
	Node* newNode = new Node;
	if (newNode == NULL) return NULL;

	newNode->key = data;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;

	return newNode;
}
//---------Ham ho tro------
int getHeight(Node* root) {
	if (root == NULL) return 0;
	return root->height;
}

int getBalance(Node* root) {
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

Node* leftRotate(Node* root) {
	Node* pivot = root->right;
	Node* temp = pivot->left;

	pivot->left = root;
	root->right = temp;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));

	return pivot;
}

Node* rightRotate(Node* root) {
	Node* pivot = root->left;
	Node* temp = pivot->right;

	pivot->right = root;
	root->left = temp;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));

	return pivot;
}
//-------------------------

Node* insertNode(Node*& root, int data) {
	if (root == NULL) {
		Node* newNode = createNode(data);
		root = newNode;
		return root;
	}

	if (data < root->key) {
		root->left = insertNode(root->left, data);
	}
	else if (data > root->key) {
		root->right = insertNode(root->right, data);
	}
	else {
		return root;
	}

	// Cap nhat chieu cao cho Node cha
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	// Kiem tra do can bang
	int balance = getBalance(root);

	//--------------Co 4 truong hop mat can bang-----------
	// Left Left Case 
	if (balance > 1 && data < root->left->key)
		return rightRotate(root);

	// Right Right Case 
	if (balance < -1 && data > root->right->key)
		return leftRotate(root);

	// Left Right Case 
	if (balance > 1 && data > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case 
	if (balance < -1 && data < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) return NULL;

	if (data < root->key) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->key) {
		root->right = deleteNode(root->right, data);
	}
	else {
		if (root->left == NULL || root->right == NULL) {
			Node* temp = root->left ? root->left : root->right;

			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else {
				*root = *temp;
			}
			
			delete temp;
		}
		else {
			// Tim node nho nhat ben nhanh phai
			Node* temp = root->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}

			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL) return NULL;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balance = getBalance(root);

	//--------------Co 4 truong hop mat can bang-----------
	// Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Left Right Case 
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) return NULL;

	if (data < root->key) {
		return searchNode(root->left, data);
	}
	else if (data > root->key) {
		return searchNode(root->right, data);
	}
	else {
		return root;
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
	NLR(root->right);
	cout << root->key << char(32);
}

void LRN(Node* root) {
	if (root == NULL) return;

	NLR(root->left);
	cout << root->key << char(32);
	NLR(root->right);
}

void levelOrder(Node* root) {
	if (root == NULL) return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		cout << cur->key << char(32);

		if (cur->left != NULL) q.push(cur->left);
		if (cur->right != NULL) q.push(cur->right);
	}
}

bool isFull(Node* root) {
	if (root == NULL) return true;

	if (root->left == NULL && root->right == NULL) return true;
	if (root->left != NULL && root->right != NULL) {
		return isFull(root->left) && isFull(root->right);
	}

	return false;
}

bool isComplete(Node* root) {
	if (root == NULL) return true;

	queue<Node*> q;
	q.push(root);

	bool flag = false;
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL) {
			if (flag == true) return false;
			q.push(temp->left);
		}
		else {
			flag = true;
		}

		if (temp->right != NULL) {
			if (flag == true) return false;
			q.push(temp->right);
		}
		else {
			flag = true;
		}
	}

	return true;
}

int countNode(Node* root) {
	if (root == NULL) return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}

bool isPerfect(Node* root) {
	if (root == NULL) return true;

	int h = getHeight(root);
	// isFull + isComplete + countNode
	return isFull(root) && isComplete(root) && pow(2, h) - 1 == countNode(root);
}

int findCommonAncestor(Node* root, int x, int y) {
	if (root == NULL) return -1;
	
	// ancestor o ben trai 
	if (root->key > x && root->key > y) {
		return findCommonAncestor(root->left, x, y);
	}
	// ancestor o ben phai
	else if (root->key < x && root->key < y) {
		return findCommonAncestor(root->right, x, y);
	}
	else {
		return root->key;
	}
}

// find all node with 2 node, the left child is divisor of right child
void printSpecialNodes(Node* root) {
	if (root == NULL) return;

	if (root->left != NULL && root->right != NULL) {
		if (root->left->key % root->right->key == 0) {
			cout << root->key << char(32);
		}
	}

	printSpecialNodes(root->left);
	printSpecialNodes(root->right);
}

int main() {
	AVL Tree;
	Tree.root = insertNode(Tree.root, 1);
	Tree.root = insertNode(Tree.root, 2);
	Tree.root = insertNode(Tree.root, 3);
	Tree.root = insertNode(Tree.root, 5);
	Tree.root = insertNode(Tree.root, 6);
	Tree.root = insertNode(Tree.root, 9);
	Tree.root = insertNode(Tree.root, 4);
	cout << "NLR: ";  NLR(Tree.root); cout << endl;
	cout << "LNR: ";  LNR(Tree.root); cout << endl;
	cout << "LRN: ";  LRN(Tree.root); cout << endl;

	cout << "After Delete: " << endl;  deleteNode(Tree.root, 3);
	cout << "NLR: ";  NLR(Tree.root); cout << endl;
	cout << "LNR: ";  LNR(Tree.root); cout << endl;
	cout << "LRN: ";  LRN(Tree.root); cout << endl;

	cout << "isFull: " << isFull(Tree.root) << endl;
	cout << "isComplete: " << isComplete(Tree.root) << endl;
	cout << "isPerfect: " << isPerfect(Tree.root) << endl;
	
	cout << "Common Ancestor: " << findCommonAncestor(Tree.root, 2, 6) << endl;
	cout << "Special Nodes: "; printSpecialNodes(Tree.root); cout << endl;

	return 0;
}
