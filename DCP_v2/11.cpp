/*
  author : Anand

    Problem 11
    This problem was asked by Twitter.

    Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

    For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

    Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
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

const int SIZE = 26;

class Trie {
    class TrieNode {
       public:
        vector<TrieNode*> children;
        bool isEndOfWord;
        TrieNode() {
            children = vector<TrieNode*>(SIZE, nullptr);
            isEndOfWord = false;
        }
    };
    TrieNode* root;
    bool isLastNode(TrieNode* node) {
        for (int i = 0; i < SIZE; ++i) {
            if (node->children[i]) {
                return false;
            }
        }
        return true;
    }
    void suggestionsRec(TrieNode* node, string s) {
        if (node->isEndOfWord) {
            cout << s << "\n";
        }
        if (isLastNode(node)) {
            return;
        }

        for (int i = 0; i < SIZE; ++i) {
            if (node->children[i]) {
                s.push_back('a' + i);
                suggestionsRec(node->children[i], s);
                s.pop_back();
            }
        }
    }

   public:
    Trie() {
        root = new TrieNode();
    }

    void addWord(string s) {
        TrieNode* temp = root;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            int idx = s[i] - 'a';
            if (!temp->children[idx]) {
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->isEndOfWord = true;
    }

    bool search(string s) {
        TrieNode* temp = root;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            int idx = s[i] - 'a';
            if (!temp->children[idx]) {
                return false;
            }
            temp = temp->children[idx];
        }
        return temp->isEndOfWord;
    }

    void printAutoSuggestions(string s) {
        TrieNode* temp = root;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            int idx = s[i] - 'a';
            if (!temp->children[idx]) {
                cout << "No string found with this prefix\n";
                return;
            }
            temp = temp->children[idx];
        }
        bool isLast = isLastNode(temp);
        if (temp->isEndOfWord && isLast) {
            cout << s << "\n";
            cout << "No other strings found with this prefix\n";
            return;
        }
        if (!isLast) {
            suggestionsRec(temp, s);
        }
    }
};

void solve() {
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