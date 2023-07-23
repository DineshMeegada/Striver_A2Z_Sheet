#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
	int count = 0;
	while (n>0){
		count++ ;
		n /= 10;
	}
	return count;
}

int reverseNum(int n){
	int rev = 0;
	while (n>0){
		rev = rev*10 + n%10;
		n /= 10;
	}
	return rev;
}

bool checkPalindrome(int n){
	int dup = n;
	int rev = 0;
	while (n>0){
		rev = rev*10 + n%10;
		n /= 10;
	}
	return dup==rev;
}

bool armstrongNum(int n){
	int dup = n;
	int sum = 0;
	while (n>0){
		int rem = n%10;
		sum += rem*rem*rem;
		n /= 10;
	}
	return dup==sum;
}

void printDivisors(int n){
	vector<int> divs;
	for(int i=1; i*i<=n; i++){
		if (n%i == 0){
			divs.push_back(i);
			if (n/i != i){
				divs.push_back(n/i);
			}
		}
	}
	sort(divs.begin(), divs.end());
	
//	for(int i=0; i<divs.size(); i++){
//		cout << divs[i] << " ";
//	}
	for(auto it : divs) cout << it << " " ;
	
}

bool checkPrime(int n){
	int cnt = 0;
	for(int i=1; i*i<=n; i++){
		if (n%i==0){
			cnt++;
			if (i != n/i){
				cnt++;
			}
		}
	}
	if (cnt==2) return true;
	return false;
}

int gcd(int a, int b){
	while (a>0 && b>0){
		if (a>b) a=a-b;
		else b=b-a;
	}
	if (a>0) return a;
	return b;
}

int main() {
	
	freopen("C:\\Users\\DINI\\Documents\\C++\\A2Z_Sheet\\input.txt", "r", stdin);
	freopen("C:\\Users\\DINI\\Documents\\C++\\A2Z_Sheet\\output.txt", "w", stdout);
	
	int n;
	cin >> n ;
	
	printDivisors(n);
	
	
	
}
