/*
    author : Anand
    Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

    For example, given the following tree and K of 20

            10
          /   \
        5      15
              /  \
            11    15
    Return the nodes 5 and 15.
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

bool findIfSumOfAny2NodesEqualsK(Node *root, ll k)
{
  unordered_multimap<ll, Node *> hashTable;
  queue<Node *> Q;
  Q.push(root);
  while (!Q.empty())
  {
    Node *top = Q.front();
    Q.pop();
    if (hashTable.find(k - top->data) != hashTable.end())
    {
      return true;
    }
    else
    {
      hashTable.insert({top->data, top});
    }
    if (top->left != nullptr)
    {
      Q.push(top->left);
    }
    if (top->right != nullptr)
    {
      Q.push(top->right);
    }
  }
  return false;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->right->left = new Node(11);
  root->right->right = new Node(15);

  assert(findIfSumOfAny2NodesEqualsK(root, 15));
  assert(findIfSumOfAny2NodesEqualsK(root, 16));
  assert(findIfSumOfAny2NodesEqualsK(root, 20));
  assert(findIfSumOfAny2NodesEqualsK(root, 21));
  assert(findIfSumOfAny2NodesEqualsK(root, 25));
  assert(findIfSumOfAny2NodesEqualsK(root, 26));
  assert(findIfSumOfAny2NodesEqualsK(root, 30));

  return 0;
}