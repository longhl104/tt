#include <stdio.h>

#define SIZE 10

template <class _T>
struct matrix {
    _T a[SIZE][SIZE];
    int m, n;
    _T* operator[] (int i){ return a[i]; }
    const _T* operator[] (int i) const { return a[i]; }
    void clear(int M, int N){ m=M,n=N; int i, j; for (i=1; i<=m; i++) for (j=1; j<=n; j++) a[i][j]=0; }
    void operator = (const matrix &A);
    matrix (int M, int N){ clear(M, N); }
};

template <class _T> matrix<_T>
basedMatrix(int n){
    matrix<_T> R(n,n);
    for (int i=1; i<=n; i++) R[i][i]=1;
    return R;
}

template <class _T> matrix<_T>
operator * (const matrix<_T> &A, const matrix<_T> &B){
    matrix<_T> C(A.m, B.n);
    int i, j, k;
    for (i=1; i<=A.m; i++)
    for (j=1; j<=B.n; j++)
    for (k=1; k<=A.n; k++)
    C[i][j] += A[i][k] * B[k][j];
    return C;
}

template <class _T> matrix<_T>
operator ^ (const matrix<_T> &A, int k){
    if (k==0) return basedMatrix<_T>(A.n);
    if (k==1) return A;
    matrix <_T> p = A^(k/2);
    p=p*p;
    if (k&1) return p*A;
    else return p;
}

template <class _T> void matrix<_T> ::
operator = (const matrix<_T> &A){
    int i, j;
    for (i=1; i<=A.m; i++)
    for (j=1; j<=A.n; j++)
    a[i][j]=A[i][j];
    m=A.m, n=A.n;
}


matrix <long long> A(2,2);
main(){
    A[1][1]=1;
    A[2][1]=1;
    A[1][2]=1;
    A[2][2]=0;
    A=A^90;
    printf("%lld\n", A[2][2]);

}
