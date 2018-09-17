/*
 *ACCEPTED
 *DP WITH MONOTONIC QUEUE
 */
/*#include <iostream>
#include <string.h>
using namespace std;
struct Q{ int ind,dat;Q(int i=0,int d=0):ind(i),dat(d){} };
const int MAXL=1000010,MAXN=1010;
const int INF=1<<30;
int a,b,n,l,s[MAXN],e[MAXN],v[MAXL],f[MAXL];
Q q[MAXL];int fr,re;
inline int min(int a,int b){ return a<b?a:b; }
void insert(int ind,int dat)
{
	while(q[re].dat>dat && re>=fr) --re;
	++re;
	q[re].ind=ind;q[re].dat=dat;
}
void outhead()
{
	++fr;
}
int main()
{
	cin>>n>>l>>a>>b;
	a*=2;b*=2;
	memset(v,-1,sizeof(v));
	for(int i=1;i<=n;++i)
	{
		cin>>s[i]>>e[i];
		for(int j=s[i]+1;j<e[i];++j) v[j]=false;
	}
	f[0]=0;
	fr=0;re=-1;
	for(int i=1;i<=l;++i) f[i]=INF;
	for(int i=a;i<=l;++i)
	{
		insert(i-a,f[i-a]);
		if(q[fr].ind<i-b) outhead();
		if(i%2==0 && v[i]) f[i]=min(f[i],f[q[fr].ind]+1);
	}
	//for(int i=0;i<=l;i++) cout<<i<<" : "<<f[i]<<endl;
	if(f[l]==INF) cout<<-1;
	else cout<<f[l];
	system("pause");
	return 0;
}*/