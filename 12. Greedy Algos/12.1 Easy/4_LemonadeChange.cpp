#include <bits/stdc++.h>
using namespace std;

bool lemonadeChangePartial(vector<int>& bills) {
    vector<int> temp = {0, 0, 0};
    unordered_map<int, int> mp = {{0,5}, {1,10}, {2,20}};

    for (int bill: bills) {
        if (bill == 5) temp[0]++;
        else if (bill == 10) temp[1]++;
        else temp[2]++;

        int rem = bill-5, i=2;
        while (rem>0 && i>=0) {
            if (temp[i]>0 && rem-mp[i]>=0){
                rem -= mp[i];
                temp[i]--;
            }else i--;
        }
        if (rem != 0) return false;
    }

    return true;
}

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill: bills) {
        if (bill == 5) five++;
        else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            if (five>0 && ten>0) {
                five--;
                ten--;
            }else if (five >= 3) five -= 3;
            else return false;
        }
    }

    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    
    
    return 0;
}