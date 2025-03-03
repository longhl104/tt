#include <bits/stdc++.h>

using namespace std;

const int maxn = 10001;

int n;
int a[maxn];

void merge(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(int i=l,j=0;i<=m;++i,++j) {
		L[j] = a[i];
	}
	for(int i=m+1,j=0;i<=r;++i,++j) {
		R[j] = a[i];
	}
	int i = l, jL = 0, jR = 0;
	while(jL<n1 && jR<n2) {
		if(L[jL] < R[jR]) {
			a[i] = L[jL];
			++jL;
		} else {
			a[i] = R[jR];
			++jR;
		}
		++i;
	}
	while(jL < n1) {
		a[i] = L[jL];
		++jL;
		++i;
	}
	while(jR < n2) {
		a[i] = R[jR];
		++jR;
		++i;
	}
}

void mergeSort(int l, int r) {
	if(l>=r)
		return;
	int m = (l+r)>>1;
	mergeSort(l,m);
	mergeSort(m+1,r);
	merge(l,m,r);
}

int main() {
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	mergeSort(0,n-1);
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
}