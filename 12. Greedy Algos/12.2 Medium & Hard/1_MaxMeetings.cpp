#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool static comparator(struct meeting a, meeting b) {
    if (a.end < b.end) return true;
    if (a.end > b.end) return false;
    return (a.pos < b.pos);
}

int maximumMeetings(vector<int> &start, vector<int> &end){
    int n = start.size();
    struct meeting meet[n];

    for (int i=0; i<n; i++) {
        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i+1;
    }
    sort (meet, meet+n, comparator);

    int res = 1, prev_end = meet[0].end;
    for (auto it: meet) {
        if (it.start > prev_end) {
            res++;
            prev_end = it.end;
        }
    }

    return res;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr1(n);
    for (int i=0; i<n; i++) cin >> arr1[i] ;
    
    vector<int> arr2(n);
    for (int i=0; i<n; i++) cin >> arr2[i] ;
    
    cout << maximumMeetings(arr1, arr2);
    
    return 0;
}