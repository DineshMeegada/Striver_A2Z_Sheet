#include <bits/stdc++.h>
using namespace std;

void heapify (vector<int> &arr, int n, int i) {
    int parent = i;
    int child1 = 2*i+1, child2 = 2*i+2;

    if (child1<n && arr[child1]>arr[parent]) parent = child1;
    if (child2<n && arr[child2]>arr[parent]) parent = child2;

    if (parent != i) {
        swap(arr[parent], arr[i]);
        heapify(arr, n, parent);
    }
}

vector<int>MinToMaxHeap(int n, vector<int>&arr) {
	for (int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> maxHeap = MinToMaxHeap(n, arr);
    for (int it: maxHeap) cout << it << ' ' ;

    
    return 0;
}