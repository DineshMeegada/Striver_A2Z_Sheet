#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend==INT_MIN && divisor==1) return INT_MIN;
    if (dividend==INT_MIN && divisor==-1) return INT_MAX ;

    bool sign = (dividend>=0 && divisor>=0) || (dividend<0 && divisor<0);

    long dvd = abs(dividend);
    long dvs = abs(divisor);

    long ans = 0;
    while (dvd >= dvs) {
        long temp = dvs, curr = 1;
        while (temp << 1 <= dvd) {
            temp = temp << 1;
            curr = curr << 1;
        }
        dvd -= temp;
        ans += curr;
    }

    if (!sign) return -ans;
    return ans; 
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, b;
    cin >> a >> b;

    return divide(a, b);

    
    return 0;
}