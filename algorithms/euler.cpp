#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define maxn 100001
#define maxm 1000001

int n,m,u,v;
struct st
{
    int d,c,cs;
    st(int a,int b,int c): d(a),c(b),cs(c) {}
};
vector <st> canh[maxm];
bool dd[maxm];
stack <int> s;

void input()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        canh[u].push_back(st(u,v,i));
        canh[v].push_back(st(v,u,i));
    }
}
void solve()
{
    s.push(1);
    while(!s.empty())
    {
        int i=0;
        int u=s.top();
        while(i<canh[u].size()&&dd[canh[u][i].cs])
            i++;
        if(i<canh[u].size())
        {
            s.push(canh[u][i].c);
            dd[canh[u][i].cs]=true;
        }
        else
        {
            cout<<u<<" ";
            s.pop();
        }
    }
}
void output()
{

}

int main()
{
    // freopen("123.txt","r",stdin);
    input();
    solve();
    output();
}
