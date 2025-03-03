#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

#define mini(a,b) ((a)<(b)?(a):(b))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define ttd(a) ((a)<0?-(a):(a))
#define maxn 50001
#define oo LLONG_MAX

typedef long long ll;

int n,m;
int a[maxn];
struct st
{
    ll sum,suml,sumr,res;
};
st tree[131073];

void update(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].sum=tree[node].suml=tree[node].sumr=tree[node].res=a[l];
        return;
    }
    int mid=(l+r)>>1;
    update(2*node,l,mid);
    update(2*node+1,mid+1,r);
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].suml=maxi(tree[2*node].suml,tree[2*node].sum+tree[2*node+1].suml);
    tree[node].sumr=maxi(tree[2*node+1].sumr,tree[2*node].sumr+tree[2*node+1].sum);
    tree[node].res=maxi(maxi(tree[2*node].res,tree[2*node+1].res),tree[2*node].sumr+tree[2*node+1].suml);
}
st mst(ll a,ll b,ll c,ll d)
{
    st ans;
    ans.sum=a;ans.suml=b;ans.sumr=c;ans.res=d;
    return ans;
}
bool bang(st a,st b)
{
    return (a.sum==b.sum&&a.suml==b.suml&&a.sumr==b.sumr&&a.res==b.res);
}
st get(int node,int L,int R,int l,int r)
{
    st ct=mst(-oo,-oo,-oo,-oo);
    if(l>R||r<L)
        return ct;
    if(l<=L&&R<=r)
        return tree[node];
    st id1,id2;
    int mid=(L+R)>>1;
    id1=get(2*node,L,mid,l,r);id2=get(2*node+1,mid+1,R,l,r);
    if(bang(id1,ct))
        return id2;
    if(bang(id2,ct))
        return id1;
    return mst(id1.sum+id2.sum,maxi(id1.suml,id1.sum+id2.suml),maxi(id2.sumr,id1.sumr+id2.sum),maxi(maxi(id1.res,id2.res),id1.sumr+id2.suml));
}
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    update(1,1,n);
    scanf("%d",&m);
    int u,v;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        printf("%lld\n",get(1,1,n,u,v).res);
    }
}
void init()
{

}
void solve()
{

}
void output()
{

}

int main()
{
    freopen("123.inp","r",stdin);
    freopen("123.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
