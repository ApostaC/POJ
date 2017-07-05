/*unfinished*/
/*#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
const int MAXN=362880+100;
int fac[9];
int v[MAXN];string op[MAXN];int fr,re;
int d[4]={-3,-1,1,3};char o[4]={'u','l','r','d'};
void init()
{
	fac[0]=1;
	for(int i=1;i<9;i++) fac[i]=fac[i-1]*(i+1);
}
inline int hashs(string s)
{
	int ans=0;
	for(int i=0;i<9;i++) if(s[i]!='x') ans+=((s[i]-'0')*fac[i]);
	return ans%MAXN;
}
string getState(string s,int d)
{
	for(int i=0;i<9;i++)
		if(s[i]=='x')
		{
			if(d==1 || d==-1)
			{
				if(i+d>=9 || i+d<0) continue;
				if((i/3)!=((i+d)/3)) continue;
			}
			if(d==3 || d==-3)
			{
				if(i+d>=9 || i+d<0) continue;
			}
			char temp=s[i];s[i]=s[i+d];s[i+d]=temp;
			return s;
		}
	return s;
}
const string END="12345678x";
string start;queue<string> q;
void bfs()
{
	if(start==END) { cout<<"no move"<<endl;return; }
	q.push(start);string nd,newn,oo,no;int h;v[hashs(start)];
	re=fr=0;
	op[re++]="";
	while(!q.empty())
	{
		string nd=q.front();q.pop();oo=op[fr];++fr;
		for(int i=0;i<4;i++)
		{
			newn=getState(nd,d[i]);
			if(newn==nd) continue;
			no=oo+o[i];
			if(newn==END){
				cout<<no<<endl;
				return;
			}
			h=hashs(newn);
			if(!v[h])
			{
				q.push(newn);op[re++]=no;v[h]=true;
			}
		}
	}
	cout<<"unsolvable"<<endl;
}
int main()
{
	init();
	memset(v,0,sizeof(v));
	for(int i=0;i<9;i++)
	{
		char c;cin>>c;
		start+=c;
	}
	bfs();
	system("pause");
	return 0;
}*/