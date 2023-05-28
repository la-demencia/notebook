/*
*   edge: edge structure where
*         v = from, inv = id of the inverse edge, cap = capacity, flow = current flow on the edge.
*
*   Dinic: n = number of nodes, s = source node, t = sink node;
*          level = vector level of nodes (level network)
*          graph = network flow graph
*          call maxflow with oo = the require flow (infinite for maximum flow or a value if you want a flow <= x)
*
*/
//Complexity O (n * n * m); where m = number of edges
template <class T> struct  Dinic {
	struct Edge {
		int v, inv; T cap, flow;
		Edge (int v, int inv, T cap, T flow) : v(v), inv(inv), cap(cap), flow(flow) {}
	};
	int n, s, t, top;
	vector <int> level, q;
	vector <vector <Edge>> graph;
	Dinic (int n) : n(n), top(0), level(n), q(n + 1), graph(n) {}
	void addedge(int u, int v, T cap) {
		graph[u].push_back(Edge(v, graph[v].size(), cap, 0));
		graph[v].push_back(Edge(u, graph[u].size() - 1, 0, cap));
	}
	bool bfs() {
		fill(level.begin(), level.end(), -1);
		q[++top] = s;
		level[s] = 0;
		while (top) {
			int u = q[top]; top--;
			for (int i= 0; i < (int)graph[u].size(); i++) {
				Edge& e = graph[u][i];
				if (e.cap > 0 && level[e.v] == -1) {
					level[e.v]= level[u] + 1;
					q[++top] = e.v;
				}
			}
		}
		return level[t] != -1;
	}
	T dfs(int u, T pushed) {
		if (u == t) return pushed;
		T ans = 0;
		for (int i = 0; i < (int)graph[u].size(); i++) {
			Edge& e = graph[u][i];
			if (e.cap >  0 && level[e.v] == level[u] + 1) {
				T newflow = dfs(e.v, min(pushed, e.cap));
				ans += newflow;
				pushed -= newflow;
				e.cap -= newflow, e.flow += newflow;
				graph[e.v][e.inv].cap += newflow;
				graph[e.v][e.inv].flow -= newflow;
				if (pushed == 0) return ans;
			}
		}
		if (!ans) level[u] = -1;
		return ans;
	}
	T maxflow(int u, int v) {
		T ans = 0; s = u, t = v;
		while (bfs()) ans += dfs(s, oo);
		return ans;
	}
};
