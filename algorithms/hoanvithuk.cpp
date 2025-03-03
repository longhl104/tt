#include
#include

#define fi "HOANVI.INP"

using namespace std;

typedef unsigned long long ull;
ull dem = 0;

int n;
ull k;
ull * gt;
int * ThuTu;

void Nhap() {
    fstream f(fi, ios :: in);
    f >> n;
    f >> k;
    f.close();
}

void Init() {
    ThuTu = new int[n+1];
    int i;
    for (i=1; i<=n; i++) ThuTu[i] = i;
}

void XoaViTri(int k) {
    int i;
    for (i=k; i<n; i++) ThuTu[i] = ThuTu[i+1];
    n--;
}

void TinhGiaiThua(int n) {
    gt = new ull[n+1];
    gt[0] = 1;
    int i;
    for (i=1; i<=n; i++) gt[i] = i*gt[i-1]; }   void ThucHien() {     int x;     while (n > 0) {
        //x = TimKiemNhiPhan(k, 1, n, n);
        x = gt[n]/gt[n-1];
        if (gt[n]%gt[n-1] != 0) x++;
        cout << ThuTu[x] << "   ";
        k = k - (x-1)*gt[n-1];
        XoaViTri(x);
    }

}

int main() {
    Nhap();
    Init();
    TinhGiaiThua(n);
    ThucHien();
    //cout << endl << "k = " << k;
}
