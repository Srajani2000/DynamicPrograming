#include <bits/stdc++.h>
using namespace std;
vector<vector<long>> memo;





void print(vector<vector<long>> x)
{
    cout<<endl;
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x[0].size();j++)
        {
            cout<<x[i][j]<<" ";
        }
       
    cout<<endl;
    }
   cout<<endl; 
}




long ConArray(int a,int k,int x,int n,int segment)
{
    // cout<<"a "<<a<<" segment "<<segment<<endl;
    
    
#include <bits/stdc++.h>
using namespace std;


if(a==x && segment==n)
    {
        memo[a][segment] = 1;
        // cout<<" should "<<a<<" "<<segment<<endl;
        return 1;
    }
    else if(segment>=n)
    {
        // cout<<" shoouid be "<<segment<<" "<<a<<endl;
        return 0;
    }
    else 
    {
        long count = 0;
        for(int i=1;i<=k;i++)
        {
        if(i!=a){
            // cout<<" inside the for loop a "<<a<<" segment "<<segment<<endl;
            // cout<<" shahsi "<<i<< " memeo table cpooe" <<memo[i][segment+1]<<endl;
            // print(memo);
            if(memo[i][segment+1]!=-1){
                // cout<<"inside the "<<memo[i][segment+1]<< " "<<a<<" "<<segment+1<<endl;
                count = count+memo[i][segment+1];
            }
            else{
                count = count+ConArray(i,k,x,n,segment+1);
                }  
        }
        }
        // cout<<" count "<<count<<endl;
        memo[a][segment] = count%(10000000000 + 7);
        return count%(10000000000 + 7);
    }
}







int main()
{
    // 100000 100000 1
    int k = 761;
    int n = 99;
    int x = 1;
    memo.resize(k+1,vector<long>(n+1,-1));
    cout<<"The maximum possible way ::::::::::::: "<<ConArray(1,k,x,n,1)%(10000000000 + 7)<<" :::::::::::::"<<endl;
    // print(memo);
    
    return 0;
}