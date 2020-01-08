/*
    author : Anand
    Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. 
    A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a 
    subtree of itself.
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
  Node(ll data)
  {
    this->data = data;
    this->left = this->right = nullptr;
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

bool areIdentical(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL)
    return true;

  if (root1 == NULL || root2 == NULL)
    return false;

  return (root1->data == root2->data &&
          areIdentical(root1->left, root2->left) &&
          areIdentical(root1->right, root2->right));
}

bool isSubtree(Node *root1, Node *root2)
{
  if (root2 == NULL)
    return true;

  if (root1 == NULL)
    return false;

  if (areIdentical(root1, root2))
    return true;

  return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root1 = new Node(26);
  root1->right = new Node(3);
  root1->right->right = new Node(3);
  root1->left = new Node(10);
  root1->left->left = new Node(4);
  root1->left->left->right = new Node(30);
  root1->left->right = new Node(6);

  Node *root2 = new Node(10);
  root2->right = new Node(6);
  root2->left = new Node(4);
  root2->left->right = new Node(30);

  assert(isSubtree(root1, root2));

  return 0;
}