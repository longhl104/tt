#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
#define fi "123.INP"
#define fo "POLYGON.OUT"
const int maxN=100001;
const double epsilon=1e-6;
struct point
{
    double x,y;
};
typedef point vec;
point p[maxN];
point A,B;
int n;
bool inside;

vec make_vec(double a, double b)
{
    vec u;
    u.x=a; u.y=b;
    return u;
}
vec operator -(vec u,vec v)
{
    return make_vec(u.x-v.x,u.y-v.y);
}

double operator *(vec u, vec v)
{
    return (u.x*v.x+u.y*v.y);
}
double cp(vec u, vec v)
{
    return (u.x*v.y-u.y*v.x);
}

bool iszero(double a)
{
    return (abs(a)<=epsilon);
}

void Enter()
{
    cin>>n>>A.x>>A.y;
    for (int i=1;i<=n;++i)
        cin>>p[i].x>>p[i].y;
    p[n+1]=p[1];
}

bool onsegment(vec u, vec v)
{
    return (iszero(cp(u,v))&&(u*v<=0));
}

void make_ray()
{
    bool ok;
    do
    {
        ok=false;
        srand(time(0));
        B.x=rand(); B.y=rand();
        for (int i=1;i<=n;++i)
            if (iszero(cp(B-A,p[i]-A)))
            {
                ok=true;
                break;
            }
    }
    while (ok);
}

vec solveSLE(vec a, vec b, vec c)
{
    double D,Dx,Dy;
    D=cp(a,b);Dx=cp(c,b);Dy=cp(a,c);
    return make_vec(Dx/D,Dy/D);
}

bool cut(point C, point D)
{
    vec r;
    r=solveSLE(B-A,C-D,C-A);
    return (r.x>=0 && 0.0<=r.y && r.y<=1.0);
}

bool check()
{
    for (int i=1;i<=n;++i)
        if (onsegment(p[i]-A,p[i+1]-A))
            return true;
    make_ray();
    bool res=false;
    for (int i=1;i<=n;++i)
        if (cut(p[i],p[i+1]))
            res=!res;
    return res;
}
int main()
{
    freopen("123.inp","r",stdin);
    Enter();
    inside=check();
    if (inside)
        cout<<"Inside the polygon.\n";
    else
        cout<<"Outside the polygon.\n";
    return 0;
}
