#include <bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b) {
	a = a^b;
    b = a^b;
    a = a^b;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, b;
    cin >> a >> b;

    cout << "Before swapping : " << a << ' ' << b << endl;
    swapNumber(a, b);
    cout << "After swapping : " << a << ' ' << b << endl;

    
    return 0;
}