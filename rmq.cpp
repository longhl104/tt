#include <stdio.h>
#include <math.h>

int a[230997];
int M[230997][23];
int n, m;

int max(int a, int b){ return a>b?a:b; }

main(){
    int i,k;
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++)
    scanf("%d", &a[i]);

    for (i=1; i<=n; i++) M[i][0]=a[i];

    for (k=1; (1<<k)<=n; k++)
    for (i=1; i+(1<<k)-1<=n; i++)
    M[i][k] = max(M[i][k-1], M[i+(1<<(k-1))][k-1]);

    int u, v;
  while(m--){
    scanf("%d%d", &u, &v);
    k=log2(v-u+1);
    printf("%d\n", max(M[u][k],M[v-(1<<k)+1][k]));
  }
}
