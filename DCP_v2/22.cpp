/*
  author : Anand

    Problem 22
    This problem was asked by Microsoft.

    Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

    For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

    Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

class TrieNode {
   public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode() {
        children.assign(26, nullptr);
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, string s) {
    TrieNode* temp = root;
    int len = s.size();
    int idx;
    for (int i = 0; i < len; ++i) {
        idx = s[i] - 'a';
        if (!temp->children[idx]) {
            temp->children[idx] = new TrieNode();
        }
        temp = temp->children[idx];
    }
    temp->isEndOfWord = true;
}

bool match1(TrieNode* root, string s) {
    TrieNode* temp = root;
    int len = s.size();
    int idx;
    for (int i = 0; i < len; ++i) {
        idx = s[i] - 'a';
        if (!temp->children[idx]) {
            return false;
        }
        temp = temp->children[idx];
    }
    return temp->isEndOfWord;
}

vector<string> match2(TrieNode* root, string s) {
    TrieNode* temp = root;
    int len = s.size();
    int idx;
    vector<string> res;
    int prevStart = 0;
    for (int i = 0; i < len; ++i) {
        idx = s[i] - 'a';
        if (!temp->children[idx]) {
            return {};
        }
        temp = temp->children[idx];
        if (temp->isEndOfWord) {
            temp = root;
            res.push_back(s.substr(prevStart, i - prevStart + 1));
            prevStart = i+1;
        }
    }
    if (temp != root) {
        res = {};
    }
    return res;
}

template <typename T>
bool isVectorEqual(vector<T> v1, vector<T> v2) { return v1 == v2; }

void solve() {
    TrieNode* root1 = new TrieNode();
    insert(root1, "quick");
    insert(root1, "brown");
    insert(root1, "the");
    insert(root1, "fox");

    assert(match1(root1, "quick"));
    assert(match1(root1, "brown"));
    assert(match1(root1, "the"));
    assert(match1(root1, "fox"));

    assert(isVectorEqual(match2(root1, "thequickbrownfox"), {"the", "quick", "brown", "fox"}));

    TrieNode* root2 = new TrieNode();
    insert(root2, "bed");
    insert(root2, "bath");
    insert(root2, "bedbath");
    insert(root2, "and");
    insert(root2, "beyond");

    assert(match1(root2, "bed"));
    assert(match1(root2, "bath"));
    assert(match1(root2, "bedbath"));
    assert(match1(root2, "and"));
    assert(match1(root2, "beyond"));

    assert(isVectorEqual(match2(root2, "bedbathandbeyond"), {"bed", "bath", "and", "beyond"}));
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}