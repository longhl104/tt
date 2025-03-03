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
#define maxn 30005

typedef long long ll;

int test,n,res1,res2;
int a[maxn],l[maxn],r[maxn];
ll res;

void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
}
void init()
{
    for(int i=1;i<=n;++i)
    {
        l[i]=i;
        while(a[i]<=a[l[i]-1])
            l[i]=l[l[i]-1];
    }
    for(int i=n;i>=1;--i)
    {
        r[i]=i;
        while(a[i]<=a[r[i]+1])
            r[i]=r[r[i]+1];
    }
    res=0;
}
void solve()
{
    for(int i=1;i<=n;++i)
        if(res<1ll*a[i]*(r[i]-l[i]+1))
        {
            res=1ll*a[i]*(r[i]-l[i]+1);
            res1=l[i];res2=r[i];
        }
}
void output()
{
    printf("%lld %d %d\n",res,res1,res2);
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
