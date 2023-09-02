#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>> &arr, int low, int mid, int high, vector<int> &res) {

    int left = low, right = mid+1;
    vector<pair<int, int>> temp;
    while (left <= mid && right <= high) {
        if (arr[left].first<=arr[right].first){
            temp.push_back(arr[right++]);
        } else {
            res[arr[left].second] += high - right + 1;
            temp.push_back(arr[left++]);
        }
    }

    while (left<=mid) temp.push_back(arr[left++]);
    while (right<=high) temp.push_back(arr[right++]);

    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}




// void merge(vector<pair<int, int>> &arr, int low, int mid, int high, vector<int> &res) {
//     // cout << low << ' ' << mid << ' ' << high << endl << "Current Array : " << endl;
//     // for (auto it: arr) cout << it.first << ' ' << it.second << endl;

//     int l = low;
//     while (l<=mid){
//         int curr = arr[l].first;

//         int j = mid+1;
//         while (j<=high && arr[j].first < curr) j++;

//         res[arr[l].second] += j-mid-1;
//         l++;
//     }

//     // for (auto it: res) cout << it << ' ';
//     // cout << endl << endl;


//     int left = low, right = mid+1;
//     vector<pair<int, int>> temp;
//     while (left <= mid && right <= high) {
//         if (arr[left]<=arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while (left<=mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while (right<=high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for (int i=low; i<=high; i++) {
//         arr[i] = temp[i-low];
//     }
// }

void mergeSort(vector<pair<int, int>> &arr, int low, int high, vector<int> &res){
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, res);
    mergeSort(arr, mid+1, high, res);
    merge(arr, low, mid, high, res);
}

vector<int> countSmaller(vector<int> &arr){
    int n = arr.size();
    vector<pair<int, int>> hold;
    for (int i=0; i<n; i++) hold.push_back({arr[i], i});

    vector<int> res(n, 0);
    mergeSort(hold, 0, n-1, res);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    // mergeSort(arr, 0, n-1);
    // for (auto it: arr) cout << it << ' ' ;

    vector<int> ans = countSmaller(arr);
    for (auto it: ans) cout << it << ' ' ;
    
    return 0;
}