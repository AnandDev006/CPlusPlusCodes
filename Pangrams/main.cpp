#include <iostream>

using namespace std;

int main() {
    int sum =0 , i=0 , j=0 , check[26]={0};
    string a;
    char ch;
    getline(cin,a);

    for(i=0;a[i]!='\0';++i)
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i]+=32;

    for(ch='a',i=0;ch<='z';++ch)
        for(j=0;a[j]!='\0';++j)
            if(a[j]==ch){
                check[i++]=1;
                break;
            }

    for(i=0;i<26;++i)
        sum+=check[i];

    if(sum==26)
        cout<<"pangram";
    else
        cout<<"not pangram";
    return 0;
}