#include <bits/stdc++.h>
using namespace std;


int maxPoints(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int frontScore = 0, endScore = 0;
    for (int i=0; i<k; i++) {
        frontScore += cardPoints[i];
    }

    int resScore = frontScore;
    for (int i=k-1; i>=0; i--) {
        frontScore -= cardPoints[i];
        endScore += cardPoints[n-(k-i)];

        resScore = max(resScore, frontScore+endScore);
    }

    return resScore;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    

    int points = maxPoints(arr, k);
    cout << points;

    
    return 0;
}