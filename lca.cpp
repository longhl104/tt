#include <bits/stdc++.h>

using namespace std;

#define ttd(a) ((a)<0?-(a):(a))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define maxn 100010
#define oo INT_MAX

typedef pair <int,int> ii;
typedef pair <int,ii> iii;

vector <ii> l[maxn];
ii cha[maxn];
int g[maxn][21];
int dmin[maxn][21];
int dmax[maxn][21];
int n;
int d[maxn];

void dfs(int u)
{
    for(int v=0;v<l[u].size();++v)
    {
        int j=l[u][v].first;
        if(cha[u].first!=j&&cha[j].first==-1)
        {
            cha[j]=ii(u,l[u][v].second);
            d[j]=d[u]+1;
            dfs(j);
        }
    }
}
void lca()
{
    cha[1]=ii(0,0);
    for(int i=2;i<=n;++i)
        cha[i]=ii(-1,0);
    d[1]=0;
    dfs(1);
    for(int i=2;i<=n;++i)
    {
        g[i][0]=cha[i].first;
        dmin[i][0]=dmax[i][0]=cha[i].second;
    }
    g[1][0]=0;
    dmin[1][0]=oo;
    dmax[1][0]=-1;
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i<=n;++i)
        {
            g[i][j]=g[g[i][j-1]][j-1];
            dmin[i][j]=mini(dmin[i][j-1],dmin[g[i][j-1]][j-1]);
            dmax[i][j]=maxi(dmax[i][j-1],dmax[g[i][j-1]][j-1]);
        }
}
iii truyvan(int a, int b)
{
    if(d[a]<d[b])
        return truyvan(b,a);
    int rmax=-1,rmin=oo;
    int k=d[a]-d[b];
    for(int j=0;(1<<j)<=k;++j)
        if((1<<j)&k)
        {
            rmax=maxi(rmax,dmax[a][j]);
            rmin=mini(rmin,dmin[a][j]);
            a=g[a][j];
        }
    if(a==b)
        return iii(a,ii(rmin,rmax));
    k=0;
    while(g[a][k]!=g[b][k])
        ++k;
    --k;
    for(int j=k;j>=0;--j)
        if(g[a][j]!=g[b][j])
        {
            rmin=mini(rmin,mini(dmin[a][j],dmin[b][j]));
            rmax=maxi(rmax,maxi(dmax[a][j],dmax[b][j]));
            a=g[a][j];b=g[b][j];
        }
    rmin=mini(rmin,mini(cha[a].second,cha[b].second));
    rmax=maxi(rmax,maxi(cha[a].second,cha[b].second));
    return iii(cha[a].first,ii(rmin,rmax));
}

int main()
{
    freopen("123.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        l[u].push_back(ii(v,w));
        l[v].push_back(ii(u,w));
    }
    lca();
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        iii p=truyvan(i,j);
        printf("%d %d %d\n",p.first,p.second.first,p.second.second);
    }
}
