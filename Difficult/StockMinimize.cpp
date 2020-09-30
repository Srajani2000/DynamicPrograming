#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)  
{  
    return (a > b)? a : b;  
}


int StockMinimize(vector<int>  arr)
{
    long a[arr.size()] = {0};
    long maxima  = arr[0] ;
    long minima = 0;
    long profit = 0;
    int totalStock = 1;
    long stockprice = arr[0];
    long bigmax = 0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>bigmax)
        {
            bigmax= arr[i];
        }
        if(arr[i]>maxima)
        {
            maxima = arr[i];
            profit = max(profit,(arr[i]*totalStock)-stockprice);
            cout<<profit<<endl;        
        }
            stockprice = stockprice+arr[i];
            totalStock++;
       
    } 

return profit;
}


int main()
{
    vector<int> x{1,3,1,2};
    cout<<StockMinimize(x)<<endl;
}