/*
    author : Anand
    Given a binary tree, return the level of the tree with minimum & maximum sum.
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

pair<ll, ll> findTreeLevelWithMaxSum(Node *root)
{
  vector<ll> levelSums(1000, 0);
  queue<pair<Node *, ll>> Q;

  Q.push(mp(root, 0));

  ll numOfLevels = 0;

  while (!Q.empty())
  {
    pair<Node *, ll> node = Q.front();
    Q.pop();
    levelSums[node.Y] += node.X->data;
    if (node.X->left != nullptr)
    {
      numOfLevels = max(numOfLevels, node.Y + 1);
      Q.push(mp(node.X->left, node.Y + 1));
    }
    if (node.X->right != nullptr)
    {
      numOfLevels = max(numOfLevels, node.Y + 1);
      Q.push(mp(node.X->right, node.Y + 1));
    }
  }

  levelSums.resize(numOfLevels + 1);

  ll maxSum = *max_element(all(levelSums));
  ll maxSumLevel = (find(all(levelSums), maxSum) - levelSums.begin());
  cout << "With level 0 being root level" << endl;
  cout << "( maxSumLevel, maxSum) = (" << maxSumLevel << ", " << maxSum << ")" << endl;
  return mp(maxSumLevel, maxSum);
}

pair<ll, ll> findTreeLevelWithMinSum(Node *root)
{
  vector<ll> levelSums(1000, 0);
  queue<pair<Node *, ll>> Q;

  Q.push(mp(root, 0));

  ll numOfLevels = 0;

  while (!Q.empty())
  {
    pair<Node *, ll> node = Q.front();
    Q.pop();
    levelSums[node.Y] += node.X->data;
    if (node.X->left != nullptr)
    {
      numOfLevels = max(numOfLevels, node.Y + 1);
      Q.push(mp(node.X->left, node.Y + 1));
    }
    if (node.X->right != nullptr)
    {
      numOfLevels = max(numOfLevels, node.Y + 1);
      Q.push(mp(node.X->right, node.Y + 1));
    }
  }

  levelSums.resize(numOfLevels + 1);

  ll minSum = *min_element(all(levelSums));
  ll minSumLevel = (find(all(levelSums), minSum) - levelSums.begin());
  cout << "With level 0 being root level" << endl;
  cout << "( minSumLevel, minSum) = (" << minSumLevel << ", " << minSum << ")" << endl;
  return mp(minSumLevel, minSum);
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = new Node(26);
  root->right = new Node(3);
  root->right->right = new Node(3);
  root->left = new Node(10);
  root->left->left = new Node(4);
  root->left->left->right = new Node(30);
  root->left->right = new Node(6);

  assert(findTreeLevelWithMaxSum(root) == mp(ll(3), ll(30)));
  assert(findTreeLevelWithMinSum(root) == mp(ll(1), ll(13)));

  return 0;
}