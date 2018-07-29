#include<bits/stdc++.h>

using namespace std;

unordered_map< int, int> memoTable;

static int n;

int fun(const string& data, int pos){
    ++n;    
    // Base Cases
    if( pos == data.length())
        return 1;
    if( data[pos] == '0')
        return 0;
    
    int result = 0;
    
    if( memoTable[pos])
        result = memoTable[pos];
    else
        result = fun( data, pos + 1);

    if( memoTable[pos+2])
        result += memoTable[pos+2];
    else{
        if( stoi( data.substr(pos,2)) <= 26  && (pos + 2) <= data.length() ){
            result += fun( data, pos + 2);
        }
    }

    memoTable[pos] = result;

    return result;
}

int main(){
    
    string input;
    
    cin >> input;

    cout << fun(input, 0) << " " << n << endl;

    return 0;
}
