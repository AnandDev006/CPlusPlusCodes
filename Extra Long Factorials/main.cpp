
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d;
    d.push_back(1);

    for (int i = 2; i <= n; ++i) {
        for (auto it = d.begin(); it != d.end(); ++it)
            *it *= i;

        for (size_t j = 0; j < d.size(); ++j) {
            if (d[j] < 10)
                continue;

            if (j == d.size() - 1)
                d.push_back(0);

            d[j + 1] += d[j] / 10;
            d[j] %= 10;
        }
    }

    for (auto it = d.rbegin(); it != d.rend(); ++it)
        cout << *it;

    return 0;
}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std ;

const int ArraySize = 160;

class BigInt{
    int digits[ArraySize] ;
    int p ;
public:
    BigInt() ;
    BigInt( string numb ) ;
    void Assign ( string num );
    BigInt operator= ( const BigInt &b ) ;
    BigInt operator* ( const BigInt &a ) ;
    void Factorial ( int LO , int n );
    void print ( ) ;
};

void BigInt :: Assign ( string num ) {
    int i = num.size() - 1 ;
    p = i ;
    string temp = num ;
    while ( i >= 0 ){
        digits[i] = temp.back() - '0' ;
        temp.pop_back();
        --i;
    }
    for ( i = p + 1 ; i < ArraySize ; ++i )
        digits[i] = 0 ;
}

BigInt ::BigInt() {
    for( int i = 0 ; i < ArraySize ; ++i )
        digits[i] = 0 ;
    p=0;
}

BigInt :: BigInt ( string numb ) {
    Assign( numb );
}

BigInt BigInt :: operator= ( const BigInt &b ) {
    int i ;
    for( i = 0 ; i <= b.p ; ++i )
        digits[i] = b.digits[i] ;
    p = b.p ;
    for( ; i < ArraySize ; ++i )
        digits[i] = 0 ;
    return *this;
}


BigInt BigInt :: operator * ( const BigInt &a ) {
    BigInt temp ;
    temp.p = p + a.p ;
    int CarryOver = 0 ;
    int t1 = p ;
    int t2 = a.p ;
    int t = 0 ;
    int d = 0;
    for ( ; t2>=0 ; --t2 , t -= (a.p - t2 ) ){
        t = p + a.p ;
        t -= ( a.p - t2 ) ;
        for ( t1 = p ; t1 >= 0 ; --t1 , --t ){
            d = digits[t1] * a.digits[t2] ;
            CarryOver = ( temp.digits[t] + d ) / 10 ;
            temp.digits[t] = ( temp.digits[t] + d ) % 10 ;
            temp.digits[t-1] += CarryOver ;
        }
    }
    if( CarryOver != 0 ){
        for( int i = temp.p ; i >= 0 ; --i ){
            temp.digits[i+1] = temp.digits[i] ;
        }
        temp.digits[0] = CarryOver ;
        ++temp.p;
    }
    return temp;
}

void BigInt :: Factorial ( int LO , int n ) {
    BigInt temp ;
    string t ;
    for( int i = LO ; LO > 0 ; --LO ){
        t = to_string( n - LO + 1 ) ;
        temp.Assign( t ) ;
        *this = *this * temp ;
    }
}

long long RecFactorial ( int n ){
    if ( n == 0 || n == 1)
        return 1;
    else
        return n * RecFactorial( n - 1);
}

void BigInt ::print() {
    cout<<endl;
    for( int i = 0 ; i <= p ; ++i )
        cout<<digits[i];
}

int main(){
    int Num;
    cin >> Num;
    if( Num > 100 ){
        cout <<endl<< "Enter a number within 0 - 100 " ;
        return 0 ;
    }
    if ( Num <= 20 )
        cout << RecFactorial( Num ) ;
    else{
        string FactOf20 = "2432902008176640000";
        BigInt fact( FactOf20 );
        int LeftOver = Num - 20 ;
        fact.Factorial( LeftOver , Num ) ;
        fact.print();
    }
    return 0;
}

*/

//     OR
/*
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int val;
    int carry = 0;
    cin >> val;
    vector <int> arr(200, 0);
    arr[0] = 1; //Initial product = 1

    int k = 0; //Current size of the number stored in arr

    for(int i = 1; i <= val; i++) {
        for(int j = 0;j <= k; j++) {
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while(carry) { //Propogate the remaining carry to higher order digits
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }
    }
    for(int i = k; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
 */
