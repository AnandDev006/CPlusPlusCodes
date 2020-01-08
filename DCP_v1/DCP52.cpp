/*

Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should also remove the least recently used item.
get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.

*/

#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

inline void debug(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache{
    public:
    unordered_map<int, Node*> cacheMap;
    int cap;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        this->cap =  capacity;
    }

    int get(int key){
        if( cacheMap.find(key) == cacheMap.end() ){
            return -1;
        } else {
            Node* temp = cacheMap[key];
            remove(temp);
            setHead(temp);
            return temp->value;
        }
    }

    void put(int key, int value){
        if( cacheMap.find(key) != cacheMap.end()){
            Node* temp = cacheMap[key];
            temp->value = value;
            remove(temp);
            setHead(temp);
        } else {
            if( cacheMap.size() >= cap ){
                cacheMap.erase(tail->key);
                remove(tail);
            }
            Node* temp = new Node(key, value);
            setHead(temp);
            cacheMap[key] = temp;
        }
    }

    void remove(Node* temp){
        if( temp->prev != NULL ) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
 
        if( temp->next != NULL ) {
            temp->next->prev = temp->prev;
        }else{
            tail = temp->prev;
        }
    }

    void setHead(Node* temp){
        if( head != NULL){
            head->prev = temp;
        }
 
        temp->next = head;
        temp->prev = NULL;
        head = temp;
 
        if( tail == NULL){
            tail = head;
        }
    }
};

int
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}