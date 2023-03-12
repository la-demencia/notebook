template<class T> struct MinCostFlow {
	struct Edge {
	  int to, rev; 
	  T cap, cost, flow ;
	  Edge(int to, int rev, T cap, T cost, T flow = 0) : to(to), rev(rev), cap(cap), cost(cost), flow(flow) {}
	};
	int n, s, t;
	vector<vector<Edge>> graph;
	void addedge(int s, int t, T cap, T cost){
		graph[s].push_back(Edge(t, graph[t].size() , cap, cost));
		graph[t].push_back(Edge(s, graph[s].size() -1, 0, -cost));
	}
	MinCostFlow (int n) : n(n) { 
		graph.resize(n); 
	}
	bool spfa(int start, vector<T>& d, vector<int>& p) {
		d.assign(n, oo); 
		d[start] = 0;
		vector<bool> inq(n,0);
		queue<int> q;
		q.push(start);
		p.assign(n,-1);
		while (!q.empty()) {
		  int u = q.front();
		  q.pop();
		  inq[u] = 0;
			for(int i= 0; i < graph[u].size(); ++i){
				Edge v = graph[u][i];
				if (v.cap - v.flow > 0 && d[v.to] > d[u] + v.cost ) {
					d[v.to] = d[u] + v.cost;
					p[v.to] = v.rev;
					if (!inq[v.to]) {
						inq[v.to] = 1;
						q.push(v.to);
					}
				}
			}
		}
		return d[t] != oo;
	}
	pair <T, T>  maxflow(int source, int sink) {
		s = source, t = sink;
		T flow = 0, cost = 0;
		vector<int> p;
		vector<T> d;
		while (spfa(s, d, p)) {
			T newflow  = oo;
			int cur = t;
			while (cur != s) {
				int u = graph[cur][p[cur]].to;
				int rev = graph[cur][p[cur]].rev;
				T c = graph[u][rev].cap - graph[u][rev].flow;
				newflow  = min(newflow, c);
				cur = u;
			}
			flow += newflow;
			cost += newflow * d[t];
			cur = t;
			while (cur != s) {
				int rev = graph[cur][p[cur]].rev;
				int u = graph[cur][p[cur]].to;
				graph[u][rev].flow += newflow;
				graph[cur][p[cur]].flow -= newflow;
				cur = u;
			}
		}
		return {flow, cost};
	}
};
