Bài toán
Cho hai mảng a, b, thực hiện các thao tác.
1. Gán k phần tử của a tính từ vị trí x vào k phần tử của b tại vị trí y (gán b[y+i] bằng a[x+i] với mọi 0<=i<k)
2. In ra giá trị phần tử thứ x.
Độ phức tạp
O(logn) với mỗi truy vấn.

Code này của Nguyễn Tiến Trung Kiên
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 2000006
int n, m, a0[N], b0[N];
int Lazy[N];

struct node {
   int ll, rr, Index, Size;
   node(int L, int R, int ID){ ll=L, rr=R, Index=ID, Size=rr-ll+1; }
   node left(){ return node(ll, (ll+rr)/2, Index*2); }
   node right(){ return node((ll+rr)/2+1, rr, Index*2+1); }

   void access(){
      if (Lazy[Index] && ll!=rr){
         Lazy[Index*2]=Lazy[Index];
         Lazy[Index*2+1]=Lazy[Index]+left().Size;
         Lazy[Index]=0;
      }
   }
   int get(int X){ access();
      if (rr<X || X<ll) return 0;
      if (ll==rr) return Lazy[Index];
      return left().get(X) + right().get(X);
   }
   int update(int L, int R, int X){ access();
      if (ll>R || L>rr || L>R) return 0;
      if (L<=ll && ll<=rr && rr<=R) { Lazy[Index]=X; access(); return Size; }
      int Solved = left().update(L, R, X);
      return Solved + right().update(L, R, X+Solved);
   }
};

main(){
   ios :: sync_with_stdio(false);
   cin >> n >> m;
   f1(i,n) cin >> a0[i];
   f1(i,n) cin >> b0[i];

   f1(i,m){
      int ch, x, y, z;
      cin >> ch;
      if (ch==1) { cin >> x >> y >> z; node(1,n,1).update(y, y+z-1, x); }
      else { cin >> x; y=node(1,n,1).get(x); cout << (y==0?b0[x]:a0[y]) << '\n'; }
   }
}
