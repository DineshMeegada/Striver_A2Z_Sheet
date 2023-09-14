class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if (q1.empty() || num<q1.top()) q1.push(num);
        else q2.push(num);

        if (q1.size() > q2.size()+1) {
            q2.push(q1.top());
            q1.pop();
        } else if (q2.size() > q1.size()+1) {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        if (q1.size()==q2.size()) return (q1.size()==0) ? 0 : (q1.top()+q2.top())/2.0 ;
        else return (q1.size()>q2.size()) ? q1.top() : q2.top();
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    
    
    return 0;
}