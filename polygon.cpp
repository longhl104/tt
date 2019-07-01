#include <bits/stdc++.h>

using namespace std;

#define ttd(a) ((a)<0?-(a):(a))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define maxn 105
#define x first
#define ll long long
#define y second

const double eps=0.0000001;
const double oo=10001.0;
int n1,n2;
typedef pair <double,double> ii;
ii a[maxn],b[maxn];
double res;

void input()
{
    scanf("%d",&n1);
    for(int i=1;i<=n1;++i)
        cin>>a[i].x>>a[i].y;
    scanf("%d",&n2);
    for(int i=1;i<=n2;++i)
        cin>>b[i].x>>b[i].y;
}
void init()
{
    a[n1+1]=a[1];b[n2+1]=b[1];
    res=oo;
}
ii operator +(ii u,ii v)
{
    return ii(u.x+v.x,u.y+v.y);
}
ii operator -(ii u,ii v)
{
    return ii(u.x-v.x,u.y-v.y);
}
double operator *(ii u,ii v)
{
    return u.x*v.x+u.y*v.y;
}
double cp(ii u,ii v)
{
    return u.x*v.y-u.y*v.x;
}
ii tuyentinh(ii a,ii b,ii c)
{
    return ii(cp(c,b)/cp(a,b),cp(a,c)/cp(a,b));
}
double giai(ii C,ii A,ii B)
{
    ii D=ii(C.x+A.y-B.y,C.y+B.x-A.x);
    ii r=tuyentinh(B-A,C-D,C-A);
    ii M=A+ii((B-A).x*r.x,(B-A).y*r.x);
    ii vtMA=ii(A.x-M.x,A.y-M.y),vtMB=ii(B.x-M.x,B.y-M.y);
    if(vtMA*vtMB<=0)
        return(sqrt((M.x-C.x)*(M.x-C.x)+(M.y-C.y)*(M.y-C.y)));
    return -1;
}
void solve()
{
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
        {
            double g=giai(a[i],b[j],b[j+1]);
            if(g==-1)
                continue;
            res=mini(res,g);
        }
    for(int i=1;i<=n2;++i)
        for(int j=1;j<=n1;++j)
        {
            double g=giai(b[i],a[j],a[j+1]);
            if(g==-1)
                continue;
            res=mini(res,g);
        }
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            res=mini(res,sqrt((b[j].x-a[i].x)*(b[j].x-a[i].x)+(b[j].y-a[i].y)*(b[j].y-a[i].y)));
}
void output()
{
    cout<<setprecision(6)<<fixed<<(res+eps)/2<<endl;
}

int main()
{
    freopen("polygon.inp","r",stdin);
    freopen("polygon.out","w",stdout);
    input();
    init();
    solve();
    output();
}
