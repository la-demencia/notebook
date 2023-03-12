struct FenwickTree{
    vector<ll> bit;
    int n;
    
    FenwickTree(int N){
        n = N;
        bit.assign(n, 0);        
    }
    
    FenwickTree(ll a[], int N){
        n = N;
        bit.assign(n, 0);
        for(int i = 0; i < n; i++)
            add(i, a[i]);
    }

    ll sum(int r){
        ll ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int i, ll delta){
        for(; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
};
