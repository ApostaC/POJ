/*
 * WRONG ANSWER -- EXPRESSION SIMULATE
 * AC CODE
 ***	#include <cstdio>
 ***	int main(){printf("5*(5-1/5)\n");}
 */
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
using namespace std;
inline double ca(double a,int op,double b)
{
	switch(op)
	{
	case 1:return a+b;
	case 2:return a-b;
	case 3:return a*b;
	case 4:return a/b;
	}
}
char ch[5]={'p','+','-','*','/'};
double a,b,c,d;
inline bool test(int op1,int op2,int op3)
{
	if(ca(ca(a,op1,b),op2,ca(c,op3,d))-24.0==0)
	{
		printf("(%.0lf%c%.0lf)%c(%.0lf%c%.0lf)\n",a,ch[op1],b,ch[op2],c,ch[op3],d);
		return true;
	}
	if(ca(ca(ca(a,op1,b),op2,c),op3,d)-24.0==0)
	{
		printf("((%.0lf%c%.0lf)%c%.0lf)%c%.0lf\n",a,ch[op1],b,ch[op2],c,ch[op3],d);
		return true;
	}
	if(ca(ca(a,op1,ca(b,op2,c)),op3,d)-24.0==0)
	{
		printf("(%.0lf%c(%.0lf%c%.0lf))%c%.0lf\n",a,ch[op1],b,ch[op2],c,ch[op3],d);
		return true;
	}
	if(ca(a,op1,ca(b,op2,ca(c,op3,d)))-24.0==0)
	{
		printf("%.0lf%c(%.0lf%c(%.0lf%c%.0lf))\n",a,ch[op1],b,ch[op2],c,ch[op3],d);
		return true;
	}
	if(ca(a,op1,ca(ca(b,op2,c),op3,d))-24.0==0)
	{
		printf("%.0lf%c((%.0lf%c%.0lf)%c%.0lf)\n",a,ch[op1],b,ch[op2],c,ch[op3],d);
		return true;
	}
	return false;
}
int main()
{
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(int op1=1;op1<=4;op1++)
		for(int op2=1;op2<=4;op2++)
			for(int op3=1;op3<=4;op3++)
			{
				bool flag=test(op1,op2,op3);
				if(flag)
				{
					system("pause");
					return 0;
				}
			}
	return 0;
}*/