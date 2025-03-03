#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> a[2309];
int d[2309];
int n,m;

void bfs()
{
    int u,v;
    queue <int> qu;
    qu.push(1);
    d[1]=1;
    while(qu.size())
    {
        u=qu.front();
        qu.pop();
        for(int i=0;v=a[u][i];++i)
            if(d[v]==0)
            {
                d[v]=d[u]+1;
                qu.push(v);
            }
    }
}

main()
{
    int i,p,q;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&p,&q);
        a[p].push_back(q);
        a[q].push_back(p);
    }
    for(int i=1;i<=n;++i)
        a[i].push_back(0);
    bfs();
}
