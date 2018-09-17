/*ACCEPTED ENUMRATION*/
/*#include <iostream>
#include <string>
using namespace std;
const int WIDTH=6;const int HEIGHT=5;
int change[30];int n;
int currState;
int mask[5];
string debug(int s,int leng=32)
{
	string t;
	for(int i=0;i<leng;i++)
	{
		if(s&(1<<i)) t="1"+t;
		else t="0"+t;
	}
	return t;
}

void init()
{
	for(int i=0;i<HEIGHT;i++)
		for(int j=0;j<WIDTH;j++)
		{
			int temp=i*6+j;
			change[temp]^=(1<<temp);
			if(j-1>=0) change[temp]|=(1<<(temp-1));
			if(j+1<WIDTH) change[temp]|=(1<<(temp+1));
			if(i-1>=0) change[temp]|=(1<<(temp-6));
			if(i+1<HEIGHT) change[temp]|=(1<<(temp+6));
		}
	int a=0x3f;
	for(int i=0;i<HEIGHT;i++)
	{
		mask[i]=a;a<<=6;
	}
}
void changeState(int & s,int row,int op)
{
	//cout<<debug(s&mask[row],6)<<"------"<<endl;
	int base=row*6;
	for(int i=0;i<6;i++)
	{
		if(op&(1<<(i))) s^=change[base+i];
	}
	//cout<<"row:"<<row<<" op:"<<debug(op,6)<<endl<<" ans:"<<debug(s&mask[row],6)<<endl;
}

int search(int s)
{
	int ss=s;int ans=0;
	for(int _case=0;_case<64;_case++)
	{
		ss=s;
		ans=_case;
		changeState(ss,0,_case);
		for(int r=0;r<4;r++)
		{
			int op=(ss & mask[r])>>(r*6);
			changeState(ss,r+1,op);
			ans|=op<<((r+1)*6);
		}
		if(!ss) return ans;
	}
	return -1;
}
void print(int n){
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++)
		{
			if(n&(1<<(i*6+j))) cout<<1<<" ";
			else cout<<"0"<<" ";
		}
		cout<<endl;
	}
}


int main1(int a)
{
	currState=0;
	for(int temp=0;temp<30;temp++)
	{
		int t;cin>>t;
		if(t) currState|=(1<<temp);
	}
	int ans=search(currState);
	cout<<"PUZZLE #"<<a<<endl;
	print(ans);
	return 0;
}

int main()
{
	init();
	cin>>n;
	for(int i=0;i<n;i++) main1(i+1);
	system("pause");
	return 0;
}*/