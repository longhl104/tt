#include <stdio.h>

struct bit_tree {
    int n;
    int T[1230997];
    void clear(int N){ int i; n=N; for (i=1; i<=n; i++) T[i]=0; }
    void update(int p, int k){ int i; for (i=p; i<=n; i+=i&-i) T[i]+=k; }
    int get(int p){ int i; int r=0; for (i=p; i>=1; i-=i&-i) r+=T[i]; return r; }
};

struct super_bit {
    bit_tree tr, lazy;
    void clear(int N){ tr.clear(N); lazy.clear(N); }
    void update(int u, int x){ tr.update(u,u*x); lazy.update(u,x); }
    int get(int u){ return tr.get(u) + u*(lazy.get(tr.n)-lazy.get(u)); }
    void update(int ll, int rr, int x){ update(rr,x); update(ll-1,x); }
    int get(int ll, int rr){ return get(rr)-get(ll-1); }
};

super_bit tr;
int n, m;

main(){
    int i, u, x; char option;
    scanf("%d%d", &n, &m);
    tr.clear(n);

    for (i=1; i<=m; i++){
        scanf(" %c%d%d", &option, &u, &x);
        if (option=='+') tr.update(u,x);
        else printf("%d\n", tr.get(u,x));
    }
}
