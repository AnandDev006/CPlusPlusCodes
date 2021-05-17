/*
An arborist that operates a plant store in Brooklyn, NY would like to improve
their online sales by improving their ratings.

In order to become a five-star store, they must maintain a certain threshold
percentage of five-star ratings. Given their current situation, find the minimum
number of additional five-star ratings they must receive to meet the threshold.
The overall online store percentage is calculated by taking the sum of
percentages of five-star ratings for each product.

Examples
Example 1:
Input:
productCount = 3

productRatings = [[4,4],[1,2],[3,6]] where each entry is [five-star reviews,
total reviews]

threshold = 77

Output: 3
Explanation :
We need the sum of the percentages of five-star ratings for each product to add
up to the threshold.

The current percentage of five-star ratings for this seller is ((4/4) + (1/2) +
(3/6))/3 = 66.66%

If we add a five star review to product #2, their threshold becomes ((4/4) +
(2/3) + (3/6))/3 = 72.22%

If we add another five star review to product #2, their threshold becomes ((4/4)
+ (3/4) + (3/6))/3 = 75%

If we add a five star review to product #3, their threshold becomes ((4/4) +
(3/4) + (4/7))/3 = 77.38%

At this point, the 77% threshold is met. The answer is 3, because there is no
other way to add less ratings and achieve 77% or more.

Constraints:
There is always at least one product, and the threshold is between 1 and 99
inclusive. All values are positive.
*/

/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;
struct node {
  int num;
  int den;
  double inc;
  node(int _num, int _den) {
    num = _num;
    den = _den;
    inc = ((double)(num + 1) / (double)(den + 1)) -
          ((double)(num) / (double)(den));
  }
  bool operator<(node other) const { return inc < other.inc; }
  string toString() { return to_string(num) + "/" + to_string(den); }
};

signed main() {
  vector<vector<int>> ratings({{4, 4}, {1, 2}, {3, 6}});
  int n = ratings.size();
  double threshold = 77;
  double required = n * threshold;
  double current = 0;
  priority_queue<node> pq;
  // set<node> s;
  for (auto rating : ratings) {
    pq.push({rating[0], rating[1]});
    current += ((double)(100 * rating[0]) / (double)rating[1]);
  }
  int count = 0;
  while (current < required) {
    ++count;
    node top = pq.top();
    pq.pop();
    pq.push({top.num + 1, top.den + 1});
    current += top.inc * 100;
  }

  cout << count << endl;

  return 0;
}