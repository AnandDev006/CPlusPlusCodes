// Largest area recatangle in histogram

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int input;
    stack<int> position, height;
    int largest = 0, size = 0;
    
    for( int i = 0 ; i < n ; ++i ){
        cin >> input;
        if( height.size() == 0 && input != 0){
            height.push( input);
            position.push( i);
        } else if( height.top() < input ){
            height.push( input);
            position.push( i);
        } else if( height.top() > input ){
            while( height.top() > input ){
                size = height.top() * ( i - position.top());
                largest = max( largest, size);
                height.pop();
                position.pop();
                if( height.size() == 0)
                    break;
            }
        }
    }height.push( input);
    position.push( 0);

    while( height.size() != 0){
        size = height.top() * ( n - position.top() );
        largest = max( largest, size);
        height.pop();
        position.pop();
    }

    cout << largest << endl;

    return 0;
}