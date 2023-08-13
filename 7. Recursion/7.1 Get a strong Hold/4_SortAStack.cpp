#include <bits/stdc++.h>
using namespace std;

stack<int> createStack(vector<int> arr){
    stack<int> st;
    for (int it: arr) st.push(it);

    return st;
}

void printStack(stack<int> s){
    while (!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

    cout << endl;
}

void sortStack(stack<int> &s){
    if(s.empty()) return ;

    int curr = s.top();
    s.pop();
    sortStack(s);

    stack<int> tempStack;
    
    while (!s.empty() && s.top()>curr){
        tempStack.push(s.top());
        s.pop();
    }

    s.push(curr);

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    stack<int> s = createStack(arr);
    printStack(s);

    sortStack(s);
    printStack(s);

    
    return 0;
}