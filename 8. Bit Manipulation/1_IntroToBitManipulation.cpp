#include <bits/stdc++.h>
using namespace std;

vector<int> bitManipulation(int num, int i){
    // Write your code here.
    int add = pow(2, i-1);
    int n = num, rem;
    while (i>0) {
        rem = n%2;
        n = n/2;
        i--;
    };

    return (rem==0) ? vector<int>{rem, num+add, num} : vector<int>{rem, num, num-add};
    // if (rem == 0) return {rem, num+add, num} ;
    // return {rem, num, num-add};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int num, i;
    cin >> num >> i;

    vector<int> res = bitManipulation(num, i);
    for (auto it: res) cout << it << ' ';

    
    return 0;
}