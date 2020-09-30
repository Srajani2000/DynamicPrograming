#include <bits/stdc++.h>
using namespace std;

 long long Tanya( long long n, long long k, long long A, long long B)
{
    long long* a = new long long[n];
    for(int i=1;i<n;i++)
    {
         long long  div = -1;
        if(i%k==0)
        {
            div= i/k;
        }
        if(div!=-1)
        a[i] = min(a[i-1]+A,a[div]+B);
        else
        a[i] = a[i-1]+A;
    }
    cout<<" maximum is ::::::::: "<<a[n-1]<<" ::::::::"<<endl;
 return a[n-1];
}


  long long Tanya2( long long x, long long k, long long A, long long B)
{
    if(x<k|| k==1)
    {
        return (x-1)*A;
    }
    if(x%k)
    {
        return Tanya2(x-x%k,k,A,B)+(x%k)*A;
    }
    return Tanya2(x/k,k,A,B)+min(B,(x-x/k)*A);
}



int main()
{
     long long n,k,A,B;
    cin>>n>>k>>A>>B;
    cout<<Tanya(n,k,A,B)<<endl;
    return 0;
}