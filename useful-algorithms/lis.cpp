vector<int> lis(vector<int> &s){
    int len = 0, n = s.size();
    vector<int> l;
    int lis_len[MAXN], pos;
    for(int i = 0; i < n; i++){
        int j = lower_bound(l.begin(), l.end(), s[i]) - l.begin();
        if(j == l.size()) l.push_back(s[i]);
        else l[j] = s[i];
        lis_len[i] = j + 1;
        if(lis_len[i] > len){
            len = lis_len[i];
            pos = i;
        }
    }
    vector<int> lis(len);
    lis[len - 1] = s[pos];
    for(int i = pos - 1, j = len - 2; i >= 0; i--){
        if(s[i] < s[pos] && lis_len[i] == lis_len[pos] - 1){
            pos = i;
            lis[j] = s[i];
            j--;
        }
    }
    return lis;
}
