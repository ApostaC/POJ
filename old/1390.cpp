/*ACCEPTED MEMORIAL SEARCHING*/
/*#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
inline int SQ(int a){ return a*a; }
int f[210][210][210];
struct Seg{ int t,leng; };Seg seg[210];

int search(int i,int j,int head)
{
	if(i>j) return 0;
	if(i==j) return SQ(head+seg[i].leng);
	if(f[i][j][head]==0)
	{
		int result=search(i+1,j,0)+SQ(head+seg[i].leng);

		for(int p=i+1;p<=j;p++)
		{
			if(seg[p].t==seg[i].t)
			{
				int temp1=search(i+1,p-1,0)+search(p,j,head+seg[i].leng);
				if(temp1>result) result=temp1;
			}
		}
		f[i][j][head]=result;
	}
	return f[i][j][head];
}
void init()
{
	memset(f,0,sizeof(f));
	memset(seg,0,sizeof(seg));
}
int main1()
{
	init();
	int n;cin>>n;int size=0;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;
		if(a==seg[size-1].t) ++seg[size-1].leng;
		else {
			seg[size++].t=a;
			seg[size-1].leng=1;
		}
	}
	cout<<search(0,size-1,0)<<endl;return 0;
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Case "<<i+1<<": ";
		main1();
	}
	//system("pause");
	return 0;
}*/