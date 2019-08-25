
#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1000005;
const int MAXN = 100005;

// Trie
struct Node {
	int ch[26];
	Node() {
		memset(ch, -1, sizeof ch);
	}
} trie[MAXLEN]; int sz;

// Aho Corasick
struct AhoCorasick {
	int fail[MAXLEN];
	vector <int> g[MAXLEN];

	void add(string &s, int id) {
		int cur = 0;
		for (int i = 0; i < s.size(); ++i) {
			int c = s[i] - 'a';
			if (trie[cur].ch[c] == 0) {
				trie[cur].ch[c] = ++sz;
			}
			cur = trie[cur].ch[c];
		}
	}

	void bfs() {
		queue <int> q; q.push(0);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < 26; ++i) {
				int v = trie[u].ch[i];
				trie[u].ch[i] = 0;
				trie[u].ch[i] = trie[fail[u]].ch[i];
				if (v) {
					fail[v] = trie[u].ch[i];
					trie[u].ch[i] = v;
					q.push(v);
				}
			}
		}
	}

	void build() {
		// build link-tree
		for (int i = 1; i <= sz; ++i) {
			g[fail[i]].push_back(i);
		}
		// dfs(0);
	}
};