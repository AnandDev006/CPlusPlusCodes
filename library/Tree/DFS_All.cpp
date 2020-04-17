/*
    author : Anand
    Tree DFS traversals
    pre : 1 2 4 5 3 6 7
    in : 4 2 5 1 6 3 7
    post : 4 5 2 6 7 3 1
*/

#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int mod = 1000000007;
const double zero = 10e-9;
const int N = 3e5, M = N;

int mpow(int base, int exp);
int DP[N];

class Node {
   public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        left = right = NULL;
        this->data = data;
    }
};

void preOrderRec(Node* node) {
    cout << node->data << ' ';
    if (node->left) preOrderRec(node->left);
    if (node->right) preOrderRec(node->right);
}

void inOrderRec(Node* node) {
    if (node->left) inOrderRec(node->left);
    cout << node->data << ' ';
    if (node->right) inOrderRec(node->right);
}

void postOrderRec(Node* node) {
    if (node->left) postOrderRec(node->left);
    if (node->right) postOrderRec(node->right);
    cout << node->data << ' ';
}

void preOrderIter(Node* node) {
    stack<Node*> s;
    s.push(node);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout << temp->data << ' ';
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
}

void inOrderIter(Node* node) {
    stack<Node*> s;
    Node* cur = node;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << ' ';
        cur = cur->right;
    }
}

void postOrderIter(Node* node) {
    stack<Node*> s1, s2;
    s1.push(node);
    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << ' ';
        s2.pop();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrderRec(root);
    cout << '\n';
    inOrderRec(root);
    cout << '\n';
    postOrderRec(root);
    cout << '\n';
    preOrderIter(root);
    cout << '\n';
    inOrderIter(root);
    cout << '\n';
    postOrderIter(root);
    cout << '\n';

    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}