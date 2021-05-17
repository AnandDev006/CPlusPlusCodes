/*
  author : Anand

    Problem 24
    This problem was asked by Google.

    Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

    Design a binary tree node class with the following methods:

    is_locked, which returns whether the node is locked lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true. unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true. You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
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

class Node {
    bool isParentLocked(Node* node) {
        while (node->parent) {
            if (node->parent->isLocked) {
                return true;
            }
            node = node->parent;
        }
        return false;
    }

    void updateParents(Node* node, int increment) {
        while (node->parent) {
            node->parent->lockedDescendantsCount += increment;
            node = node->parent;
        }
    }

   public:
    int val;
    Node* parent;
    Node* left;
    Node* right;
    bool isLocked;
    int lockedDescendantsCount;

    Node(int _val, Node* _parent = nullptr) {
        val = _val;
        parent = _parent;
        left = right = nullptr;
        isLocked = false;
        lockedDescendantsCount = 0;
    }

    bool lock() {
        if (isParentLocked(this) || lockedDescendantsCount != 0) {
            return false;
        } else {
            this->isLocked = true;
            updateParents(this, 1);
            return true;
        }
    }

    bool unlock() {
        if (isParentLocked(this) || lockedDescendantsCount != 0) {
            return false;
        } else {
            this->isLocked = false;
            updateParents(this, -1);
            return true;
        }
    }
};

void solve() {
    Node* a;
    Node* b;
    Node* c;
    Node* d;
    Node* e;
    Node* f;
    Node* g;

    Node* root = a = new Node(1);
    root->left = b = new Node(2, root);
    root->right = c = new Node(3, root);
    root->left->left = d = new Node(4, root->left);
    root->left->right = e = new Node(5, root->left);
    root->right->left = f = new Node(6, root->right);
    root->right->right = g = new Node(7, root->right);

    assert(b->lock());
    assert(b->isLocked);
    assert(c->lock());
    assert(b->unlock());
    assert(not b->isLocked);
    assert(d->lock());

    assert(not g->lock());
    assert(c->unlock());
    assert(g->lock());

    assert(f->lock());
    assert(e->lock());
    assert(a->lockedDescendantsCount == 4);
    assert(b->lockedDescendantsCount == 2);
    assert(c->lockedDescendantsCount == 2);
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