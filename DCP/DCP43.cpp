/*

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack. If there are no 
        elements in the stack, then it should throw an error or return null.

max(), which returns the maximum value in the stack currently. If there are no elements 
        in the stack, then it should throw an error or return null.
        
Each method should run in constant time

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

class augmentedStack {
    stack<int> primaryStack;
    stack<int> maxStack;

    void push( int data){
            primaryStack.push( data);
            if( maxStack.empty() || maxStack.top() <= data){
                maxStack.push(data);
            }
    }
    
    void pop(){
        if( !primaryStack.empty()){
            if( maxStack.top() == primaryStack.top()){
                maxStack.pop();
            }
            primaryStack.pop();
        }
    }

    int getMax(){
        return maxStack.top();
    }

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}