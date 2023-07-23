#include <bits/stdc++.h>
using namespace std;

void pattern1(int n){
	for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    		cout << "* ";
		}
		cout << endl;
	}
}

void pattern2(int n){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			cout << "* ";
		}
		cout << endl;
	}
}

void pattern3(int n){
	for (int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cout << j ;
		}
		cout << endl;
	}
}

void pattern4(int n){
	for(int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			cout << i ;
		}
		cout << endl;
	}
}

void pattern5(int n){
	for(int i=0; i<n; i++){
		for (int j=0; j<n-i; j++){
			cout << "* ";
		}
		cout << endl;
	}
}

void pattern6(int n){
	for(int i=0; i<n; i++){
		for (int j=1; j<=n-i; j++){
			cout << j;
		}
		cout << endl;
	}
}

void pattern7(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n+i; j++){
			if (j>=n-i-1) cout << "* ";
			else cout << "  ";
		}
		cout << endl;
	}
}

void pattern8(int n){
	for (int i=0; i<n; i++){
		for(int j=0; j<2*n-i-1; j++){
			if (j>=i) cout << "* ";
			else cout << "  ";
		}
		cout << endl;
	}
}

void pattern9(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n+i; j++){
			if (j>=n-i-1) cout << "* ";
			else cout << "  ";
		}
		cout << endl;
	}
	for (int i=0; i<n; i++){
		for(int j=0; j<2*n-i-1; j++){
			if (j>=i) cout << "* ";
			else cout << "  ";
		}
		cout << endl;
	}
}

void pattern10(int n){
	for (int i=0; i<2*n-1; i++){
		int stars = i; 
		if (i>=n) stars = 2*n-i-2;
		for (int j=0; j<=stars; j++){
			cout << "* ";
		}
		cout << endl;
	}
}

void pattern11(int n){
	int start = 1;
	for (int i=0; i<n; i++){
		if (i%2==0) start = 1;
		else start = 0;
		for (int j=0; j<=i; j++){
			cout << start << " ";
			start = 1-start;
		}
		cout << endl;
	}
}

void pattern12(int n){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (j<=i) cout << j ;
			else cout << " ";
		}
		for (int j=n; j>0; j--){
			if (j<=i) cout << j;
			else cout << " ";
		}
		cout << endl;
	}
}

void pattern13(int n){
	int num = 1;
	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			cout << num << " ";
			num += 1;
		}
		cout << endl;
	}
}

void pattern14(int n){
	for (int i=0; i<n; i++){
		for (char ch='A'; ch<='A'+i; ch++){
			cout << ch << " ";
		}
		cout << endl;
	}
}

void pattern15(int n){
	for (int i=n; i>0; i--){
		for (char ch='A'; ch<'A'+i; ch++){
			cout << ch << " ";
		}
		cout << endl;
	}
}

void pattern16(int n){
	char ch = 'A';
	for (int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout << ch ;
		}
		ch++;
		cout << endl;
	}
}

void pattern17(int n){
	for (int i=0; i<n; i++){
		for (int j=1; j<n-i; j++){
			cout << " ";
		}
		
		char ch = 'A';
		for (ch ; ch<='A'+i; ch++){
			cout << ch ;
		}
		ch = ch-2;
		for (ch ; ch >='A'; ch--){
			cout << ch ;
		}
		cout << endl;
	}
}

void pattern18(int n){
	for(int i=n-1; i>=0; i--){
		char ch = 'A' + i;
		for(ch ; ch<='A'+n-1 ; ch++){
			cout << ch ;
		}
		cout << endl;
	}
}

void pattern19(int n){
	for (int i=n; i>0; i--){
		for(int j=0; j<n; j++){
			if (j<i) cout << "*";
			else cout << " ";
		}
		for (int k=n; k>0; k--){
			if (k<=i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			if (j<i) cout << "*";
			else cout << " ";
		}
		for (int k=n; k>0; k--){
			if (k<=i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	} 
}

void pattern20(int n){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (j<=i) cout << "*";
			else cout << " ";
		}
		for (int k=n; k>0; k--){
			if (k<=i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	
	for (int i=n; i>0; i--){
		for (int j=1; j<=n; j++){
			if (j<=i) cout << "*";
			else cout << " ";
		}
		for (int k=n; k>0; k--){
			if (k<=i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}

void pattern21(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i==0 || i==n-1 || j==0 || j==n-1) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}

void pattern22(int n){
	for (int i=0; i<2*n-1; i++){
		int row_num ;
		if (i<n) row_num = i;
		else row_num = 2*(n-1)-i;
		for (int j=0; j<2*n-1; j++){
			if (j>=row_num && j<2*n-1-row_num) cout << n-row_num << " ";
			else if (j<n) cout << n-j << " ";
			else cout << n - (2*(n-1)-j) << " ";
		}
		cout << endl;
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n ;
    cin >> n ;
    
    pattern22(n);
    
    
    
	
	return 0;

}
