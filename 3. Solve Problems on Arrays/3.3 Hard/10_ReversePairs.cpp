#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high){
    int cnt = 0;
    int left = low, right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else{
            if (arr[left] > arr[right]) {
                cnt += (mid - left + 1);
                cout << mid << " " << left << " " << right << endl;
                cout << low << " " << mid << " " << high << endl << endl ;
            }
            temp.push_back(arr[right++]);
        }        
    } 

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i=low; i<=high; i++) arr[i] = temp[i-low];

    return cnt;

}

int countReversePairs(vector<int> &arr, int low, int high){
    int cnt = 0;
    if (low >= high) return 0;

    int mid = (low + high) / 2;

    cnt += countReversePairs(arr, low, mid);
    cnt += countReversePairs(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int pairsCount = countReversePairs(arr, 0, n-1);

    cout << pairsCount << endl;
    
    return 0;
}