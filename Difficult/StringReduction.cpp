# include <iostream>
using namespace std;
// int x[50000][100000];
int Strred(string s)
{
    int counta = 0,countb = 0,countc= 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a')
        {
            counta++;
        }
        else if(s[i]=='b')
        {
            countb++;
        }
        else if(s[i]=='c')
        {
            countc++;
        }
    }



    if(counta==s.size()||countb==s.size()||countc==s.size())
    {
        return s.size();
    }
    else{
    if(((counta%2==0)&&(countb%2==0)&&(countc%2==0)) ||((counta%2==1)&&(countb%2==1)&&(countc%2==1)))
    {
        return 2;
    }  
    else 
    {
        return 1;
    }
    }
}

int main()
{
    
    cout<<Strred("aabbbcbc")<<endl;
    return 0;
}