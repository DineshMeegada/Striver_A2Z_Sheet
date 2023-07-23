#include <bits/stdc++.h>
using namespace std;

void selection_sort(int n, int arr[]){
	for(int i=0; i<n-1; i++){
		int mini =i; 
		for(int j=i; j<n; j++){
			if (arr[mini]>arr[j]) mini = j;
		}
		int temp = arr[mini];
		arr[mini] = arr[i];
		arr[i] = temp;
	}
}

void bubble_sort(int n, int arr[]){
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++){
			if (arr[j]>arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertion_sort(int n, int arr[]){
	for(int i=0; i<n-1; i++){
		int j = i;
		while(j>0 && arr[j-1]>arr[j]){
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
		}
	}
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr [n];
	for(int i=0; i<n; i++) cin >> arr[i];
	
	bubble_sort(n, arr);
	
	for(auto it: arr) cout << it << " ";

}


