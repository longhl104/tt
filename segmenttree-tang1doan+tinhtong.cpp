#include <bits/stdc++.h>
#define N 50010
using namespace std;

int n, q, L, R;
char t;
int64_t add[8*N], tree[8*N];
int64_t v, res;

void update(int node, int l, int r)
{
    tree[node] += (r-l+1)*add[node];
    add[node*2] += add[node];
    add[node*2+1] += add[node];
    add[node] = 0;
    if(r<L or R<l) return;
    if(L<=l and r<=R)
    {
        tree[node] += (r-l+1)*v;
        add[node*2] += v;
        add[node*2+1] += v;
        return;
    }
    int m=(l+r)/2;
    update(node*2, l, m);
    update(node*2+1, m+1, r);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void get(int node, int l, int r)
{
    tree[node] += (r-l+1)*add[node];
    add[node*2] += add[node];
    add[node*2+1] += add[node];
    add[node] = 0;
    if(r<L or R<l) return;
    if(L<=l and r<=R)
    {
        res += tree[node];
        return;
    }
    int m=(l+r)/2;
    get(node*2, l, m);
    get(node*2+1, m+1, r);
}

int main()
{
    freopen("123.inp","r",stdin);
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf(" %c",&t);
        if(t=='+')
        {
            scanf("%d%d%lld", &L, &R, &v);
            update(1, 1, n);
        }
        if(t=='?')
        {
            scanf("%d%d", &L, &R);
            res=0;
            get(1, 1, n);
            printf("%lld\n",res);
        }
    }
    return 0;
}
