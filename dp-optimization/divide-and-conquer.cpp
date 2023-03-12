/**
 * NOTE: 
 * 1. in order to work cost(a, c) + cost(b, d) <= cost(a, d) + cost(b, c)
 *    where a <= b <= c <= d.
 * 2. Complexity O(n * k * log(n));
 * 3. You can iterate over the segments like in Mo's, moving lo and hi over the segments
 **/
template <class T> struct DivideAndConquer{
	vector <T> dp, dp_prev, a;
	int n, k;
	T totalCost;
	DivideAndConquer(int n, int k, vector <T> a) : n(n), k(k), a(a) {
		dp_prev.resize(n);
		dp.resize(n);
		totalCost = 0;
	}
	T cost (int l, int r) {
		//fill out this method
		return totalCost;
	}
	void compute(int l, int r, int optl, int optr) {
		if (l > r) return;
		int mid =  (l + r) >> 1;
		pair <T, int> best = {numeric_limits<T>::max(), -1};
		for (int k = optl; k <= min(mid, optr); k++) {
			pair <T, int> cur = { (k ? dp_prev[k - 1] : 0) + cost(k, mid), k} ;
			best = min(best, cur);
		}
		dp[mid] = best.first;
		int opt = best.second;
		compute(l, mid - 1, optl, opt);
		compute(mid + 1, r, opt, optr);
	}
	T solve() {
		for (int i = 0; i < n; i++) {
			dp_prev[i] = cost(0, i);
		}
		for (int i = 1; i < k; i++) {
			compute(0, n - 1, 0, n - 1);
			dp_prev = dp;
		}
		return dp_prev[n - 1];
	}
};
