/*
  author : Anand
	Problem 6
	This problem was asked by Google.

	An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

	If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

class Node {
public:
	int data;
	Node* both;
};


class XORLL {
	Node* XOR (Node *a, Node *b) { 
	    return reinterpret_cast<Node *>(
	      reinterpret_cast<uintptr_t>(a) ^ 
	      reinterpret_cast<uintptr_t>(b)); 
	}
public:
	Node* head;
	Node* tail;
	XORLL() {
		head = tail = nullptr;
	}

	void pushback(int _data) {
		Node* temp = new Node();
		temp->data = _data;
		temp->both = tail;
		if(head == nullptr) {
			head = temp;
		}
		if(tail) {
			tail->both = XOR(temp, tail->both);	
		}
		tail = temp;
	}

	void pushfront(int _data) {
		Node* temp = new Node();
		temp->data = _data;
		temp->both = head;
		if(tail == nullptr) {
			tail = temp;
		}
		if(head) {
			head->both = XOR(temp, head->both);	
		}
		head = temp;
	}


	int get(int index) {
		Node* cur = head;
		Node* prev = nullptr;
		Node* next;
		while(cur && index-- > 0) {
			next = XOR(cur->both, prev);
			prev = cur;
			cur = next;
		}
		return cur->data;
	}

	void printList() {
		Node* cur = head;
		Node* prev = nullptr;
		Node* next;
		while(cur) {
			cout << cur->data << " : ";
			next = XOR(cur->both, prev);
			prev = cur;
			cur = next;
		}
		cout << endl;
	}
};

void solve() {
	XORLL x = XORLL();
	x.pushback(10);
	x.pushback(20);
	x.pushback(30);
	x.pushback(40);
	x.pushfront(5);
	x.pushfront(1);
	x.printList();
	debug(x.get(2));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}