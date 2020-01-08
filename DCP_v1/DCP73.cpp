/*
	author : Anand
	Given the head of a singly linked list, reverse it in-place.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;

class Node{
	public:
	ll data;
	Node* next;
	Node(ll data){
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedListT{
	public:
	Node* head;
	LinkedListT(){
		head=nullptr;
	}

	void addAtBegin(ll data){
		Node* n = new Node(data);
		n->next = head;
		head = n;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	LinkedListT L;
	L.addAtBegin(1);
	L.addAtBegin(2);
	L.addAtBegin(3);
	L.addAtBegin(4);
	L.addAtBegin(5);

	Node* head = L.head;
	while( head != nullptr){
		cout << head->data << " : ";
		head = head->next;
	}

	cout << endl;
	head = L.head;
	{
		if( head != nullptr && head->next != nullptr) {
			Node* currNode = head;
			Node* nextNode = nullptr;
			Node* prevNode = nullptr;
			
			while( currNode != nullptr) {
				nextNode = currNode->next;
				currNode->next = prevNode;
				prevNode = currNode;
				currNode = nextNode;
			}
			L.head = prevNode;
		}
	}
	

	head = L.head;
	while( head != nullptr){
		cout << head->data << " : ";
		head = head->next;
	}
	

	return 0;
}