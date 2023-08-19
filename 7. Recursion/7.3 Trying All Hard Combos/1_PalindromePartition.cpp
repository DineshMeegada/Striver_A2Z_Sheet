#include <bits/stdc++.h>
using namespace std;

// Code to find palindrome subsequences

/*bool isPal(string st){
    int i = 0, n = st.size();
    while (i<n/2){
        if (st[i]!=st[n-i-1]) return false;
        i++;
    }

    return true;
}

void helper(int ind, string s, string temp, map<int, vector<string>> &mpp){
    // cout <<ind << ' ' << temp << endl;
    if (temp!="" && isPal(temp)) {
        // cout << "entered" << endl;
        int len = temp.size();
        if (mpp.find(len) == mpp.end()) {
            mpp[len] = {temp};
        } else {
            mpp[len].push_back(temp);
        }
    }
    if (ind == s.size()) return;

    for (int i=ind; i<s.size(); i++){
        temp.push_back(s[i]);
        // cout << temp << ' ' << i << endl;
        helper(i+1, s, temp, mpp);
        temp.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    map<int, vector<string>> mpp;
    helper(0, s, "", mpp);
    for(auto len=mpp.begin(); len!=mpp.end(); len++){
        vector<string> curr;
        for (auto it: len->second) {
            curr.push_back(it);
        }
        res.push_back(curr);
    }

    return res;
}*/


bool isPal(int start, int end, string s){
    while(start<end){
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void helper(int ind, string s, vector<string> temp, vector<vector<string>> &res){
    if (ind == s.size()){
        res.push_back(temp);
        return;
    }

    for (int i=ind; i<s.size(); i++){
        if (isPal(ind, i, s)){
            temp.push_back(s.substr(ind, i-ind+1));
            helper(i+1, s, temp, res);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    helper(0, s, {}, res);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    vector<vector<string>> res = partition(s);
    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }

    
    return 0;
}