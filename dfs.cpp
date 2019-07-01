#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 100005
#define f1(i,n) for (int i=1; i<=n; i++)

int n,m,cnt;
vector <int> a[maxn];
int dd[maxn],cha[maxn];

void dfs(int u)
{
    int v;
    dd[u]=++cnt;
    for(int i=0;v=a[u][i];++i)
        if(v!=cha[u]&&!dd[v])
        {
            cha[v]=u;
            dfs(v);
        }
}

int main()
{
    freopen("b.in","r",stdin);
    int n;
    scanf("%d", n);
    while (n--) {
        vector <int> ar;
        for (int i = 0; i < 9; ++i) {
            char ch;
            scanf("%c", ch);
            if (ch == 'F') ar.push_back(0);
            if (ch == 'U') ar.push_back(1);
            if (ch == 'T') ar.push_back(2);
        }
        if(ok[pack(ar)])
            printf("definable\n");
        else
            printf("undefinable\n");
    }
}
