struct Line {
	ll m = 0, b = INF;
	ll eval(ll x) { return m * x + b; }
};
struct Node {
	Line value;
	Node* left = nullptr, *right = nullptr;
	Node(Line value): value(value) {};
	Node(Node *l, Node* r, Line value) : value(value) {
		left = l, right = r;
	}
};
Node* roots[maxn];
Node* build(int l = 0, int r = N - 1) {
	return new Node({});
}
Node* update(Node* u, Line val, int l = 0, int r = N - 1) { //Minimum
	if (l > r) return nullptr;
	if (l == r || !u) return new Node(val); 
	int mid = (l + r) / 2;

	// To remove persistance just use node u instead of v
	Node* v = new Node({u->value});
	v->left = u->left;
	v->right= u->right;
 
	if (v->value.eval(mid) > val.eval(mid)) swap(val, v->value); //set current line to optimal
	if (v->value.eval(l) > val.eval(l)) {
		v->left = update(v->left, val, l, mid);
	} else {
		v->right = update(u->right, val, mid + 1, r);
	}
	return v;
}
ll query(Node* u, ll x, int l = 0, int r = N - 1) {
	if (!u) return INF;
	if (l == r) return u->value.eval(x);
	int mid = (l + r) / 2;
	ll ans = u->value.eval(x);
	if (x <= mid) return min(ans, query(u->left, x, l, mid));
	return min(ans, query(u->right, x, mid + 1, r));
}
