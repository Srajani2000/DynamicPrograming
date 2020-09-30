#include <bits/stdc++.h>
using namespace std;
string result = "";
int NMP(int a,int b,string str)
{
    if(a==0)
    {
        for(int i=0;i<b;i++)
        {
        str = str+")";
        }
        result = result+str+"\n";
        return 1;
    }
    else if(a<b)
    {
        int x = NMP(a-1,b,str+"(")+NMP(a,b-1,str+")");
        return x;
    }
    else if(a==b)
    {
        int m = NMP(a-1,b,str+"(");
        return m;
    }
}


int main()
{
    cout<<"Maxx possible matched parenthesis ::::::::::::::::: "<<NMP(7,7,"")<<" ::::::::::::::::::"<<endl;
    cout<<endl;
    cout<<result<<endl;
    return 0;
}