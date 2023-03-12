template<class T> struct SparseTable{
    int N, LOG2N;
    vector<T> lg2;
    vector<vector<T>> st;

    SparseTable(vector<T> &a, std::function<T(T, T)> f){
        N = a.size();
        LOG2N = log2(N) + 2;
        lg2.assign(N + 1, 0);
        st.assign(N, vector<T>(LOG2N, 0));

        lg2[1] = 0;
        for(int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
        for(int i = 0; i < N; i++) st[i][0] = a[i];
        for(int j = 1; j <= LOG2N; j++)
            for(int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    T minimum(int L, int R){
        int lg = lg2[R - L + 1];
        return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
    }

    T sum(int L, int R){
        T ans = 0;
        for(int i = LOG2N; i >= 0; i--){
            if(R - L + 1 >= (1 << i)){
                ans += st[L][i];
                L += (1 << i);
            }
        }
        return ans;
    }
};
