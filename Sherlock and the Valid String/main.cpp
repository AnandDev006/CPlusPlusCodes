#include<iostream>
#include<map>

using namespace std;

int abs(int a)
{
    if(a < 0)
        return -a;
    else return a;
}

int main()
{
    int max = 0;
    string input;
    cin>>input;
    int maap[26] = {0};
    for(int i=0;i<input.size();i++)
    {
        maap[input[i] - 'a']++;
        if(max < maap[input[i] - 'a'])
            max = maap[input[i] - 'a'];
    }
    map<int, int> m;
    for(int i=0;i<26;i++)
    {
        if(maap[i])
        {
            if(m.find(maap[i]) != m.end())
                m[maap[i]]++;
            else
                m[maap[i]] = 1;
        }
    }

    if(m.size() > 2)
        cout<<"NO\n";
    else
    {
        if(m.size() == 1)
        {
            cout<<"YES\n";
            return 0;
        }
        map<int, int>::iterator i, j;
        j = m.begin();
        i = j;
        j++;
        if((i->first == 1 && i->second == 1) || (j->first == 1 && j->second == 1)) //case where there is one occurance of one character
        {
            cout<<"YES\n";
            return 0;
        }
        if(abs(i->first - j->first) > 1)
        {
            cout<<"NO\n";
            return 0;
        }
        else
        {
            if(i->second != 1 && j->second != 1)
            {
                cout<<"NO\n";
                return 0;
            }
            else if( i->first == max && i->second == 1 || j->first == max && j->second == 1 ) // THIS TEST CASE WAS MISSING
            {
                cout<<"YES\n";
                return 0;
            }
        }
        cout<<"NO\n";
    }
    return 0;
}