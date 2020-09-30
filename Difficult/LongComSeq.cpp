#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)  
{  
    return (a > b)? a : b;  
}


int LcsIter(string X,string Y,int m,int n)
{
    int memo[X.length()+1][Y.length()+1];
    int maximum = -1;
    for(int i=0;i<=X.length();i++)
    {
        for(int j=0;j<=Y.length();j++)
        {
            memo[i][j] = 0;
        }
    }
    for(int i = 1;i<=X.length();i++)
    {
        for(int j=1;j<=Y.length();j++)
        {
            if(X[i-1]==Y[j-1])
            {
                memo[i][j] = 1+memo[i-1][j-1];
            }
            else  {
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
            if(memo[i][j]>maximum)
            {
                maximum = memo[i][j];
            }
        }
    }

    return maximum;
}

int lcs(string X,string Y,int m,int n)
{

    if(m==0|| n==0)
    {
        return 0;
    }
    else if(X[m-1]==Y[n-1])
    {
        return 1+lcs(X,Y,m-1,n-1);
    }
    else{
        return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
    }


}

int main()
{

    string A = "1234578345678192";
    string B = "2341556792";
    int maximun =  lcs(A,B,A.length(),B.length()); 
    cout<<"Maximum sub sequence recursive :::::::::: "<<maximun<<" :::::::::::::::::"<<endl;
    cout<<"Maximum sub sequence iterative :::::::::: "<<LcsIter(A,B,A.length(),B.length())<<" :::::::::::::::::"<<endl;
    return 0;
}