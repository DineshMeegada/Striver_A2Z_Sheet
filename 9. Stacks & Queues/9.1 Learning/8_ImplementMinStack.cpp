#include <bits/stdc++.h>
using namespace std;

// Implement Min Stack type 1
class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    



    
    return 0;
}