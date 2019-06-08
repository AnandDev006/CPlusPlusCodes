/*
    author : Anand

  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.
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

class Node
{
public:
  ll data;
  Node *left;
  Node *right;
  Node *parent;
  Node(ll data, Node *parent)
  {
    this->data = data;
    this->left = this->right = nullptr;
    this->parent = parent;
  }
};

void printArray(const vector<ll> &arr)
{
  cout << "[ ";
  for (ll i = 0; i < sz(arr) - 1; ++i)
  {
    cout << arr[i] << ", ";
  }
  cout << arr[sz(arr) - 1] << " ]" << endl;
}

ll getLowestCommonAncestor(Node *A, Node *B)
{
  stack<Node *> pathToA;
  stack<Node *> pathToB;
  while (A != nullptr)
  {
    pathToA.push(A);
    A = A->parent;
  }
  while (B != nullptr)
  {
    pathToB.push(B);
    B = B->parent;
  }

  ll commonAncestor;

  while (!pathToA.empty() && !pathToB.empty())
  {
    commonAncestor = pathToA.top()->data;
    pathToA.pop();
    pathToB.pop();
    if (pathToA.top() != pathToB.top())
    {
      cout << commonAncestor << endl;
      return commonAncestor;
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = new Node(1, nullptr);
  root->left = new Node(2, root);
  root->right = new Node(3, root);
  root->left->left = new Node(4, root->left);
  root->left->right = new Node(5, root->left);
  root->right->left = new Node(6, root->right);
  root->right->right = new Node(7, root->right);
  root->left->left->left = new Node(8, root->left->left);
  root->left->right->left = new Node(9, root->left->right);

  assert(getLowestCommonAncestor(root->left->left->left, root->left->right->left) == 2);
  assert(getLowestCommonAncestor(root->left->left->left, root->right->left) != 2);
  assert(getLowestCommonAncestor(root->left->left->left, root->right->left) == 1);

  return 0;
}