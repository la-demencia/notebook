struct StrongCRT {
	vector <ll> A, M; // solves x congruent ai mod mi, for mi not necesarily pairwise coprime
	ll ans, mod;// ans stores x value, and mod (x + mod) is also a solution
	StrongCRT(vector <ll> A, vector <ll> M) : A(A), M(M) {}
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
			ll g = __gcd(m1, m2);
			if (a1 % g != a2 % g) { ans = -1; return; }
			ll p, q;
			ext_gcd(m1/g, m2/g, p, q);
			mod = m1 / g * m2;
			ll x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;// may overflow
			a1 = x;
			if (a1 < 0) a1 += mod;
			m1 = mod;
		}
		ans = a1;
	}
};
