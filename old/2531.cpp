/* ACCEPTED
 * DFS
 */
/*
#include <iostream>
#include <string.h>
using namespace std;
int n,c[30][30],ans,set[30];
void dfs(int pos,int val)
{
	int temp=val;
	set[pos]=1;
	for(int i=0;i<n;i++)
		if(set[i])
			temp-=c[pos][i];
		else temp+=c[pos][i];
	if(ans<temp) ans=temp;
	for(int i=pos+1;i<n;i++)
		dfs(i,temp);
	set[pos]=0;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>c[i][j];
	dfs(0,0);
	cout<<ans<<endl;
//	system("pause");
	return 0;
}*/


/*#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct Edge{ int u,v,l;Edge(int _u=0,int _v=0,int _l=0):u(_u),v(_v),l(_l){} };
inline bool cmp(const Edge & l,const Edge & r){ return l.l>r.l; }
int c[30][30],n,pre[50];Edge e[500];
void package(int x,int y){
int r=x;while(pre[x]!=y){ r=pre[x];pre[x]=y;x=r; }
}
inline int max(int a,int b){ return a>b?a:b; }
inline int find(int x){ int r=x;while(r!=pre[r]) r=pre[r];package(x,r); return r; }
inline void join(int u,int v){ int x=find(u),y=find(v);if(x==y) return;pre[x]=y; }
//if in return true;
inline bool quest(int u,int v){ if(find(u)==find(v)) return true; return false; }
int cnt=0,ans=0;
inline void add(int u,int v,int l){ e[cnt++]=Edge(u,v,l); }
bool vis[500];
inline int getStart(){ int ans=0;
while(true){ if(!vis[ans]) return ans;ans++; }
return ans; }
int main()
{
cin>>n;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++) cin>>c[i][j];
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++) add(i,j,c[i][j]);
std::sort(e,e+cnt,cmp);
int start=getStart();
while(start<cnt)
{
int temp=0;
for(int i=0;i<cnt*2;++i) pre[i]=i;
for(int i=start;i<cnt;++i)
{
//if(!quest(e[i].u,e[i].v+cnt) && !quest(e[i].u+n,e[i].v))
if(quest(e[i].u,e[i].v)) continue;
else {
join(e[i].u,e[i].v+cnt);join(e[i].v,e[i].u+cnt);
temp+=e[i].l;
vis[i]=true;
}
}
ans=max(ans,temp);start=getStart();
}
cout<<ans<<endl;
//system("pause");
return 0;
}*/
