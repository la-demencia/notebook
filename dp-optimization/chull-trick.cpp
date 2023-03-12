struct Line {
	ll m, b;
	ll eval (ll x) { return m*x + b; }
};
struct CHT { // for maximum (for minimum do add({-bi, -dpi}), ans = -eval(ai))  
	vector<Line> lines;
	vector<lf> inter;
	int n;
	lf get_inter(Line &a, Line &b) { return lf(b.b - a.b) / (a.m - b.m); }
	inline bool ok(Line &a, Line &b, Line &c) { 
		return lf(a.b-c.b) / (c.m-a.m) > lf(a.b-b.b) / (b.m-a.m); 
	}
	void add(Line l) { 
		n = lines.size();
		if(n && lines.back().m == l.m && lines.back().b >= l.b) return;
		if(n == 1 && lines.back().m == l.m && lines.back().b < l.b) lines.pop_back(), n--;
		while(n >= 2 && !ok(lines[n-2], lines[n-1], l)) {
			n--;
			lines.pop_back(); inter.pop_back();
		}
		lines.push_back(l); n++;
		if(n >= 2) inter.push_back(get_inter(lines[n-1], lines[n-2]));
	}
	ll eval(lf x) {
		if(lines.size() == 0) return LLONG_MIN; //change in case you need a minimum;
		if(lines.size() == 1) return lines[0].eval(x);
		int pos = lower_bound(inter.begin(), inter.end(), x) - inter.begin();
		return lines[pos].eval(x);
	}
};
