/*

Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with 
the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.

Delete heavy implementation

*/
#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
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
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

class newQueue{
    
    stack<int> pushStack;
    stack<int> popStack;

public:

    enqueue(int element){
        pushStack.push(element);
    }

    int dequeue(){
        if( popStack.empty()){
            while(!pushStack.empty()){
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        int result = popStack.top();
        popStack.pop();
        return result;
    }
};

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    newQueue Q;
    Q.enqueue(1);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(2);
    cout << Q.dequeue() << endl;
    return 0;
}