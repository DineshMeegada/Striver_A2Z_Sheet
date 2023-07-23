#include <bits/stdc++.h>
using namespace std;

int bruteCountInversions(vector<int> arr, int n){
    int cnt = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++){
            if (arr[i] > arr[j]) cnt ++;
        }
    }

    return cnt;
}


int merge(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int left = low, right = mid + 1;

    vector<int> temp;
    while (left <= mid && right <= high){
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return cnt;

}

int countInversions(vector<int> &arr, int left, int right) {
    int cnt = 0;
    if (left >= right) return cnt;

    int mid = (left + right) / 2;
    cnt += countInversions(arr, left, mid);
    cnt += countInversions(arr, mid+1, right);
    cnt += merge(arr, left, mid, right);

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int inversions = countInversions(arr, 0, n-1);

    cout << inversions << endl;

    return 0;
}