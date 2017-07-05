/*ACCEPTED DFS+PRUNING*/
/*#define _CRT_SECURE_NO_WARNINGS
#define M1
#ifdef M1
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;
int n,num[80],maxl,sum,initnum[80];
int len;vector<int> q;
int init()
{
	memset(num,0,sizeof(num));
	memset(initnum,0,sizeof(initnum));q.clear();
	sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;++initnum[a];sum+=a;
	}
	for(int i=50;i>=1;i--) if(initnum[i]) q.push_back(i);
	return n;
}
void donum(){ for(int i=1;i<=50;i++) num[i]=initnum[i]; }
inline int findmax()
{
	for(int i=0;i<q.size();i++) if(num[q[i]]) return q[i];
	return 0;
}
inline int min(int a,int b){ return a<b?a:b; }
bool flag;
bool dfs(int l,int index,int recover)
{
	if(recover==sum/len)
		return 1;
	if(l==0)
		return dfs(len,0,recover+1);

	if(l==len){
		for(int i=0;i<q.size();++i)
			if(num[q[i]]!=0){
				num[q[i]]--;
				if(dfs(len-q[i],i,recover))
					return 1;
				num[q[i]]++;
				return 0;
			}
	}

	for(int i=index;i<q.size();++i)
		if(num[q[i]]!=0&&q[i]<=l){
			num[q[i]]--;
			if(dfs(l-q[i],i,recover))
				return 1;
			num[q[i]]++;
		}
	return 0;
}
int main1()
{
	int a=init();
	if(a==0) return 0;
	donum();
	for(int i=findmax();i<=sum/2;i++)
	{
		if(sum%i==0)
		{
			donum();
			len=i;
			flag=dfs(i,0,0);
			if(flag)
			{
				cout<<i<<endl;
				return 1;
			}
		}
	}
	cout<<sum<<endl;
	return 1;
}
int main()
{
	while(main1()){}
	return 0;
}
#endif
#ifdef M2
#include <cstdio>
#include <string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int Max = 65;

int n,len,stick[Max];
bool flag,vis[Max];

bool cmp(int a,int b){
	return a > b;
}

void dfs(int dep,int now_len,int u){// dep为当前已被用过的小棒数，u为当前要处理的小棒。
	if(flag) return;
	if(now_len == 0){//  当前长度为0，寻找下一个当前最长小棒。
		int k = 0;
		while(vis[k]) k++;//  寻找第一个当前最长小棒。
		vis[k] = true;
		dfs(dep + 1,stick[k],k + 1);
		vis[k] = false;
		return;
	}
	if(now_len == len){//  当前长度为len，即又拼凑成了一根原棒。
		//cout<<"complete!"<<endl;
		if(dep == n) flag = true;//  完成的标志：所有的n根小棒都有拼到了。
		else dfs(dep,0,0);
		return;
	}
	for(int i = u; i < n; i++)
		if(!vis[i] && now_len + stick[i] <= len){
			if(!vis[i-1] && stick[i] == stick[i-1]) continue;//  不重复搜索：最重要的剪枝。
			vis[i] = true;
			//cout<<i<<" ";
			dfs(dep + 1,now_len + stick[i],i + 1);
			vis[i] = false;
		}
}

int main(){
	while(scanf("%d",&n) && n != 0){
		int sum = 0;
		flag = false;
		for(int i = 0; i < n; i++){
			scanf("%d",&stick[i]);
			sum += stick[i];
		}
		sort(stick,stick + n,cmp);//  从大到小排序。
		for(len = stick[0]; len < sum; len++)
			if(sum % len == 0){//  枚举能被sum整除的长度。
				memset(vis,0,sizeof(vis));
				dfs(0,0,0);
				if(flag) break;
			}
		printf("%d\n",len);
	}
	return 0;
}
#endif
#ifdef M3
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int n,sticks[70],sum=0,len=0;
int num[70];
vector<int> q;

bool cut(int l,int index,int recover){
	if(recover==sum/len)
		return 1;
	if(l==0)
		return cut(len,0,recover+1);

	if(l==len){
		for(int i=0;i<q.size();++i)
			if(num[q[i]]!=0){
				num[q[i]]--;
				if(cut(len-q[i],i,recover))
					return 1;
				num[q[i]]++;
				return 0;
			}
	}

	for(int i=index;i<q.size();++i)
		if(num[q[i]]!=0&&q[i]<=l){
			num[q[i]]--;
			if(cut(l-q[i],i,recover))
				return 1;
			num[q[i]]++;
		}
	return 0;
}

int main(){
	while(cin>>n&&n!=0){
		sum=0;
		memset(num,0,sizeof(num));
		q.clear();
		for(int i=0;i<n;++i){
			cin>>sticks[i];
			sum+=sticks[i];
			if(num[sticks[i]]==0)
				q.push_back(sticks[i]);
			num[sticks[i]]++;
		}
		bool flag=0;
		sort(q.begin(),q.end(),greater<int>());
		for(int i=q[0];i<=sum/2;++i)
			if(sum%i==0){
				len=i;
				if(cut(i,0,0)){
					flag=1;
					break;
				}
			}
		if(flag)
			cout<<len<<endl;
		else
			cout<<sum<<endl;
	}
}
#endif*/