#include <bits/stdc++.h>
using namespace std;

int NMP(int a,int b)
{
    if(a==0)
    {
        return 1;
    }
    else if(a<b)
    {
        int x = NMP(a-1,b)+NMP(a,b-1);
        return x;
    }
    else if(a==b)
    {
        int m = NMP(a-1,b);
        return m;
    }
}


int main()
{
    cout<<"Maxx possible matched parenthesis ::::::::::::::::: "<<NMP(4,4)<<" ::::::::::::::::::"<<endl;
    return 0;
}