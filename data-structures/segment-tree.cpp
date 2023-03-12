template<class T> struct SegmentTree{
    int N;
    vector<T> st;
 
    SegmentTree(int n) : N(n){ st.assign(4 * N, 0); }
 
    int R(int si){ return 2 * si + 2; }
    int L(int si){ return 2 * si + 1; }
    int MID(int ss, int se){ return (ss + se) / 2; }
    T NEUTRAL(){ return 0; }
 
    T merge(T lval, T rval){
        return NEUTRAL();
    }
 
    T get(int qs, int qe){ return get(0, N - 1, 0, qs, qe); }
    T get(int ss, int se, int si, int qs, int qe){
        if(qs <= ss && se <= qe) return st[si];
        if(ss > qe || se < qs) return NEUTRAL();
        return merge(get(ss, MID(ss, se), L(si), qs, qe), 
                    get(MID(ss, se) + 1, se, R(si), qs, qe));   
    }
 
    T update(int i, T val){ return update(0, N - 1, 0, i, val); }
    T update(int ss, int se, int si, int i, T val){
        if(ss == se) return st[si] = val;
        if(i <= MID(ss, se)) return st[si] = merge(update(ss, MID(ss, se), L(si), i, val), 
                                                  st[R(si)]);
        else return st[si] = merge(st[L(si)], update(MID(ss, se) + 1, se, R(si), i, val));
    }
    
};
