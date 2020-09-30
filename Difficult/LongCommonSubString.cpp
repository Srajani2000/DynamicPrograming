#include <bits/stdc++.h>
using namespace std;

int FindSubstring(string a,string b,int &endingindex)
{
int memo[a.length()+1][b.length()+1] ;
int maxlength ;
maxlength = -1;

for(int i=0;i<a.length()+1;i++)
{
for(int j=0;j<b.length()+1;j++)
{
    memo[i][j] = 0;
}    
}

for(int i=1;i<a.length()+1;i++)
{
    for(int j=1;j<b.length()+1;j++)
    {
        if(a[i-1]==b[j-1])
        {
            memo[i][j]= memo[i-1][j-1]+1;
        }
        if(maxlength<memo[i][j])
        {
            maxlength = memo[i][j];
            endingindex = j;
        }
    }
}
return maxlength;
}


int main()
{
int index;
string A = "OldSite:GeeksforGeeks.org";
string B = "NewSite:GeeksQuiz.com"; 
int x = FindSubstring(A,B,index);
cout<<" long sub string is ::::::::::::::::::"<< A.substr(index - x, x)<<":::::::::::::::::::"<<endl;
return 0;

}