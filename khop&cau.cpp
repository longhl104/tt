#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define maxn 10001
#define maxm 50001
#define oo INT_MAX
#define mini(a,b) ((a)<(b)?(a):(b))

int n,m;
vector <int> l[maxn];
int num[maxn],cha[maxn],low[maxn],numcon[maxn];
int dem;
int res2;
set <int> res1;

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int u,v;scanf("%d%d",&u,&v);
        l[u].push_back(v);l[v].push_back(u);
    }
}
void init()
{

}
void dfs(int u)
{
    ++dem;
    num[u]=dem;
    low[u]=oo;
    for(int v=0;v<l[u].size();++v)
        if(l[u][v]!=cha[u])
            if(num[l[u][v]]>0)
                low[u]=mini(low[u],num[l[u][v]]);
            else
            {
                cha[l[u][v]]=u;
                dfs(l[u][v]);
                low[u]=mini(low[u],low[l[u][v]]);
            }
}
void dfs()
{
    for(int i=1;i<=n;++i)
        if(num[i]==0)
        {
            cha[i]=-1;
            dfs(i);
        }
}
void solve()
{
    dfs();
    cout<<"cau: \n";
    for(int i=1;i<=n;++i)
        if(cha[i]!=-1)
        {
            ++numcon[cha[i]];
            if(low[i]>=num[i])
                cout<<i<<" "<<cha[i]<<"\n";
        }
    cout<<"khop: \n";
    for(int i=1;i<=n;++i)
        if(cha[i]==-1)
        {
            if(numcon[i]>=2)
                res1.insert(i);
        }
        else
            if(low[i]>=num[cha[i]]&&cha[cha[i]]!=-1)
                res1.insert(cha[i]);
}
void output()
{
    for(set <int> :: iterator it=res1.begin();it!=res1.end();++it)
        cout<<*it<<"\n";
}

int main()
{
    freopen("123.inp","r",stdin);
    freopen("123.out","w",stdout);
    input();
    init();
    solve();
    output();
    return 0;
}
