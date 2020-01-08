/*
    author : Anand
    Print the nodes in a binary tree level-wise
*/

#include <bits/stdc++.h>

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

void printArray(const vector<ll> &arr)
{
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

class node
{
  public:
    node *left;
    node *right;
    ll data;
    node(ll data)
    {
        this->left = this->right = nullptr;
        this->data = data;
    }
};

void printLevelWise(node *root)
{
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *temp = Q.front();
        Q.pop();
        cout << temp->data << endl;
        if (temp->left != nullptr)
        {
            Q.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            Q.push(temp->right);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    printLevelWise(root);

    return 0;
}