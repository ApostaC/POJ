#include <iostream>
using namespace std;
const int MAX = 30000;
int n,m;
int pre[MAX+10], total[MAX+10];

inline int getRoot(int a){ return a == pre[a] ? a : (pre[a] = getRoot(pre[a])); }
inline void join(int a, int b)
{
    int ra = getRoot(a), rb = getRoot(b);
    if(ra == rb) return;
    total[ra] += total[rb];
    pre[rb] = ra;
}

inline int query(int a, int b)
{
    return getRoot(a) == getRoot(b);
}

void init()
{
    for(int i=0;i<MAX;i++)
    {
        pre[i] = i;
        total[i] = 1;
    }
}

int main1()
{
    init();
    cin>>n>>m;
    if(n == 0 && m == 0) return -1;
    for(int i=0;i<m;i++)
    {
        int l,a,b;
        cin>>l>>a;
        for(int j=1;j<l;j++)
        {
            cin>>b;
            join(a,b);
        }
    }
    std::cout<<total[getRoot(0)]<<std::endl;
    return 0;
}

int main()
{
    int status;
    do{
       status = main1();
    }while(status == 0); 
    return 0;
}
