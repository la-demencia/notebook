struct Berges{
	int n, m;
	vector <int> match, vis;
	vector <vector <int>> graph;
	Berges(int n, int m) : n(n), m(m), vis(n), graph(n) {
		match.assign(m, -1);
	} 
	void addedge(int l, int r) {
		graph[l].push_back(r);
	}
	int dfs(int l) {
		if (vis[l]) return 0;
		vis[l] = 1;
		for (int& r : graph[l]) {
			if (match[r] == -1 || dfs(match[r])) {
				match[r] = l;
				return 1;
			}
		}
		return 0;
	}
	int mbm() {
		int ans = 0;
		for (int l = 0; l < n; l++) {
			fill(vis.begin(), vis.end(), 0);
			ans += dfs(l);
		}
		return ans;
	}
};

