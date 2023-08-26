#include <bits/stdc++.h>
using namespace std;

// Find single element in a vector
int findSingle(vector<int> arr, int n){

    int xor1 = 0;
    for (int i=0; i<n; i++){
        xor1 = xor1^arr[i];
    }
    
    return xor1;
    
}

// Swap two numbers
void swapTwoNums(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

// XOR of nums till n
int findXOR(int n){
    if (n%4 == 0) return n;
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n+1;
    if (n%4 == 3) return 0;
}

// Find XOR in a range
int findXORInRange(int l, int r){
    return findXOR(r)^findXOR(l-1);
}

// Even or Odd check
bool isEven(int n){
    return n&1==0;
}

// Check if ith bit is set or not
bool isIthBitSet(int n, int i){
    int mask = 1 << i;
    int res = mask&n;
    return res;
}

// Set the ith bit
int setIthBit(int n, int i) {
    int mask = 1 << i;
    int res = mask|n;
    return res;
}

// Remove the ith bit
int removeIthBit(int n, int i){
    int mask = ~(1<<i);
    int res = n&mask;
    return res;
}

// Clear the last bit
int clearLastBit(int n) {
    n = n&(n-1);
    return n;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    // Find single element in a vector
    // int n;
    // cin >> n;
    
    // vector<int> arr(n);
    // for (int i=0; i<n; i++) cin >> arr[i] ;
    // cout << findSingle(arr, n) << endl;    

    // // Swap two numbers
    // int a, b;
    // cin >> a >> b;
    // cout << "Before swapping : " << a << ' ' << b << endl;
    // swapTwoNums(a, b);
    // cout << "After swapping : " << a << ' ' << b << endl;

    int m;
    cin >> m;

    cout << clearLastBit(m);

    
    return 0;
}