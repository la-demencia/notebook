// O(n) time complexity

const int MAXN = 1000000;
vector<int> pr;
int lp[MAXN];

void sieve(int N){
    for(int i = 2; i <= N; i++){
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
}
