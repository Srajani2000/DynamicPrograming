

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a(200005);
map<int,int> hashtable;
int ans,f;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		hashtable[a[i]]=hashtable[a[i]-1]+1;
		if(hashtable[a[i]]>ans)
		{
			ans=hashtable[a[i]];
			f=a[i];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	if(a[i]==f-ans+1)
	{
		printf("%d ",i);
		ans--;
	}
	return 0;
}