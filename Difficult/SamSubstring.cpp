#include <bits/stdc++.h>
using namespace std;
#define MOD 10000000007;
int SamSum(string x)
{
    long previous = x[0]-'0';
    long sum = previous;
    long mod = pow(10,9)+7;
    for(int i=1;i<x.size();i++)
    {
        cout<<"previous "<<previous<<endl;
        previous = (((x[i]-'0')*(i+1))+(10*(previous)))%mod;
        sum = (sum+previous)%mod;
    }
    cout<<" max is "<<sum<<endl;
 return sum;
}





int main()
{
    SamSum("213676822290");
    return 0;
}
