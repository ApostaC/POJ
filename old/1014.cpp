/*ACCEPTED MULTIPLE PACK DP*/
/*#include <iostream>
#include <string.h>
using namespace std;
int f[120010],a[10];
int v;
inline int max(int a,int b){ return a>b?a:b; }
int init()
{
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	v=0;
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];v+=a[i]*i;
	}
	return v;
}
void zopack(int c,int w)
{
	for(int i=v;i>=c;i--)
		f[i]=max(f[i],f[i-c]+w);
}
void compack(int c,int w)
{
	for(int i=c;i<=v;i++)
		f[i]=max(f[i],f[i-c]+w);
}
void mulpack(int c,int m,int w)
{
	if(c*m>v) compack(c,w);
	int k=1;
	while(k<=m)
	{
		zopack(c*k,w*k);
		m=m-k;k*=2;
	}
	zopack(c*m,w*m);
}
int main()
{
	int cnt=1;
	while(init())
	{
		cout<<"Collection #"<<cnt<<":"<<endl;++cnt;
		if(v%2!=0)
		{
			cout<<"Can't be divided."<<endl;
			cout<<endl;continue;
		}
		for(int i=1;i<=6;i++)
		{
			mulpack(i,a[i],i);
		}
		if(f[v/2]==v/2)
		{
			cout<<"Can be divided."<<endl;
			cout<<endl;
		}
		else{
			cout<<"Can't be divided."<<endl;
			cout<<endl;
		}
	}
	system("pause");
}
*/