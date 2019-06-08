/*
    author : Anand
    Given the head of a singly linked list, swap every two nodes and return its head.

    For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.   
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
typedef pair< ll, ll > ii;

class Node{
    public:
    ll data;
    Node* next;
    Node(ll data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    LinkedList(){
        this->head = this->tail = nullptr;
    }
    void pushBack( ll data){
        Node* node = new Node( data);
        if( this->head == nullptr){
            this->head = this->tail = node;
        }
        this->tail->next = node;
        this->tail = node;
    }

    void reOrder(){
        Node* n1 = nullptr;
        Node* n2 = nullptr;
        Node* prev = nullptr;

        n1 = this->head;
        n2 = n1->next;
        n1->next = n2->next;
        n2->next = n1;
        this->head = n2;
        prev = n1;

        while( prev->next != nullptr && prev->next->next != nullptr ) {
            n1 = prev->next;
            n2 = n1->next;
            n1->next = n2->next;
            n2->next = n1;
            prev->next = n2;
            prev = n1;
        }

        if( prev->next == nullptr ) {
            this->tail = prev;
        }
    }

    void printList(){
        cout << "Head : " << this->head->data << endl;
        Node* node = this->head;
        while(node != nullptr){
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl << "Tail : " << this->tail->data << endl << endl;
    }
};

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList L;
    
    L.pushBack(1);
    L.pushBack(2);
    L.pushBack(3);
    L.pushBack(4);
    L.pushBack(5);
    L.pushBack(6);
    L.pushBack(7);
    L.pushBack(8);
    L.pushBack(9);
    
    L.printList();
    L.reOrder();
    L.printList();

    return 0;
}