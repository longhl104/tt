#include <bits/stdc++.h>
using namespace std;
#define maxn 30001
int n;
int a[maxn],b[maxn],res;
vector <int> ds;
void input()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    b[0]=INT_MAX;
}
void solve()
{
    for(int i=1;i<=n;++i)
    {
        int t=res;
        while(a[i]>=b[t])
            t--;
        b[t+1]=a[i];
        if(res<t+1)
        {
            res=t+1;
            ds.push_back(a[i]);
        }
    }
}
void output()
{
    cout<<res<<endl;
    for(int i=0;i<ds.size();++i)
        cout<<ds[i]<<" ";
}
int main()
{
    freopen("123.txt","r",stdin);
    input();
    solve();
    output();
}
