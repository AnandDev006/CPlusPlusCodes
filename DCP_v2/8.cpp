/*
    author : Anand

    This problem was asked by Google.

    A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

    Given the root to a binary tree, count the number of unival subtrees.

    For example, the following tree has 5 unival subtrees:

           0
          / \
         1   0
            / \
           1   0
          / \
         1   1
*/

#include <bits/stdc++.h>

#define zero 10e-9
#define sz(a) int((a).size())
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

class Node {
   public:
    Node* left;
    Node* right;
    int data;
    Node(int data, Node* left = nullptr, Node* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

pair<bool, pair<int, int> > helper(Node* node) {
    if (node->left == nullptr && node->right == nullptr) return mp(true, mp(node->data, 1));

    pair<bool, pair<int, int> > isLeftUnival = node->left == nullptr ? mp(true, mp(node->data, 0)) : helper(node->left);

    pair<bool, pair<int, int> > isRightUnival = node->right == nullptr ? mp(true, mp(node->data, 0)) : helper(node->right);

    if (isLeftUnival.X && isRightUnival.X && isLeftUnival.Y.X == node->data && isRightUnival.Y.X == node->data) {
        return mp(true, mp(node->data, isLeftUnival.Y.Y + isRightUnival.Y.Y + 1));
    }
    return mp(false, mp(node->data, isLeftUnival.Y.Y + isRightUnival.Y.Y));
}

int getUnivalTreeCount(Node* root) {
    return helper(root).Y.Y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Node* root = new Node(0, new Node(1), new Node(0, new Node(1, new Node(1), new Node(1)), new Node(0)));
    assert(getUnivalTreeCount(root) == 5);
    return 0;
}