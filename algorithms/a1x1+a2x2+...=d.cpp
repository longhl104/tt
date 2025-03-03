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
#define maxn 101
#define maxd 1000001

typedef long long ll;

int n,d;
int a[maxn],sc[maxd],dd[maxd],cnt[maxn];

void input()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
}
void init()
{
    for(int i=1;i<=n;++i)
        if(d<a[i])
        {
            printf("NO\n");
            exit(0);
        }
    dd[0]=true;
}
void solve()
{
    for(int i=1;i<=n;++i)
        for(int j=a[i];j<=d;++j)
            if(!dd[j]&&dd[j-a[i]])
            {
                dd[j]=true;
                sc[j]=i;
            }
    if(!dd[d])
    {
        printf("NO\n");
        exit(0);
    }
    for(int i=d;i>0;i-=a[sc[i]])
        ++cnt[sc[i]];
    for(int i=1;i<=n;++i)
        ++cnt[i];
}
void output()
{
    printf("YES\n");
    for(int i=1;i<=n;++i)
    {
        if(i>1)
            printf(" ");
        printf("%d",cnt[i]);
    }
    printf("\n");
}

int main()
{
    //freopen("candies.in","r",stdin);
    //freopen("candies.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}

