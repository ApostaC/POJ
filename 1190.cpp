/*
 * ACCEPTED DFS
 */
/*#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int n,m,ans;
int vmin[25],smin[25];
inline int min(int a,int b){ return a<b?a:b; }
void dfs(int v,int p,int r,int h,int s)
{
	if(v<0 ||p<0) return;
	if(p==0 && v==0)
	{
		ans=min(ans,s);
		return;
	}
	if(v<vmin[p] || s+smin[p]>ans) return;
	for(int rr=r-1;rr>=p;rr--)
		for(int hh=h-1;hh>=p;hh--)
		{
			int tempv=rr*rr*hh;
			if(tempv*m<v) break;
			if(tempv>v) continue;
			dfs(v-rr*rr*hh,p-1,rr,hh,s+2*rr*hh);
		}
}
int main()
{
	for(int i=1;i<=20;i++)
	{
		vmin[i]=vmin[i-1]+i*i*i;
		smin[i]=smin[i-1]+2*i*i;
	}
	cin>>n>>m; ans=1<<30;
	if(vmin[m]>n)
	{
		cout<<0;
		return 0;
	}
	int h,r;
	for(h=n/(m*m);h>=m;h--)
		for(r=sqrt(n/h);r>=m;r--)//(r=m;r*r*h<n;r++)
		{
			int temps=r*r+2*r*h,tempv=r*r*h;
			dfs(n-tempv,m-1,r,h,temps);
		}
	cout<<ans;
}*/