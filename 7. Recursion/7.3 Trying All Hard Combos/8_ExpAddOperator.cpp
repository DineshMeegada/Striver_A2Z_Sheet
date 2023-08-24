#include <bits/stdc++.h>
using namespace std;

void solve(int i, string path, long long resSofar, long long prev, string s, int target, vector<string> &ans){
    int n = s.size();
    if (i==n){
        if (resSofar == target) ans.push_back(path);
        return ;
    }

    for (int j=i; j<n; j++){
        if (j>i && s[i]=='0') break;

        string curr = s.substr(i, j-i+1);
        long long curr_num = stoll(curr);
        if (i==0) solve(j+1, path+curr, curr_num, curr_num, s, target, ans);
        else {
            solve(j+1, path+"+"+curr, resSofar+curr_num, curr_num, s, target, ans);
            solve(j+1, path+"-"+curr, resSofar-curr_num, -curr_num, s, target, ans);
            solve(j+1, path+"*"+curr, resSofar-prev + prev*curr_num, prev*curr_num, s, target, ans);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> ans;
    solve(0, "", 0, 0, num, target, ans);
    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> ans = addOperators(s, k);
    for (auto it: ans) cout << it << endl;


    
    return 0;
}