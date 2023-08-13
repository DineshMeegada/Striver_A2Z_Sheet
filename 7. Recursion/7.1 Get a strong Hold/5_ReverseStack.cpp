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

void reverseStack(stack<int> &s){
    if (s.empty()) return ;

    int curr = s.top();
    s.pop();

    reverseStack(s);

    stack<int> tempStack;
    while(!s.empty()){
        tempStack.push(s.top());
        s.pop();
    }

    s.push(curr);

    while(!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }

}

void reverseStackBrutal(stack<int> &st) {
    stack<int> temp;
    
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    st = temp;
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

    reverseStack(s);
    printStack(s);
    

    return 0;
}