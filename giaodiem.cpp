#include <bits/stdc++.h>

using namespace std;

struct point
{
    double x,y;
};
point make_point(double a,double b)
{
    point result;
    result.x=a;result.y=b;
    return result;
}
double cp(point u,point v)
{
    return u.x*v.y-u.y*v.x;
}
point solvesle(point a,point b,point c)
{
    double delta=cp(a,b);
    return make_point(cp(c,b)/delta,cp(a,c)/delta);
}
point operator - (point a,point b)
{
    return make_point(a.x-b.x,a.y-b.y);
}

int main()
{
    point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    point r=solvesle(b-a,c-d,c-a);
    ///giao 2 duong thang
    if(isnan(r.x))
        cout<<"2 duong thang trung nhau";
    else
        if(isinf(r.x))
            cout<<"2 duong thang song song";
        else
        {
            p=a+(b-a)*r.x;
            cout<<fixed<<setprecision(4)<<p.x<<" "<<p.y;
        }
}
