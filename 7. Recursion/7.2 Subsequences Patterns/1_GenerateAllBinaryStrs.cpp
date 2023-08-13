#include <bits/stdc++.h>
using namespace std;

void print(int k, string str){
    if (k==0) {
        cout << str << endl;
        return ;
    }

    if (str.back() == '0') {
        string str1 = str;
        str1.push_back('0');
        print(k-1, str1);

        string str2 = str;
        str2.push_back('1');
        print(k-1, str2);
    } else {
        string str3 = str;
        str3.push_back('0');
        print(k-1, str3);
    }
}

vector<string> getStrings(int k, string str){
    if (k==0) {
        // strs.push_back(getStrings);
        
        return {str} ;
    }

    vector<string> res;

    if (str.back() == '0') {
        string str1 = str;
        str1.push_back('0');
        vector<string> temp1 = getStrings(k-1, str1);

        string str2 = str;
        str2.push_back('1');
        vector<string> temp2 = getStrings(k-1, str2);
        
        for (auto it: temp1) res.push_back(it);
        for (auto it: temp2) res.push_back(it);
    } else {
        string str3 = str;
        str3.push_back('0');
        vector<string> temp3 = getStrings(k-1, str3);
        for (auto it: temp3) res.push_back(it);
    }

    return res;
}

void getStrings(int k, string str, vector<string> &strs){
    if (k==0) {
        strs.push_back(str);
        return ;
    }

    if (str.back() == '0' || str.empty()) {
        string str1 = str;
        str1.push_back('0');
        getStrings(k-1, str1, strs);

        string str2 = str;
        str2.push_back('1');
        getStrings(k-1, str2, strs);
        
    } else {
        string str3 = str;
        str3.push_back('0');
        getStrings(k-1, str3, strs);
    }

}

vector<string> generateString(int n) {
    vector<string> strs;
    getStrings(n, "", strs);
    return strs;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<string> strs1 = getStrings(n-1, "0");
    for(auto it: strs1) cout << it << " " ;

    vector<string> strs2 = getStrings(n-1, "1");
    for(auto it: strs2) cout << it << " " ;

    cout << endl;
    print(n-1, "0");
    print(n-1, "1");
    
    return 0;
}