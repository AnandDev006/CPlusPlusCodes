#include <iostream>

using namespace std;
int main() {

    int i,n, *p;
    cin>>n;
    p=new int[n];

    for(i=0;i<n;++i)
        cin>>p[i];

    for(i=1;i<=n;++i){
        for(int j=0;j<n;++j)
            if(p[j]==i){
                for(int k=0;k<n;++k)
                    if(p[k]==j+1){
                        cout<<k+1<<endl;
                        break;
                    }
                break;
            }
    }

    delete(p);
    return 0;
}