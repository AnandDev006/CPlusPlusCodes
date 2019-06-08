/*
    author : Anand
    Given the head to a singly linked list, where each node also has a “random” pointer that points to 
    anywhere in the linked list, deep clone the list.
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
  Node *next;
  Node *random;
  Node(ll data)
  {
    this->data = data;
    this->next = this->random = nullptr;
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

Node *deepClone(Node *head)
{

  Node *newHead = new Node(head->data);

  unordered_map<Node *, Node *> table;

  Node *headIterator = head;
  Node *newHeadIterator = newHead;
  table.insert({headIterator, newHeadIterator});

  headIterator = headIterator->next;

  // Clone base list with only next pointers
  while (headIterator != nullptr)
  {
    newHeadIterator->next = new Node(headIterator->data);
    newHeadIterator = newHeadIterator->next;
    table.insert({headIterator, newHeadIterator});
    headIterator = headIterator->next;
  }

  headIterator = head;
  newHeadIterator = newHead;

  // Clone the random pointers
  while (headIterator != nullptr)
  {
    if (headIterator->random != nullptr)
    {
      newHeadIterator->random = table[headIterator->random];
    }
    headIterator = headIterator->next;
    newHeadIterator = newHeadIterator->next;
  }

  return newHead;
}

bool verifyDeepClone(Node *head1, Node *head2)
{
  Node *head1Iterator = head1;
  Node *head2Iterator = head2;
  while (head1Iterator != nullptr)
  {
    if ((head1Iterator->data != head2Iterator->data) ||
        (head1Iterator->random != nullptr && head1Iterator->random->data != head2Iterator->random->data) ||
        (head1Iterator->next != nullptr && head1Iterator->next->data != head2Iterator->next->data))
    {
      return false;
    }
    head1Iterator = head1Iterator->next;
    head2Iterator = head2Iterator->next;
  }
  cout << "Deep Clone Successful" << endl;
  return true;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(7);

  head->next->random = head;
  head->next->next->random = head->next->next;
  head->next->next->next->random = head->next->next->next->next->next->next;

  assert(verifyDeepClone(deepClone(head), head));

  return 0;
}