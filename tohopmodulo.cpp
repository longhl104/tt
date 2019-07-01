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
#define base 1234567890ll

typedef long long ll;

int test;
ll n,m,res;
ll p[]={2,3,5,3607,3803};
ll e[]={1,2,1,1,1};

void input()
{
    scanf("%lld%lld",&m,&n);
}
void analysis(ll k)
{
    ll p=2,e;
    while(k!=1)
    {
        e=0;
        while(k%p==0)
        {
            ++e;
            k/=p;
        }
        if(e!=0)
            cout<<p<<'^'<<e<<"\n";
        ++p;
        if(k>1&&p*p>k)
            p=k;
    }
}
void init()
{
    res=0;
    analysis(1234567890);
    exit(0);
}
ll inverse(ll a,ll m)
{
    ll xa=1,xm=0,xr,r,q;
    while(m!=0)
    {
        q=a/m;
        r=a-q*m;a=m;m=r;
        xr=xa-q*xm;xa=xm,xm=xr;
    }
    return xa;
}
ll intpower(ll p,ll k)
{
    if(k==0)
        return 1;
    ll result=intpower(p,k/2);
    result=result*result;
    if(k%2)
        result=result*p;
    return result;
}
ll intpowermod(ll p,ll k,ll m)
{
    if(k==0)
        return 1%m;
    ll result=intpowermod(p,k/2,m);
    result=result*result%m;
    if(k%2)
        result=result*p%m;
    return result;
}
void factorialanalysis(ll n,ll p,ll e,ll &power,ll &remainder)
{
    ll temp=n,pe;
    power=0;
    while(temp)
    {
        temp/=p;
        power+=temp;
    }
    remainder=1;
    pe=intpower(p,e);
    while(n)
    {
        temp=1;
        for(int i=1;i<=pe;++i)
            if(i%p!=0)
                temp=(temp*i)%pe;
        remainder=remainder*intpowermod(temp,n/pe,pe)%pe;
        for(int i=1;i<=n%pe;++i)
            if(i%p!=0)
                remainder=(remainder*i)%pe;
        n/=p;
    }
}
ll getremainder(ll n,ll k,ll p,ll e)
{
    ll r1,p1,r2,p2,r3,p3,modulo,result;
    factorialanalysis(n,p,e,p1,r1);
    factorialanalysis(k,p,e,p2,r2);
    factorialanalysis(n-k,p,e,p3,r3);
    modulo=intpower(p,e);
    result=r1*intpowermod(p,p1-p2-p3,modulo)%modulo;
    result=result*inverse(r2,modulo)%modulo;
    result=result*inverse(r3,modulo)%modulo;
    result=(result+modulo)%modulo;
    return result;
}
ll solve(ll n,ll k)
{
    ll a,m,c,y,result=0;
    for(int i=0;i<5;++i)
    {
        a=getremainder(n,k,p[i],e[i]);
        m=intpower(p[i],e[i]);
        c=base/m;
        result=(result+a*c%base*inverse(c,m)%base)%base;
    }
    result=(result+base)%base;
    return result;
}
void solve()
{

}
void output()
{
    printf("%lld\n",solve(m+n-1,n-1));
}

int main()
{
    freopen("123.inp","r",stdin);
    freopen("123.out","w",stdout);
    scanf("%d",&test);
    while(test--)
    {
        input();
        init();
        solve();
        output();
    }
    return 0;
}


///Tim tat ca cac uoc cua 1 so
void timuoc()
{
    md=0;
    int t;
    c.push_back(1);
    for(int i=0;i<=cnt;++i)
    {
        t=1;
        for(int j=1;j<=a[i].second;++j)  /// a[i].second = e[i];
        {
            t*=a[i].first; ///a[i].first = p[i]
            for(int z=0;z<=md;++z)
                c.push_back(c[z]*t);
        }
        md=c.size()-1;
        sort(c.begin(),c.end());
    }
}


///so catalan
#include <bits/stdc++.h>
using namespace std;

int n,hmx;
long long ans=2;
int h[100001],rmin[100001],a[200001];
const long long mod=1e9;

int main(){
    cin>>n>>hmx;
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    rmin[n]=h[n];
    for(int i=n-1;i>0;i--){
        if(h[i]>rmin[i+1])break;
        ans++;
        rmin[i]=min(rmin[i+1],h[i]);
    }
    cout<<ans<<'\n';
    ans=1;
    n++;
    for(int i=2;i<=n;i++){
        int m=n+i;
        for(int p=2;p*p<=m;p++)
            while(m%p==0){
                a[p]++;
                m/=p;
            }
        if(m>1)a[m]++;
        m=i;
        for(int p=2;p*p<=m;p++)
            while(m%p==0){
                a[p]--;
                m/=p;
            }
        if(m>1)a[m]--;
    }
    for(int i=1;i<=2*n;i++)
        for(int j=1;j<=a[i];j++)
            ans=(ans*i)%mod;
    cout<<ans<<'\n';
    return 0;
}
