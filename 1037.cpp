/*UNFINISHED!
 *WITH AC CODE FOLLOWING
 */
/*#include <iostream>
using namespace std;
typedef long long Long;
Long f[25][25][2];
int c,n;
void init()
{
	memset(f,0,sizeof(f));
	f[1][1][0]=f[1][1][1]=1;
	cin>>n>>c;
}
bool v[25];
int find(int c)
{
	int j=0;
	for(int i=1;i<=n;i++)
	{
		if(!v[i]) j++;
		if(j==c) return i;
	}
	return -1;
}
void search(int * ans,int depth,Long remain)
{
	if(depth==n) return;
	Long temp=0;
	for(int i=1;i<=n-depth;i++)
	{
		temp+=(f[i][n-depth][0]+f[i][n-depth][1]);
		if(temp>=remain)
		{
			int pos=find(i);
			ans[depth]=pos;
			v[pos]=true;
			search(ans,depth+1,remain-(temp-(f[i][n-depth][0]+f[i][n-depth][1])));
			return;
		}
	}
}
void main1()
{
	init();
	for(int N=2;N<=n;N++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<i;j++) f[i][N][0]+=f[j][N-1][1];
			for(int j=i;j<=N;j++) f[i][N][1]+=f[j][N-1][0];
		}
	}
	int * ans=new int[n+1];
	search(ans,0,c);
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<endl;
}
int main()
{
	int nn;cin>>nn;
	for(int i=0;i<nn;i++)
	{
		main1();
	}
}*/


/*AC CODE FOLLOWING
 *http://www.cnblogs.com/flipped/p/6633206.html
 */
/*#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 21
#define ll long long
using namespace std;
int t,n;
ll k;
ll up[N][N],down[N][N];
int s[N];
void get(){
	int fup,v=0;
	for(int i=1;i<=n;i++)s[i]=i;
	for(int i=n;i;i--){//ʣ��i��λ��Ҫ��
		if(i==n){
			for(int j=1;j<=n;j++){//�ŵ�1С����nС
				if(k<=down[j][i]){//�ȿ����½�����Ϊ�½������������С
					v=j;fup=0;break;//s[j]��ͷ�Ĺ��㣬����֮��һ��������
				}
				k-=down[j][i];//�����㣬���Һ���ĵ�k-down��ķ�����
				if(k<=up[j][i]){
					v=j;fup=1;break;
				}
				k-=up[j][i];
			}
		}
		else{
			if(fup){
				for(int j=v;j<=i;j++){
					if(k<=down[j][i]){
						v=j;break;
					}
					k-=down[j][i];
				}
			}
			else{
				for(int j=1;j<v;j++){
					if(k<=up[j][i]){
						v=j;break;
					}
					k-=up[j][i];
				}
			}
			fup^=1;
		}
		printf("%d ",s[v]);
		for(int j=v;j<i;j++)s[j]=s[j+1];
	}
	puts("");
}
int main() {
	down[1][1]=1;
	for(int i=1;i<N;i++){
		for(int j=2;j<=i;j++)
			down[j][i]=down[j-1][i]+up[j-1][i-1];
		//�Ե�jС��ͷ����i���½�=sum_{k=1}^{k=j-1}{up[k][i-1]}
		//��ôdown[j][i]-down[j-1][i]=up[j-1][i-1]
		for(int j=1;j<=i;j++)
			up[j][i]=down[i-j+1][i];
		//��jС��ͷ������=��i-j+1��ͷ���½�
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&k);
		get();
	}
	return 0;
}*/
