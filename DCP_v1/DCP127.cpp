/*
    author : Anand
    Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number in reversed order.

    For example, the following linked list:

    1 -> 2 -> 3 -> 4 -> 5
    is the number 54321.

    Given two linked lists in this format, return their sum in the same linked list format.

    For example, given

    9 -> 9
    5 -> 2
    return 124 (99 + 25) as:

    4 -> 2 -> 1
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

list<ll> addLinkedListNumberRepresentation(list<ll> num1, list<ll> num2)
{
  list<ll> sum;
  ll carry = 0;
  ll dig1, dig2, dig;
  while (!num1.empty() && !num2.empty())
  {
    dig1 = num1.front();
    dig2 = num2.front();

    dig = dig1 + dig2 + carry;

    sum.push_back(dig % 10);

    carry = dig > 9 ? 1 : 0;

    num1.pop_front();
    num2.pop_front();
  }
  while (!num1.empty())
  {
    dig1 = num1.front();

    dig = dig1 + carry;

    sum.push_back(dig % 10);

    carry = dig > 9 ? 1 : 0;

    num1.pop_front();
  }
  while (!num2.empty())
  {
    dig2 = num2.front();

    dig = dig2 + carry;

    sum.push_back(dig % 10);

    carry = dig > 9 ? 1 : 0;

    num2.pop_front();
  }
  if (carry == 1)
  {
    sum.push_back(carry);
  }
  printArray(vector<ll>(all(sum)));
  return sum;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(addLinkedListNumberRepresentation({9, 9}, {5, 2}) == list<ll>({4, 2, 1}));
  assert(addLinkedListNumberRepresentation({1, 2, 3, 4, 5}, {1, 2, 3, 4}) == list<ll>({2, 4, 6, 8, 5}));
  assert(addLinkedListNumberRepresentation({1, 2, 3, 4, 5}, {1, 2, 3, 8}) == list<ll>({2, 4, 6, 2, 6}));

  return 0;
}