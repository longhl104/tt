#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;

int n;
int a[maxn];

void heapify(int n, int i) {
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && a[l]>a[largest]) {
		largest = l;
	}
	if(r<n && a[r]>a[largest])
		largest = r;
	if(largest!=i) {
		swap(a[largest],a[i]);
		heapify(n, largest);
	}
}

void buildHeap() {
	for(int i=n/2 - 1;i>=0;--i)
		heapify(n, i);
	for(int i=n-1;i>=0;--i) {
		swap(a[i],a[0]);
		heapify(i, 0);
	}
}

int main() {
	cin>>n;
	for(int i=0;i<n;++i) {
		cin>>a[i];
	}
	buildHeap();
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
}