#include <bits/stdc++.h>
using namespace std;

vector<int> getTotalExecTime(int n, vector<string> logs){
    unordered_map<int, int> start, end;
    stack<int> st;

    int mini = 1e9, maxi = 0;

    for (auto s: logs){
        string delimiter = ":";

        size_t pos = 0;
        string token;
        int ind;
        string fun;
        int time;

        pos = s.find(delimiter);
        ind = stoi(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());

        pos = s.find(delimiter);
        fun = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());

        time = stoi(s); 

        if (fun == "start") start[time] = ind;
        else end[time] = ind;

        mini = min(mini, time);
        maxi = max(maxi, time);
    }

    vector<int> ans(n);
    for (int t=mini; t<=maxi; t++){
        if (start.find(t) != start.end()) st.push(start[t]);
        else if (end.find(t) != end.end()) st.pop();

        ans[st.top()]++;
    }

    return ans;
}


// def getTotalExecTime(n, logs):
//     start, end = {}, {}
//     st = []

//     mini, maxi = 1e9, 0

//     for s in logs:
//         ind, fun, time = map(int, s.split(':'))

//         if fun == "start":
//             start[time] = ind
//         else:
//             end[time] = ind

//         mini = min(mini, time)
//         maxi = max(maxi, time)

//     ans = [0]*n
//     for t in range(mini, maxi+1):
//         if t in start:
//             st.append(start[t])
//         elif t in end:
//             st.pop()

//         ans[st[-1]] += 1

//     return ans




int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    
    
    return 0;
}