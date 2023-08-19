#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> letters = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void helper(int ind, string digits, string temp, vector<string> &res){
    if (ind == digits.size()) {
        res.push_back(temp);
        return;
    }

    char digit = digits[ind];
    string curr = letters[digit];

    for (int i=0; i<curr.size(); i++) {
        temp.push_back(curr[i]);
        helper(ind+1, digits, temp, res);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    helper(0, digits, "", res);
    return res;
}

int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    vector<string> combos = letterCombinations(s);
    for (auto it: combos) cout << it << endl;

    
    return 0;
}