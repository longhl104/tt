#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int oo = 1000111000;
typedef pair <int, int> ii;

vector <ii> a[2309];
int n, m;
int d[2309];

void dijkstra()
{
    priority_queue <ii,vector<ii>,greater<ii> > pq;
    int u,v,du,uv;
    for(int i=1;i<=n;++i)
        d[i]=oo;
    d[1]=0;
    pq.push(ii(0,1));
    while(pq.size())
    {
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if(u==t)
            return;
        if(du==d[u])
            for(int i=0;v=a[u][i].second;++i)
            {
                uv=a[u][i].first;
                if(d[v]>du+uv)
                {
                    d[v]=du+uv;
                    pq.push(ii(d[v],v));
                }
            }
    }
}

int main()
{
    int p,q,m,w;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&p,&q,&w);
        a[p].push_back(ii(w,q));
        a[q].push_back(ii(w,p));
    }
    for(int i=1;i<=n;++i)
        a[i].push_back(ii(0,0));
    dijkstra();
}
