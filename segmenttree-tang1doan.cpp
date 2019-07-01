#include <bits/stdc++.h>

#define MaxN 55555
#define INF 1000000000

using namespace std;

int n, m;
int Tree[4 * MaxN];
int Max[4 * MaxN];

void update(int u, int v, int l, int r, int node, int value){
    int mid;
    if ((v < l) || (u > r)) return;
    if ((u <= l) && (r <= v)){
        Tree[node] += value;
        Max[node] += value;
        return;
    }

    Tree[2 * node] += Tree[node];
    Max[2 * node] += Tree[node];
    Tree[2 * node + 1] += Tree[node];
    Max[2 * node + 1] += Tree[node];
    Tree[node] = 0;

    mid = (l + r) / 2;
    update(u, v, l, mid, 2 * node, value);
    update(u, v, mid + 1, r, 2 * node + 1, value);
    Max[node] = max(Max[2 * node], Max[2 * node + 1]);
}

int get(int u, int v, int l, int r, int node, int add){
    int mid;
    if ((v < l) || (u > r)) return -INF;
    if ((u <= l) && (r <= v)) return Max[node] + add;
    mid = (l + r) / 2;
    add += Tree[node];
    int Left = get(u, v, l, mid, 2 * node, add);
    int Right = get(u, v, mid + 1, r, 2 * node + 1, add);
    return max(Left, Right);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i, j, x, y, value;

    cin >> n >> m;

    memset(Tree, 0, sizeof(Tree));
    memset(Max, 0, sizeof(Max));

    for (i = 1; i <= m; i++){
        cin >> j;
        if (j == 0){
            cin >> x >> y >> value;
            update(x, y, 1, n, 1, value);
        }else{
            cin >> x >> y;
            cout << get(x, y, 1, n, 1, 0) << "\n";
        }
    }
}
