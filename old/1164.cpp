/*ACCEPTED DFS*/
/*#include <iostream>
#define W 1
#define N 2
#define E 4
#define S 8
using namespace std;
const int MAXN=60;
int a[MAXN][MAXN]={0};
int pass[MAXN][MAXN]={0};
int label=1;
int pp=0;
void color(int i,int j)
{
	a[i][j]=label;pp++;
	if(!(pass[i][j] & W) && !a[i][j-1]) color(i,j-1);
	if(!(pass[i][j] & E) && !a[i][j+1]) color(i,j+1);
	if(!(pass[i][j] & S) && !a[i+1][j]) color(i+1,j);
	if(!(pass[i][j] & N) && !a[i-1][j]) color(i-1,j);
}
int main()
{
	int maxn=0;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)	cin>>pass[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			pp=0;
			if(a[i][j]==0)
			{
				color(i,j);
				label++;
				if(pp>maxn) maxn=pp;
				pp=0;
			}
		}
	cout<<label-1<<endl<<maxn<<endl;
	return 0;
}*/