///Tim luong cuc dai tren mang

#include <stdio.h>
#include <queue>
using namespace std;

#define long long long
void minimize(int &a, int b){ if (a>b) a=b; }

int n, m, source, target;
vector<int> a[12309];
int c[2309][2309];
int f[2309][2309];
int d[12309];

bool findpath(int start, int target){
    queue<int> qu;
    int i, u, v;
    for (i=1; i<=n; i++) d[i]=0;
    d[start] = 1000111000;
    qu.push(start);

    while (qu.size()){
        u=qu.front(); qu.pop();
        //printf("u=%d\n", u);
        if (u==target) return true;
        for (i=0; v=a[u][i]; i++)
        if (d[v]==0 && c[u][v] > f[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }
    return false;
}

void enlarge(){
    int u, v, delta=1000111000;
    for (v=target; (u=d[v])!=1000111000; v=u)
    minimize(delta, c[u][v] - f[u][v]);
    for (v=target; v!=source; v=u){
        u=d[v];
        f[u][v] += delta;
        f[v][u] -= delta;
    }
}

long answer(int u){
    int i, v;
    long r=0;
    for (i=0; v=a[u][i]; i++)
    r += f[u][v];
    return r;
}

main(){
    int i, p, q, w;
    scanf("%d%d%d%d", &n, &m, &source, &target);
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(q);
        a[q].push_back(p);
        c[p][q]=w;
    }
    for (i=1; i<=n; i++) a[i].push_back(0);
    while (findpath(source, target)) enlarge();

    printf("%lld\n", answer(source));
}

///Lat cat hep nhat trong mang

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

void minimize(int &a, int b){
    if (a>b) a=b;
}

int n, m;
vector<int> a[12309];
int start, target;
int c[123][123];
int f[123][123];
int d[12309];

bool bfs(int start, int target){
    queue<int> qu;
    int u, i, v;

    for (i=1; i<=n; i++) d[i]=0;
    d[start] = -1;
    qu.push(start);

    while (qu.size()){
        u=qu.front(); qu.pop();
        if (u==target) return true;
        for (i=0; v=a[u][i]; i++)
        if (d[v]==0 && f[u][v]<c[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }
    return false;
}

int mincut(bool tracing=false){
    int u, i, v, r=0;
    for (u=1; u<=n; u++)
    for (i=0; v=a[u][i]; i++)
    if (d[u] && !d[v]) {
        r += c[u][v];
        if (tracing) printf("%d %d\n", u, v);
    }
    return r;
}


void enlarge(){
    int i;
    int delta=1000111000;
    for (i=target; i!=start; i=d[i])
    minimize(delta, c[d[i]][i]-f[d[i]][i]);
    for (i=target; i!=start; i=d[i]){
        f[d[i]][i] += delta;
        f[i][d[i]] -= delta;
    }
}

main(){
    int i, p, q, w;
for (;;){
    scanf("%d%d", &n, &m);
    if (n==0) return 0;

    for (i=1; i<=n; i++) a[i].clear();
    for (p=1; p<=n; p++)
    for (q=1; q<=n; q++)
    c[p][q]=f[p][q]=0;

    start=1, target=2;
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(q);
        a[q].push_back(p);
        c[p][q]=c[q][p]=w;
    }
    for (i=1; i<=n; i++) a[i].push_back(0);

    while (bfs(start, target)) enlarge();
    mincut(true); printf("\n");
}
}

///Luong cuc dai tren mang nhieu dinh phat nhieu dinh thu

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define long long long
#define in -1+2*
#define out 2*

void minimize(int &a, int b){ if (a>b) a=b; }
void minimize(long &a, long b){ if (a>b) a=b; }

int n, m;
vector<int> a[12309];
char b[12309];
long c[234][234];
long f[234][234];

int d[12309];
int bfs(){
    queue<int> qu;
    int u, i, v;

    for (i=1; i<=n; i++)
    if (b[i]!='S') d[i]=0;
    else { d[i]=-1; qu.push(i); }

    while (qu.size()){
        u=qu.front(); qu.pop();
        //printf("%d\n", u);
        if (b[u]=='T') return u;
        for (i=0; v=a[u][i]; i++)
        if (d[v]==0 && c[u][v] > f[u][v]){
            d[v]=u;
            qu.push(v);
        }
    }
    return 0;
}

long enlarge(int t){
    //printf("enlarge(%d)\n", t);
    long delta = 1000111000111000111LL;
    int i;
    for (i=t; d[i]!=-1; i=d[i])
    minimize(delta, c[d[i]][i] - f[d[i]][i]);
    for (i=t; d[i]!=-1; i=d[i]){
        f[d[i]][i] += delta;
        f[i][d[i]] -= delta;
    }
    return delta;
}

main(){
    int p, q, w, i, j; long r;
while (scanf("%d", &n) > 0){
    for (i=1; i<=n; i++) {
        a[in i].clear(); a[out i].clear();
        b[in i] = b[out i] = 0;
    }
    for (i=1; i<=2*n; i++)
    for (j=1; j<=2*n; j++)
    c[i][j]=f[i][j]=0;

    for (i=1; i<=n; i++){
        scanf("%d", &p);
        a[in i].push_back(out i);
        a[out i].push_back(in i);
        c[in i][out i] = p;
    }
    scanf("%d", &m);
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[out p].push_back(in q);
        a[in q].push_back(out p);
        c[out p][in q] += w;
    }
    int ns, nt;
    scanf("%d%d", &ns, &nt);
    for (i=1; i<=ns; i++) { scanf("%d", &p); b[in p]='S'; }
    for (i=1; i<=nt; i++) { scanf("%d", &p); b[out p]='T'; }
    n=n*2;
    for (i=1; i<=n; i++) a[i].push_back(0);

    r=0;
    while (i=bfs()) r += enlarge(i);
    printf("%lld\n", r);
}
}

///Tim luong min cost tren mang

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//#define int long long

typedef pair<int, int> ii;
#define X first
#define Y second
bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }

// Network container
int n, m;
vector<ii> a[12309]; //
int c[123][123]; //
int f[123][123]; //

ii d[12309];
bool inqueue[12309];

bool fb(int start, int target){
    queue<int> qu;
    int u, i, v;

    for (i=1; i<=n; i++) { inqueue[i]=false; d[i].X=1000111000; }
    qu.push(start); inqueue[start]=true; d[start].X=0;

    while (qu.size()){
        u=qu.front(); qu.pop(); inqueue[u]=false;
        for (i=0; v=a[u][i].Y; i++)
        if (c[u][v] > f[u][v])
        if (minimize(d[v].X, d[u].X + (f[u][v]>=0 ? a[u][i].X : -a[u][i].X) )){
            d[v].Y=u;
            if (!inqueue[v])
            { qu.push(v); inqueue[v]=true; }
        }
    }
    if (d[target].X < 1000111000) return true;
    else return false;
}

int enlarge(int start, int target, int delta, int &answer){
    int i;
    for (i=target; i!=start; i=d[i].Y)
    if (f[d[i].Y][i] < 0)
    minimize(delta, - f[d[i].Y][i]);
    else
    minimize(delta, c[d[i].Y][i] - f[d[i].Y][i]);
    for (i=target; i!=start; i=d[i].Y){
        f[d[i].Y][i] += delta;
        f[i][d[i].Y] -= delta;
    }
    answer += delta * d[target].X;
    return delta;
}

main(){
    freopen("input", "r", stdin);
    int i, j, p, q, w;
    int r=0, capacity=0;
while (scanf("%d%d", &n, &m) > 0){
    for (i=1; i<=n; i++) a[i].clear();
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    f[i][j]=c[i][j]=0;
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
        c[p][q] += 1;
        c[q][p] += 1;
    }
    for (i=1; i<=n; i++) a[i].push_back(ii());
    scanf("%d%d", &capacity, &p);
    for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
    c[i][j] *= p;

    r=0;
    while (fb(1, n))
    if (capacity == 0) break;
    else capacity -= enlarge(1, n, capacity, r);
    if (capacity != 0) printf("Impossible.\n");
    else printf("%d\n", r);
}
}
