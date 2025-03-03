#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define maxsize 1000001

int a[maxsize];

void factor(int n,int &sz)
{
    int j=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
    {
        a[j]=n;
        j++;
    }
    sz=j-1;
}

int main()
{
    freopen("123.inp","r",stdin);
    int t,n,k,tam;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%d",&n);
        factor(n,k);
        tam=1;
        for(int j=1;j<=k;j++)
        {
            tam*=a[j]-1;
            n/=a[j];
        }
        printf("%d\n",tam*n);
    }
}

