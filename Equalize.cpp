#include <bits/stdc++.h>
using namespace std;

int Equalize(string arr,string arr2)
{
    int previous = 0;
    if(arr[0]!=arr2[0])previous = 1;
    bool flag = true;
    for(int i=1;i<arr.size();i++)
    {if(arr[i]!=arr2[i])
        {if(arr[i-1]==arr2[i] && arr[i]==arr2[i-1])
            {if(flag){previous = previous;flag = false;}
                else{previous = previous+1;flag=true;}}
            else{previous = previous+1;flag = true;}
        }}
    return previous;
}

int main()
{
    string x;
    string y;
    int k;
    cin>>k;
    cin>>x;
    cin>>y;
    Equalize(x,y);
    return 0;
}