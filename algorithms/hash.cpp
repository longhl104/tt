#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=1000006, BASE=1000000007;
int m, n;
char a[N], b[N];
long A[N], B[N], M[N];

void hash_build(char a[], int n, long H[]) {
    for (int i=1; i<=n; i++)
    H[i] = (H[i-1] * M[1] + a[i]) % BASE;
}

long hash_range(long H[], int L, int R) {
    return (H[R] - H[L-1]*M[R-L+1] + 1LL*BASE*BASE) % BASE;
}

main() {
    M[0]=1; M[1]=2309;
    for (int i=2; i<N; i++)
    M[i] = M[i-1] * M[1] % BASE;

    scanf("%s", a+1); m=strlen(a+1);
    scanf("%s", b+1); n=strlen(b+1);
    hash_build(a, m, A);
    hash_build(b, n, B);
    for (int i=1; i<=m-n+1; i++) {
        if (hash_range(A, i, i+n-1) == B[n])
        printf("%d ", i);
    }
    printf("\n");
}


////////////////////////////////////////////////////

/// Hash không quan trọng đúng thứ tự
/// A[] = {2,3,4};
/// B[] = {1,4,2,3};
/// day lien tiep xuat hien : 2,3,4
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
#define maxn 100001
#define base 1000000007ll

typedef long long ll;

ll n,m,res;
ll a[maxn],b[maxn];
ll M[maxn],A[maxn],B[maxn];

void hash_build(ll a[], ll n, ll H[])
{
    for (ll i=1; i<=n; ++i)
        H[i] = (H[i-1] + M[a[i]] ) % base;
}
ll hash_range(ll H[], ll L, ll R)
{
    return (H[R] - H[L-1] + 1ll*base*base) % base;
}
void input()
{
    M[0]=1; M[1]=2309;
    for (ll i=2; i<maxn; ++i)
        M[i] = M[i-1] * M[1] % base;
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    hash_build(a,n,A);
    scanf("%lld",&m);
    for(ll i=1;i<=m;++i)
        scanf("%lld",&b[i]);
    hash_build(b,m,B);
}
void init()
{
    if(n>m)
    {
        printf("NO\n");
        exit(0);
    }
    res=m+1;
}
void solve()
{
    for(ll i=n;i<=m;++i)
        if(A[n]==hash_range(B,i-n+1,i))
        {
            res=i-n+1;
            break;
        }
}
void output()
{
    if(res==m+1)
        printf("NO\n");
    else
        printf("YES\n%lld\n",res);
}

int main()
{
    freopen("esign.inp","r",stdin);
    freopen("esign.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
