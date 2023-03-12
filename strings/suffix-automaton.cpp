struct SuffixAutomaton {
	struct State {
		int len, link;
		map<char, int> next;
	};
	vector <State> st;
	int sz, last, n; 
	SuffixAutomaton(string &s) {
		sz = 1; last = 0; n = s.size();
		st.resize(2 * n);
		st[0].len = 0, st[0].link = -1; 
		for (auto &c : s) add(c); //comment in case you don't want to add the whole string
	}
	void add (char c) {
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		int p = last;
		while (p != -1 && !st[p].next.count(c)) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int clone = sz++;
				st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;
				st[clone].link = st[q].link;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = clone;
					p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
};
