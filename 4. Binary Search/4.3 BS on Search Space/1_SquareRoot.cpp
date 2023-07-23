#include <bits/stdc++.h>
using namespace std;

int square_root(int num) {
    int low = 1, high = num;
    while (high-low > 1){
        int mid = (low + high) / 2;
        if (mid*mid > num) high = mid;
        else low = mid;
    }

    return low;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int num;
    cin >> num;

    int root = square_root(num);
    cout << root;

    
    return 0;
}