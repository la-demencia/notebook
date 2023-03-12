struct FenwickTree2D {
    vector<vector<ll>> bit;
    int n, m;

    FenwickTree2D(int N, int M){
        n = N;
        m = M;
        bit.assign(n, vector<ll>(m, 0));
    }

    FenwickTree2D(vector<vector<ll>> &a, int N, int M){
        n = N;
        m = M;
        bit.assign(n, vector<ll>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                add(i, j, a[i][j]);
    }

    int sum(int x, int y){
        ll ret = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, ll delta){
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};
