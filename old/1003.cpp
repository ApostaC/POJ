#include <iostream>
using namespace std;
double leng[300];
int binarySearch(int l,int r,double t)
{
	if(l==r) return l;
	int mid=(l+r)/2;
	if(leng[mid]==t) return mid;
	if(leng[mid]>t) return binarySearch(l,mid,t);
	else // leng[mid]<t;
	{
		if(leng[mid+1]<t) return binarySearch(mid+1,r,t);
		else return mid+1;
	}
}

int main()
{
	leng[1]=0.5;
	for(int i=2;i<300;i++)
		leng[i]=leng[i-1]+1.0/(i+1);
	double c;
	while(cin>>c)
	{
		cout<<binarySearch(1,290,c)<<" card(s)"<<endl;
	}
	system("pause");
	return 0;
}
