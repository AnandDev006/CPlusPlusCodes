/*
    author : Anand
    An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev 
    fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement 
    an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which 
    returns the node at index.
*/

#include <bits/stdc++.h>

#define zero 10e-9
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

class Node {
   public:
    int data;
    Node* both;
    Node(int data) {
        this->data = data;
        this->both = nullptr;
    }
};

class LinkedList {
   public:
    Node* head;
    Node* tail;
    LinkedList(Node* node) {
        this->head = this->tail = node;
        this->head->both = nullptr;
        this->tail->both = nullptr;
    }

    void add(Node* node) {
        this->tail->both = (Node*)(uintptr_t(this->tail->both) ^ uintptr_t(node));
        node->both = (Node*)(uintptr_t(this->tail) ^ uintptr_t(nullptr));
        this->tail = node;
    }

    Node* get(int index) {
        Node* prevNode = nullptr;
        Node* curNode = this->head;
        Node* nextNode = nullptr;

        for (int i = 0; i < index; ++i) {
            nextNode = (Node*)(uintptr_t(prevNode) ^ uintptr_t(curNode->both));
            prevNode = curNode;
            curNode = nextNode;
        }
        return curNode;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LinkedList* ll = new LinkedList((new Node(1)));
    ll->add(new Node(2));
    ll->add(new Node(3));
    ll->add(new Node(4));
    ll->add(new Node(5));
    ll->add(new Node(6));
    ll->add(new Node(7));

    cout << ll->get(2)->data << endl;

    return 0;
}