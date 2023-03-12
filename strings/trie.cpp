struct Trie{
    
    vector<bool> end_word;
    int nodes = 1;
    vector<vector<int>> trie;

    Trie(int TRIE_LEN = 400005,int ALPHA_SIZE = 26){ // Dictionary size * length of words
        end_word.assign(TRIE_LEN, 0);
        trie.assign(TRIE_LEN, vector<int>(ALPHA_SIZE, 0));
    }

    void add(const string &s){
        int cur = 0;
        for(char c: s){
            int cc = c - 'a';
            if(!trie[cur][cc]) trie[cur][cc] = nodes++;
            cur = trie[cur][cc];
        }
        end_word[cur] = true;
    }

    bool check(const string &t){
        int cur = 0;
        for(char c: t){
            int cc = c - 'a';
            cur = trie[cur][cc];
            if(end_word[cur]) return true;
            if(!cur) return false;
        }
        return false;
    }
};
