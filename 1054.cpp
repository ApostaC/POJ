/*ACCEPTED ENUMERATION*/
/*#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 5010
bool p[MAXN][MAXN];
struct Point{ int x,y;  Point(int _x=0,int _y=0){ x=_x;y=_y; }};
Point ps[MAXN];int r,c,n;
int maxn=0;
inline int test(int fir,int sec)
{
	int x1=ps[fir].x,x2=ps[sec].x,y1=ps[fir].y,y2=ps[sec].y;
	int dx=x2-x1,dy=y2-y1;
	//prev is outside 
	if(x1-dx<=0 || x1-dx>r || y1-dy<=0  || y1-dy>c){}
	else return 0;
	//next is inside and have 
	int x3=x2+dx,y3=y2+dy;
	if(x3<=0 || x3>r) return -1;
	if(x3>0 && x3<=r && y3>0 && y3<=c && p[x3][y3]) return 1;
	else return 0;
}
int count(const Point & fir,const Point & sec)
{
	int x1=fir.x,x2=sec.x,y1=fir.y,y2=sec.y;
	int dx=x2-x1,dy=y2-y1;
	int x3=x2+dx,y3=y2+dy;
	Point next(x3,y3);
	if(x3>0 && x3<=r && y3>0 && y3<=c ) 
		if(p[x3][y3])return count(sec,next)+1;
		else return -5000;
	return 2;
}
bool cmp(const Point & l,const Point & r)
{
	if(l.x==r.x) return l.y<r.y;
	return l.x<r.x;
}
int main()
{
	cin>>r>>c>>n;
	for(int i=0;i<n;i++){cin>>ps[i].x>>ps[i].y;p[ps[i].x][ps[i].y]=true;}
	std::sort(ps,ps+n,cmp);
	//for(int i=0;i<n;i++) cout<<i<<" : "<<ps[i].x<<" "<<ps[i].y<<endl;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			int cc=test(i,j);
			if(cc==-1) break;
			if(cc==1)
			{
				//cout<<i<<" "<<j<<" : ";
				//cout<<ps[i].x<<" "<<ps[i].y<<" to "<<ps[j].x<<" "<<ps[j].y<<" ";
				int temp=count(ps[i],ps[j]);if(temp>maxn) maxn=temp;
			//	cout<<temp<<endl;
			}
		}
	cout<<maxn<<endl;
	system("pause");
	return 0;
}
*/