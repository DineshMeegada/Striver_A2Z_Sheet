#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
	int left = low;
	int right = mid+1;
	vector<int> temp;	
	while(left<=mid && right<=high){
		if(arr[left]<arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}else {
			temp.push_back(arr[right]);
			right++;
		}		
	}
	
	while (left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}
	
	for (int i=low; i<=high; i++){
		arr[i] = temp[i-low];
	}
}

void mergeSort(vector<int> &arr, int low, int high){
	if (low >= high) return ;
	
	int mid = (low + high)/2 ;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}



int partition(vector<int> &arr, int low, int high){
	int pivot = arr[low];
	int left = low, right = high;
	
	while (left<right){
		while(arr[left]<=pivot && left<high) left++;
		while(arr[right]>pivot && right>low) right--;
		if (left<right) swap(arr[left], arr[right]);
	}
	swap(arr[low], arr[right]);
	
	return right;
}

void quickSort(vector<int> &arr, int low, int high){
	if(low>=high) return;
	
	int partition_ind = partition(arr, low, high);
	quickSort(arr, low, partition_ind-1);
	quickSort(arr, partition_ind+1, high);
	
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n ;
	
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i] ;
	
	cout << "Before Sorting : \n" ;
	for (auto it : arr) cout << it << " ";
	
	quickSort(arr, 0, arr.size()-1);
	
	cout << "\n\nAfter Sorting : \n" ;
	for (auto it : arr) cout << it << " " ;
	
	
	
}



