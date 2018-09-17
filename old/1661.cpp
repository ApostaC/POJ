/*ACCEPTED
 *TREE DP 63MS
 *DIJKSTRA 0MS FASTER!
 */
/*#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXI=1<<30;
struct B{ int x1,x2,h;B(int _1=0,int _2=0,int _h=0):x1(_1),x2(_2),h(_h){} };
int f[1010][2],nex[1010][2],x,y,n,m,t;B a[1010];
inline bool operator<(const B & b1,const B & b2){ return b1.h>b2.h; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int a){ return a>0?a:-a; }
void init()
{
	for(int i=0;i<1010;i++)
		f[i][0]=f[i][1]=MAXI;
	memset(nex,0,sizeof(nex));//no -1 ground 0
	cin>>n>>x>>y>>m;
	for(int i=1;i<=n;i++) cin>>a[i].x1>>a[i].x2>>a[i].h;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int j0=a[i].x1,j1=a[i].x2;
		for(int j=i+1;j<=n;++j)
		{
			if(a[i].h-a[j].h>m) {nex[i][0]=-1;break;}
			if(a[j].x1<=j0 && a[j].x2>=j0){nex[i][0]=j;break;}
		}
		for(int j=i+1;j<=n;++j)
		{
			if(a[i].h-a[j].h>m) { nex[i][1]=-1;break; }
			if(a[j].x1<=j1 && a[j].x2>=j1){nex[i][1]=j;break;}
		}
	}
	//for(int i=1;i<=n;i++)
	//	cout<<i<<"th left : "<<nex[i][0]<<" right : "<<nex[i][1]<<endl;
}
int main()
{
	cin>>t;
	for(int cas=0;cas<t;++cas)
	{
		init();
		int i=1,target=0;
		for(;i<=n;i++) if(a[i].h<y) break;
		for(;i<=n;i++)
		{
			if(a[i].x1<=x && a[i].x2>=x)
			{
				target=i;break;
			}
		}
		if(target==0) { cout<<y<<endl;continue; }
		for(int i=n;i>=target;i--)
		{
			int j0=nex[i][0],j1=nex[i][1];
			if(j0==0) f[i][0]=0;
			else if (j0!=-1)
			f[i][0]=min(f[j0][0]+abs(a[i].x1-a[j0].x1),
						f[j0][1]+abs(a[i].x1-a[j0].x2));
			if(j1==0) f[i][1]=0;
			else if (j1!=-1)
			f[i][1]=min(f[j1][0]+abs(a[i].x2-a[j1].x1),
						f[j1][1]+abs(a[i].x2-a[j1].x2));
		}
		int sum=min(f[target][0]+abs(x-a[target].x1),
					f[target][1]+abs(x-a[target].x2))+y;
		cout<<sum<<endl;
	}
	system("pause");
	return 0;
}*/

/*#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
const int maxn=1000*2+5;
const int INF=0x3f3f3f3f;
int N,X,Y,MAX;
long long dis[maxn];
int vis[maxn];
int head[maxn];
int tot;
long long ans;
struct Line {
	int l,r,h;
	bool operator<(const Line tmp)const {
		return h>tmp.h;
	}
} line[maxn];
struct Node {
	int u;
	long long dis;
	bool operator<(const Node tmp)const {
		return dis>tmp.dis;
	}
};

struct Edge {
	int to,next;
	int length;
} edge[maxn*maxn];

void add(int i,int j,int dis) {
	edge[tot].next=head[i];
	edge[tot].to=j;
	edge[tot].length=dis;
	head[i]=tot++;
}
void dijkstra(int s) {
	for(int i=0; i<maxn; i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<Node>q;
	Node t;
	t.u=s;
	t.dis=0;
	dis[s]=0;
	q.push(t);
	int v,u;
	while(!q.empty()) {
		t=q.top();
		q.pop();
		u=t.u;
		vis[u]=1;

		if(u==2*N+1){
			ans=t.dis;
			break;
		}

		for(int k=head[u]; k!=-1; k=edge[k].next) {
			v=edge[k].to;
			if(!vis[v] && dis[u]+edge[k].length<dis[v]) {
				dis[v]=dis[u]+edge[k].length;
				t.u=v;
				t.dis=dis[v];
				q.push(t);
			}


		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(head,-1,sizeof(head));
		tot=0;
		scanf("%d%d%d%d",&N,&X,&Y,&MAX);
		for(int i=1; i<=N; i++) {
			scanf("%d%d%d",&line[i].l,&line[i].r,&line[i].h);
		}
		sort(line+1,line+N+1);
		int ldis,rdis;
		for(int i=1; i<=N; i++) {
			//����Ҫ���ǣ�����������iƽ̨�·����ϵľͿ��Խ����ߵĹ�ϵ
			//��ֻ�����������ƽ̨���С�
			//����ƽ̨1,2,3������2��3����1���·�����������������1��3������������Ϊ�м����2������ֻ��1��2����
			int cnt1=0,cnt2=0;
			for(int j=i+1; j<=N; j++) {
				if(line[i].h-line[j].h>=0 && line[i].h-line[j].h<=MAX) {
					if(line[j].l<=line[i].l && line[i].l<=line[j].r) {
						cnt1++;
						//����·���һ������Ҫ���
						if(cnt1==1) {
							ldis=line[i].h-line[j].h+line[i].l-line[j].l;
							add(i*2-1,j*2-1,ldis);

							rdis=line[i].h-line[j].h+line[j].r-line[i].l;
							add(i*2-1,j*2,rdis);
						}
					}
					if(line[j].l<=line[i].r && line[i].r<=line[j].r) {
						cnt2++;
						//�Ҷ˵��·���һ������Ҫ���
						if(cnt2==1) {
							ldis=line[i].h-line[j].h+line[i].r-line[j].l;
							add(i*2,j*2-1,ldis);

							rdis=line[i].h-line[j].h+line[j].r-line[i].r;
							add(i*2,j*2,rdis);
						}
					}
				}
			}
			//��Ҫ��������ӣ�������ƽ̨�·�û�����������ƽ̨��
			//�����ƽ̨��˵��·�û������ƽ̨����������������������������
			if(!cnt1 && line[i].h<=MAX) {
				add(i*2-1,2*N+1,line[i].h);
			}
			//�����ƽ̨�Ҷ˵��·�û������ƽ̨����������������������������
			if(!cnt2 && line[i].h<=MAX) {
				add(i*2,2*N+1,line[i].h);
			}
		}
		//ֻ����һ��ƽ̨��Դ������
		int cnt=0;
		for(int j=1; j<=N; j++) {
			if(line[j].l<=X && X<=line[j].r && Y-line[j].h>=0 && Y-line[j].h<=MAX) {
				cnt++;
				//��һ������Ҫ���ƽ̨
				if(cnt==1) {
					ldis=Y-line[j].h+X-line[j].l;
					add(0,j*2-1,ldis);

					rdis=Y-line[j].h+line[j].r-X;
					add(0,j*2,rdis);
				}
			}
		}
		//û��ƽ̨��jimmy���·���Ҳ����jimmy����ֱ�ӵ�����档����֮ǰ�������˶�
		if(cnt==0) {
			add(0,2*N+1,Y);
		}
		dijkstra(0);
		printf("%I64d\n",ans);
	}
	return 0;
}*/