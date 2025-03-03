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

typedef long long ll;
typedef pair <ll,ll> ii;

ll a,b,c;
int res;

void input()
{
    scanf("%lld%lld",&a,&b);
}
void init()
{

}
ii nghiem(ll a,ll b)
{
    ll m=a,n=b;
    ll xm=1,xn=0,q,xr,r;
    while(n)
    {
        q=m/n;
        r=m-q*n;
        xr=xm-q*xn;
        m=n;xm=xn;
        n=r;xn=xr;
    }
    return ii(m,xm);
}
void solve()
{
    cout<<nghiem(a,b).second<<" "<<(nghiem(a,b).first-a*nghiem(a,b).second)/b;
}
void output()
{

}

int main()
{
    freopen("diophante.inp","r",stdin);
    freopen("diophante.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
