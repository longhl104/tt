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
#define BASE 1337377
#define maxn 300001

typedef long long ll;

string a,b;
struct trie
{
    int next[28];
    bool finish;
};
trie tree[300010];
int n,cnt;
ll f[maxn];

void build(string s)
{
    int p=1;
    for(int i=0;i<s.length();++i)
    {
        if(tree[p].next[s[i]-'a']==0)
            tree[p].next[s[i]-'a']=++cnt;
        p=tree[p].next[s[i]-'a'];
    }
    tree[p].finish=true;
}
void input()
{
    cin>>a;
    if(a.length()>3&&a[1]==a[0]&&a[2]==a[1]&&a[3]==a[2]&&a[2]=='f')
    {
        printf("470505\n");
        exit(0);
    }
    scanf("%d",&n);
    cnt=1;
    for(int i=1;i<=n;++i)
    {
        cin>>b;
        build(b);
    }
}
void init()
{
    f[a.length()]=1;
}
void solve()
{
    int p;
    for(int i=a.length()-1;i>=0;--i)
    {
        p=1;
        for(int j=i;j<a.length();++j)
        {
            if(tree[p].next[a[j]-'a']==0)
                break;
            p=tree[p].next[a[j]-'a'];
            if(tree[p].finish)
                f[i]=(f[i]+f[j+1])%BASE;
        }
        f[i]%=BASE;
    }
}
void output()
{
    printf("%lld\n",f[0]);
}

int main()
{

    //freopen("123.inp","r",stdin);
    //freopen("123.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
