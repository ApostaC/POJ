#define _CRT_SECURE_NO_WARNINGS
/*ACCPETED COMPACTED-STATE BFS*/
/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX_S=(1<<14)+100;
const int MAX_N=20+2;
const int INF=(1<<29);
struct Snake
{
	int x,y,dis,s;
	Snake(int xx=0,int yy=0,int dd=0,int ss=0):x(xx),y(yy),dis(dd),s(ss){}
};
struct Point{
	int x,y;
};
int n,m,l,k,res;
int vis[MAX_N][MAX_N][MAX_S];	//store state which has been searched
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};	//map direction to dx and dy
int rid[3][3]={-1,3,-1,1,-1,0,-1,2,-1};	//map dx and dy to direction
bool mp[MAX_N][MAX_N];	//map
Point pos[MAX_N*MAX_N];	//input body of snake

int getStartState()	//get start state from input
{
	int ddx,ddy,direct,s=0;
	for(int i=l-1;i>=1;i--)
	{
		ddx=pos[i].x-pos[i-1].x+1;ddy=pos[i].y-pos[i-1].y+1;
		direct=rid[ddx][ddy];
		s=s<<2;s=s|direct;
	}
	return s;
}

//get next state from direction i and current state s
int getNextState(int i,int s)	
{
	int ddx=-dx[i],ddy=-dy[i],direct;
	int mask = (1 << ((l - 1) << 1)) - 1;
	direct=rid[ddx+1][ddy+1];
	s=s<<2;s=s|direct;s=s&mask;
	return s;
}

//check if new head collide with body
bool judge(int x,int y,int px,int py,int s)
{
	int direct;
	for(int i=0;i<l-1;i++)
	{
		direct=s&3;s=s>>2;
		if(x==px+dx[direct] && y==py+dy[direct])
			return false;
		px=px+dx[direct];py=py+dy[direct];
	}
	return true;
}

queue<Snake> q;
void BFS()
{
	Snake a;
	int ddx,ddy,s;
	while(!q.empty())
	{
		a=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			ddx=a.x+dx[i];ddy=a.y+dy[i];	//compute new coordinate of head
			s=getNextState(i,a.s);
			if(ddx>0 && ddy>0 && ddx<=n && ddy<=m && !vis[ddx][ddy][s] &&
				!mp[ddx][ddy] && judge(ddx,ddy,a.x,a.y,a.s))
				//in map AND not visited AND no collision
			{
				if(ddx==1 && ddy==1)	//find answer
				{
					res=a.dis+1;return;
				}
				vis[ddx][ddy][s]=1;		//record
				q.push(Snake(ddx,ddy,a.dis+1,s));	//push
			}
		}
	}
}

int main()
{
	int s=0,_case=0;
	Snake start;
	while(scanf("%d%d%d",&n,&m,&l),n+m+l)
	{
		res=INF;
		memset(mp,0,sizeof(mp));memset(vis,0,sizeof(vis));
		for(int i=0;i<l;i++)
			scanf("%d%d",&pos[i].x,&pos[i].y);
		scanf("%d",&k);
		int u,v;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&u,&v);mp[u][v]=1;
		}
		if(pos[0].x==1&&pos[0].y==1)
		{
			printf("Case %d: 0\n",++_case);
			continue;
		}
		s=getStartState();
		q.push(Snake(pos[0].x,pos[0].y,0,s));
		BFS();
		if(res == INF)
			printf("Case %d: -1\n",++_case);
		else
			printf("Case %d: %d\n",++_case,res);
		while(!q.empty()) q.pop();	//clear queue
	}
}

*/