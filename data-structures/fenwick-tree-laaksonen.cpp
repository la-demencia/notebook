struct FenwickTree{
	int n;
	vector<int> tree;

	FenwickTree(int n) : n(n) {
		tree.assign(n + 10,0);
	}

	void update(int k, int x){
		while(k<=n){
			tree[k] += x;
			k+=k&-k;
		}
	}

	int sum(int k){
		int sum = 0;
		while(k>=1){
			sum+=tree[k];
			k-=k&-k;
		}
		return sum;
	}

	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
};
