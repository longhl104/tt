#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

template <class T>
class bit
{
    T *tree;
    int maxval;
    public:
    bit(int n)
    {
        tree=new T[n+1];
        memset(tree,0,sizeof(T)*(n+1));
        maxval=n;
    }
    void update(int idx,T val)
    {
        while(idx<=maxval)
        {
            tree[idx]+=val;
            idx+=(idx&(-idx));
        }
    }
    T Read(int idx)
    {
        T sum=0;
        while(idx>0)
        {
            sum+=tree[idx];
            idx-=(idx&(-idx));
        }
        return sum;
    }
};

int main()
{
    freopen("123.inp","r",stdin);
    int n,m,u,v,val;
    cin>>n>>m;
    bit <int> b(n);
    for(int i=1;i<=m;i++)
    {
        char c;
        cin>>c;
        if(c=='u')
        {
            scanf("%d%d",&u,&val);
            b.update(u,val);
        }
        else
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",b.Read(v)-b.Read(u-1));
        }
    }
}
