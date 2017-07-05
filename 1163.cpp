/*ACCPTED SIMPLE DP*/
/*#include <stdio.h>
using namespace std;
inline int max(int a,int b){ return a>b?a:b; }
int a[110][110],f[110],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
	for(int i=n;i>=1;i--)
		for(int j=1;j<=i;j++) f[j]=max(f[j],f[j+1])+a[i][j];
	printf("%d",f[1]);
	return 0;
}*/