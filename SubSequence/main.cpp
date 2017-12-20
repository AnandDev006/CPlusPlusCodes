#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

char key[]="hackerrank";

int check(char []);

int main(){
    char in[10000];
    int i,n;
    cin>>n;

    for(i=0;i<n;++i){
        cin>>in;
        if( (check(in))==0 )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

int check (char a[]){
    int x=0,y=0;
    char temp[11]={'\0'};
    while(key[x]!='\0'){
        for(;a[y]!='\0';y++)
            if(a[y]==key[x]){
                temp[x]=a[y++];
                break;
            }
        x++;
    }

    if( strcmp("hackerrank",temp)==0 )
        return 0;

    return 1;
}