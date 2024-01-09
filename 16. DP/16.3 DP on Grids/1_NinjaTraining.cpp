#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int day, int last, vector<vector<int>> &points){
    if (day == 0){
        int maxi = 0;
        for (int task=0; task<3; task++){
            if (task != last) maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int task=0; task<3; task++){
        if (task != last) {
            int cur = points[day][task] + solve(day-1, task, points);
            maxi = max(maxi, cur);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    return solve(n-1, 3, points);
}

// Memoization
int solve2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if (dp[day][last] != -1) return dp[day][last];
    if (day == 0){
        int maxi = 0;
        for (int task=0; task<3; task++){
            if (task != last) maxi = max(maxi, points[0][task]);
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int task=0; task<3; task++){
        if (task != last) {
            int cur = points[day][task] + solve2(day-1, task, points, dp);
            maxi = max(maxi, cur);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining2(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve2(n-1, 3, points, dp);
}

// Tabulation
int ninjaTraining3(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));

    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            if (j != i) dp[0][i] = max(dp[0][i], points[0][j]);
        }
    }

    for (int day=1; day<n; day++){
        for (int last=0; last<4; last++){
            dp[day][last] = 0;
            for (int task=0; task<3; task++){
                if (task != last){
                    int cur = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], cur);
                }
            }
        }
    }

    return dp[n-1][3];
}

// Space Optimization
int ninjaTraining4(int n, vector<vector<int>> &points){
    vector<int> prev(4, 0);
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            if (j != i) prev[i] = max(prev[i], points[0][j]);
        }
    }

    for (int day=1; day<n; day++){
        vector<int> temp(4, 0);
        for (int last=0; last<4; last++){
            temp[last] = 0;
            for (int task=0; task<3; task++){
                if (task != last) {
                    int cur = points[day][task] + prev[task];
                    temp[last] = max(temp[last], cur);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int> (3, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<3; j++){
            cin >> points[i][j];
        }
    }
    
    cout << ninjaTraining2(n, points);
    
    
    return 0;
}