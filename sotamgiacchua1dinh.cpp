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

#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define ttd(a) ((a)>0?(a):-(a))
#define maxn 200001

typedef long long ll;

int n;
ll xo,yo;
struct point
{
    ll x, y;
    long double goc;
} p[maxn];
point a[maxn];
ll res;

void input()
{
    scanf("%d%d%d",&n,&xo,&yo);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].x-=xo;a[i].y-=yo;
        a[i].goc=atan2l(a[i].y*1.0,a[i].x*1.0)*180.0/M_PI;
    }
}
point mp(ll a,ll b)
{
    point result;
    result.x=a;result.y=b;
    return result;
}
point operator +(point u,point v)
{
    return mp(u.x+v.x,u.y+v.y);
}
point operator -(point u,point v)
{
    return mp(u.x-v.x,u.y-v.y);
}
double operator *(point u,point v)
{
    return u.x*v.x+u.y*v.y;
}
double cp(point u,point v)
{
    return u.x*v.y-u.y*v.x;
}
bool cmp(point a,point b)
{
    return a.goc<b.goc;
}
void init()
{
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;++i)
        a[n+i]=a[i];
    res=1ll*n*(n-1)*(n-2)/6;
}
bool cunghuong(point u,point v)
{
    if(cp(u,v)==0&&u*v>0)
        return true;
    return false;
}
bool khachuong(point u,point v)
{
    if(cp(u,v)==0&&u*v<0)
        return true;
    return false;
}
ll c2(int n)
{
    if(n<=0)
        return 0;
    return 1ll*n*(n-1)/2;
}
ll d2(int m,int n)
{
    if(m<=0||n<=0)
        return 0;
    return 1ll*m*n;
}
void solve()
{
    int i1=1,j=1,j1=1;
    for(int i=1;i<=n;++i)
    {
        if(i1<=i)
            i1=i+1;
        while(i1<n+i&&cunghuong(a[i],a[i1]))
            ++i1;
        if(j<i1)
            j=i1;
        while(j<n+i&&cp(a[i],a[j])>0)
            ++j;
        if(j1<j)
            j1=j;
        while(j1<n+i&&cunghuong(a[j],a[j1]))
            ++j1;
        res-=c2(j-i-1);
        if(j<n+i&&khachuong(a[j],a[i]))
            res-=d2(j-i-1,j1-j);
    }
}
void output()
{
    printf("%lld\n",res);
}

int main()
{
    freopen("fox.inp","r",stdin);
    freopen("fox.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
