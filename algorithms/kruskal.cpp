#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1001
#define maxm maxn*(maxn-1)/2

int n,m;
int lab[maxn];
struct st
{
    int u,v,w;
    bool dd;
};
st e[maxm];
int dem;

void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
}
int findset(int i)
{
    int result;
    if(lab[i]<=0)
        result=i;
    else
    {
        result=findset(lab[i]);
        lab[i]=result;
    }
    return result;
}
bool cmp(st a,st b)
{
    return a.w<b.w;
}
void hop(int r,int s)
{
    if(lab[r]<lab[s])
        lab[s]=r;
    else
    {
        if(lab[r]==lab[s])
            lab[s]--;
        lab[r]=s;
    }
}
void solve()
{
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int r=findset(e[i].u);
        int s=findset(e[i].v);
        if(r!=s)
        {
            e[i].dd=true;
            dem++;
            hop(r,s);
        }
    }
}
void output()
{
        int s=0;
        for(int i=1;i<=m;i++)
            if(e[i].dd)
                cout<<e[i].u<<" "<<e[i].v<<endl;
}

int main()
{
    freopen("123.txt","r",stdin);
    input();
    solve();
    output();
}
