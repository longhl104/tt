#include <bits/stdc++.h>

using namespace std;

#define maxn 105
#define x first
#define y second
#define ttd(a) ((a)<0?-(a):(a))

const double eps=1e-6;

typedef pair <double,double> ii;
ii p[maxn],d1,d2,dn,dt;
int n;
int dem,res;
double kc;
vector <ii> hr;

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
    return (u.x*v.x+u.y*v.y);
}
double cp(ii u,ii v)
{
    return(u.x*v.y-u.y*v.x);
}
bool iszero(double a)
{
    return (ttd(a)<=eps);
}
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        cin>>p[i].x>>p[i].y;
    p[n+1]=p[1];
    cin>>d1.x>>d1.y>>d2.x>>d2.y;
}
void init()
{
    srand(time(0));
}
bool onsegment(ii u,ii v)
{
    return (iszero(cp(u,v))&&(u*v<=0));
}
ii tuyentinh(ii A,ii B,ii C)
{
    return ii((cp(C,B))/(cp(A,B)),(cp(A,C))/(cp(A,B)));
}
bool check(ii diem)
{
    dt=diem;
    for(int i=1;i<=n;++i)
        if(onsegment(p[i]-dt,p[i+1]-dt))
            return true;
    bool result=0;
    for(int i=1;i<=n;++i)
        if(((p[i].y>dt.y)!=(p[i+1].y>dt.y))&&(dt.x<(p[i+1].x-p[i].x)*(dt.y-p[i].y)/(p[i+1].y-p[i].y)+p[i].x))
            result=!result;
    return result;
}
bool cut(ii A,ii B,ii C,ii D)
{
    bool result;
    ii r=tuyentinh(B-A,C-D,C-A);
    result=(r.x>=0&&0.000000<=r.y&&r.y<=1.000000);
    if(result)
    {
        ii z=A+ii((B-A).x*r.x,(B-A).y*r.x);
        kc=sqrt((A.x-z.x)*(A.x-z.x)+(A.y-z.y)*(A.y-z.y));
    }
    return result;
}
ii giao(ii A,ii B,ii C,ii D)
{
    ii r=tuyentinh(B-A,C-D,C-A);
    if(isnan(r.x)||isnan(r.y))
        return ii(-1.2345,1.2345);
    if(r.x<0.0||r.x>1.0||r.y<0.0||r.y>1.0)
        return ii(1.2345,-1.2345);
    ii M=A+ii((B-A).x*r.x,(B-A).y*r.x);
    return M;
}
void solve()
{
    bool c1=check(d1),c2=check(d2);
    if(!c1&&!c2)
    {
        for(int i=1;i<=n;++i)
        {
            ii giai=giao(d1,d2,p[i],p[i+1]);
            if(giai==ii(-1.2345,1.2345))
            {
                kc=sqrt((p[i].x-p[i+1].x)*(p[i].x-p[i+1].x)+(p[i].y-p[i+1].y)*(p[i].y-p[i+1].y));
                res=100*kc;
                printf("%d\n",res);
                return;
            }
            if(giai==ii(1.2345,-1.2345))
                continue;
            hr.push_back(giai);
        }
        if(hr.size()==0)
            printf("0\n");
        else
        {
            if(hr.size()==3&&hr[0]==hr[1])
                hr[1]=hr[2];
            kc=sqrt((hr[0].x-hr[1].x)*(hr[0].x-hr[1].x)+(hr[0].y-hr[1].y)*(hr[0].y-hr[1].y));
            res=100*kc;
            printf("%d\n",res);
        }
    }
    if(c1&&c2)
    {
        kc=sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
        res=100*kc;
        printf("%d\n",res);
    }
    if(c1&&!c2)
    {
        dt=d1;dn=d2;
        for(int i=1;i<=n;++i)
            if(cut(dt,dn,p[i],p[i+1]))
                break;
        res=100*kc;
        printf("%d\n",res);
    }
    if(!c1&&c2)
    {
        dt=d2;dn=d1;
        for(int i=1;i<=n;++i)
            if(cut(dt,dn,p[i],p[i+1]))
                break;
        res=100*kc;
        printf("%d\n",res);
    }
}
void output()
{

}

int main()
{
    freopen("poly.inp","r",stdin);
    freopen("poly.out","w",stdout);
    input();
    init();
    solve();
    output();
}
