

#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)  
{  
    return (a > b)? a : b;  
}









 vector<int> MaxSubSeqSum2(vector<int> arr)
 {

    int maximum2 = arr[0];
    // vector<int> result(arr.size(),0);
    // result[0] = arr[0];
    // maximum2   = result[0];


    int maximum = arr[0];
    //  vector<int> b(arr.size());
    //  b= arr;
    // for(int i=0;i<b.size();i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    for(int i=1;i<arr.size();i++)
    {


        maximum = max(max(maximum,arr[i]),maximum+arr[i]);
        maximum2 =max(maximum2,max(maximum2+arr[i],arr[i]));


    }
        vector<int> result2;
        result2.push_back(maximum2);
        result2.push_back(maximum);
    // cout<<endl;

    // for(int i=0;i<b.size();i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    return result2;
 }



















int Kadens(vector<int> arr)
{
    int maximum ;
    vector<int> result(arr.size(),0);
    result[0] = arr[0];
    maximum   = result[0];
    for(int i=1;i<arr.size();i++)
    {
        result[i] = max(result[i-1]+arr[i],arr[i]);
        if(result[i]>maximum)
        {
            maximum = result[i];
        }
   
    }
    
    //  cout<<"::::::::::::::::: Length of subarray :::::::::::::::"<<endl;
    //  for(int i=0;i<subarrlength.size();i++)
    //  {
    //      cout<<subarrlength[i]<<"::";
    //  }

    //  cout<<endl;
    return maximum;
 }


 int MaxSubSeqSum(vector<int> arr)
 {
     int maximum = arr[0];
     vector<int> b(arr.size());
     b= arr;
    // for(int i=0;i<arr.size();i++)
    // {
    //     b[i] =  arr[i];
    // }
    // for(int i=0;i<b.size();i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            b[i] = max(b[i],arr[i]+b[j]);
            if(b[i]>maximum)
            {
                maximum = b[i];
            }
        }
    }
    // cout<<endl;

    // for(int i=0;i<b.size();i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    return maximum;
 }



int main()
{
    vector<int> arr{2 ,-1, 2, 3, 4, -5,};
    vector<int> r = MaxSubSeqSum2(arr);
    cout<<r[0]<<" "<<r[1]<<" "<<endl;
    // cout<<" the max sub sequence sum is :::::::::::::::::: "<<MaxSubSeqSum(arr)<<" ::::::::::::::::::"<<endl;
    // cout<<"max sum subarray ::::::::::::::: "<<Kadens(arr)<<" ::::::::::::::"<<endl;

    return 0;

}