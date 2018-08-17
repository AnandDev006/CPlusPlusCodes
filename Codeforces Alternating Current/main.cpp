#include<bits/stdc++.h>

using namespace std;

int main(){

    string input;
    
    cin >> input;

    stack<char> st;

    for( int i = 0 ; i < input.length() ; ++i){
        
        if( st.size() == 0){
            st.push( input[i] );
        }
        else{
            if( st.top() == input[i])
                st.pop();
            else
                st.push( input[i]);
        }
    }

    if( st.size() == 0)
        cout << "YES" << endl;
    else
    cout << "NO" << endl;

    return 0;
}