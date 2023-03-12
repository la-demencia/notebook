/*
  Struct palindromic tree:
    sigma = alphabet size
    node : len (lenght of the palindrome at that node), lin (suffix link = longest suffix palindrome that is not itslef), to (transitions);
    tree = palindromic tree per se
*/
//Complexity O( |s| )
struct PalindromicTree{
	static const int sigma = 26; //Alphabet size
	struct Node{
		int len, link, to[sigma];
		ll cnt;
		Node (int len, int link = 0, ll cnt = 1) : len(len), link(link), cnt(cnt) {
			memset(to, 0, sizeof to);
		}
	};
	vector <Node> tree;
	int last;
	PalindromicTree() : last(0) {
		tree.push_back(Node(-1));
		tree.push_back(Node(0));
	}
	void add(int i, string &s) {
		int p = last, c = s[i] - 'a'; 
		while (s[i - tree[p].len - 1] != s[i]) p = tree[p].link;
		if (tree[p].to[c]) { //Palindrome already added
			last = tree[p].to[c];
			tree[last].cnt++;
		} else { //New palindrome
			int q = tree[p].link;
			while( s[i - tree[q].len - 1] != s[i] ) q = tree[q].link;
			q = max(1, tree[q].to[c]);
			last = tree[p].to[c] = tree.size();
			tree.push_back(Node(tree[p].len + 2, q, 1));
		}
	}
};
