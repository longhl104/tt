#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
using namespace std;

#define negativearray(temp,type,name,size) type temp[size]; type * name = temp + (size/2)

void minimize(int &a, int b){ if (a>b) a=b; }

int m, n;
negativearray(asdfjh,   vector<int>, a, 102309);
negativearray(weryjj,   vector<int>, ar, 102309);
negativearray(asfjhh,   int, value, 102309);
negativearray(asdklf,   int, num, 102309);
negativearray(asiodf,   int, low, 102309);
negativearray(weruiy,   int, label, 102309);


void setFalse(int u){
    int i, v;
    if (value[u]==2) return ;
    value[u]=2;
    for (i=0; v=ar[u][i]; i++)
    setFalse(v);
}

int cnt=0;
stack<int> st;

void NIE(){
    puts("NO");
    exit(0);
}

void visit(int u){
    //printf("visit(%d)\n", u);
    int i, v;
    num[u]=++cnt;
    low[u]=num[u];
    st.push(u);

    for (i=0; v=a[u][i]; i++)
    if (num[v]) minimize(low[u], num[v]);
    else {
        visit(v);
        minimize(low[u], low[v]);
    }

    if (num[u]==low[u])
    do {
        v=st.top(); st.pop();
        num[v]=low[v]=1000111000;
        label[v]=u;
        //printf("%d in %d\n", v, u);
        if (value[u]==2) continue;

        if (value[v]==2) NIE();
        else value[v]=1;
        setFalse(-v);
    } while (u!=v);
}

vector<int> T;
main(){
    int i, p, q;
    scanf("%d%d", &m, &n);
    for (i=1; i<=m; i++){
        scanf("%d%d", &p, &q);
        a[-p].push_back(q);
        a[-q].push_back(p);
        ar[q].push_back(-p);
        ar[p].push_back(-q);
    }
    for (i=-n; i<=n; i++) a[i].push_back(0);
    for (i=-n; i<=n; i++) ar[i].push_back(0);
    for (i=1; i<=n; i++) if (num[i]==0) visit(i);
//    for (i=1; i<=n; i++) printf(i==n?"%d\n":"%d ", value[i]);
    for (i=1; i<=n; i++) if (label[i]==label[-i]) NIE();
    for (i=1; i<=n; i++) if (value[i]==value[-i]) NIE();
    for (i=1; i<=n; i++) if (value[i]==1) T.push_back(i);
    printf("YES\n%d\n", T.size());
    for (i=0; i<T.size(); i++) printf("%d ", T[i]);
    printf("\n");
}
