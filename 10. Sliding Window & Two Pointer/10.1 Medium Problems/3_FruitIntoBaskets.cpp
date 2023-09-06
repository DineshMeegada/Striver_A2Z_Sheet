#include <bits/stdc++.h>
using namespace std;

int findMaxFruits(vector<int> &arr, int n) {
    int left = 0, right = 0;
    unordered_map<int, int> temp;
    int res = 0;

    while (right < n) {
        if (temp.find(arr[right]) == temp.end()) {
            while (temp.size()==2){
                temp[arr[left]]--;
                if (temp[arr[left]] == 0) temp.erase(arr[left]);
                left++;
            }            
        }

        res = max(res, right-left+1);
        temp[arr[right++]]++;
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int fruits = findMaxFruits(arr, n);
    cout << fruits;

    
    return 0;
}