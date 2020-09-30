#include <bits/stdc++.h>
#include<cstdio>
using namespace std;

long long Divisibility(string s)
{
   long long count = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='4' || s[i]=='8' || s[i]=='0')
        {
            count++;
        }
    }
    for(int i=0;i<s.size()-1;i++)
    {
        int h = (s[i]-'0')*10+(s[i+1]-'0');
        if(h%4==0)
        {
            count = count+i+1;
        }
    }

    return count;
}
int main()
{
    string s;
    getline (cin, s);
    cout<<Divisibility(s)<<endl;
    return 0;
}