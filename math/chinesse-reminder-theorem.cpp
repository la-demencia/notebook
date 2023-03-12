struct CRT{
	vector <ll> A, M; // solves x congruent ai mod mi, for mi pairwise coprime
	ll ans, mod;// ans stores x value, and mod (x + mod) is also a solution
	CRT(vector <ll> A, vector <ll> M) : A(A), M(M) {}
	ll ext_gcd(ll a, ll b, ll &x, ll &y) {
		if (b == 0) {x = 1, y = 0; return a; }
		ll x1, y1; 
		ll g = ext_gcd(b, a % b, x1, y1);
		x = y1; y = x1 - y1 * (a / b);
		return g;
	}
	void solve() {//If there's a solution returns smallest possible solution, otherwise return -1
		int n = A.size();
		ll a1 = A[0], m1 = M[0];
		for (int i = 1; i < n; ++i) { //merges solution
			ll a2 = A[i], m2 = M[i];
			ll p, q;
			ext_gcd(m1, m2, p, q);
			ll x = (a1 * m2 * q + a2 * m1 * p) % (m1 * m2);// may overflow
			a1 = x;
			m1 = m1 * m2;
		}
		mod = m1;
		ans = a1;
		if (ans < 0) ans += mod;
	}
};
