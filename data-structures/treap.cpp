struct Node {
	Node *left, *right;
	int weight, size, value;
	Node (int value = 0) : size(1), value(value) { 
		left = right = nullptr;
		weight = rand();
	}
};

int size(Node *&treap) {
	return treap ? treap->size : 0;
}

void split(Node *treap, Node *&left, Node *&right, int k) {
	if (!treap) {
		left = right = nullptr;
		return;
	}
	if (treap->value <= k) {
		split(treap->right, treap->right, right, k);
		left = treap;
	} else {
		split(treap->left, left, treap->left, k);
		right = treap;
	}
	treap->size = 1 + size(treap->left) + size(treap->right);
}

void merge(Node *&treap, Node *left, Node *right) {
	if (!left) treap = right;
	else if (!right) treap = left;
	else {
		if (left->weight < right->weight) {
			merge(left->right, left->right, right);
			treap = left;
		} else {
			merge(right->left, left, right->left);
			treap = right;
		}
		treap->size = 1 + size(treap->left) + size(treap->right);
	}
}

void insert(Node *&treap, int k) {
	Node *newNode = new Node(k);
	Node *left, *right;
	split(treap, left, right, k - 1);
	merge(left, left, newNode);
	merge(treap, left, right);
}

void erase(Node *&treap, int k) {
	Node *left, *right, *mid;
	split(treap, left, right, k);
	split(left, left, mid, k - 1);
	merge(treap, left, right);
}
