#include <bits/stdc++.h>
using namespace std;

int cnt = 0 ;
void printSomething(int n){
	if (cnt == n) return ;
	cout << cnt << endl ;
	cnt++;
	printSomething(n);
}

void printName(string name, int n){
	if (cnt == n) return ;
	cout << name << endl;
	cnt++;
	printName(name, n);
}

void printNum(int i, int n){
	if (i<1) return;
	cout << i << " ";
	printNum(i-1, n);
	
}

int sumN(int i, int n){
	if (i==n) return n;
	return (sumN(i+1, n) + i);
}

int factorial(int n){
	if (n<=1) return 1;
	return n*factorial(n-1);
}

void reverse(int i, int arr[], int n){
	if (i>=n-i-1) return ;
	swap(arr[i], arr[n-i-1]);
	reverse(i+1, arr, n);
}

bool isPalindrome(int i, string name){
	if (i>=name.size()/2) return true;
	if (name[i] != name[name.size()-i-1]) return false;
	return isPalindrome(i+1, name);
}

int fibonacci(int n){
	if (n<=1) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	cout << fibonacci(n);
	
	
	
}

