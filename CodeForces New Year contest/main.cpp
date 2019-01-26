fun1(){
    int arr[3];
    
    for( int i = 0 ; i < 3 ; ++i)
        cin >> arr[i];    
    
    for( int i = 0 ; i < 3 ; ++i){
        for( int j = i+1 ; j < 3 ; ++j){
            if( arr[i] + (j-i) < arr[j]){
                arr[j] -= ( abs(arr[i] - arr[j]) - ( j - i ) );
            } else {
                arr[i] = arr[j] - ( j - i );
            }
        }
    }

    int sum   = 0;

    for( int i = 0 ; i < 3 ; ++i )
        sum += arr[i];

    cout << sum << endl;

    return 0;
}

fun2(){
    set<ii> obelisk, clue;

    int n;
    cin >> n;

    ii temp;

    for( int i = 0 ; i < n ; ++i ){
        cin >> temp.X >> temp.Y;
        obelisk.insert(temp);
    }

    for( int i = 0 ; i < n ; ++i ){
        cin >> temp.X >> temp.Y;
        clue.insert(temp);
    }

    cout << (*obelisk.begin()).X + (*clue.rbegin()).X << " " << (*obelisk.begin()).Y + (*clue.rbegin()).Y <<endl ;
}

fun3(){
    int n;
    cin >> n;
    
    vector<int> factors;
    for( int i = 1 ; i <= sqrt(n) ; ++i )
        if( n % i == 0 ){
            factors.push_back(i);
            factors.push_back(n/i);
        }

    set<int> anss;
    for( int factor : factors){
        anss.insert( ( (n/factor) * ( 2*1 + ( (n/factor) - 1)*factor ))/2 );
    }

    for( int ans : anss)
        cout << ans << " ";
}