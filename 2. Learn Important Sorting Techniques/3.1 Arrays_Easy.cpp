#include <bits/stdc++.h>
using namespace std;

int largestEleInArray(int arr[], int n){
	int maxi = arr[0];
	for(auto it: arr){
		if (it>maxi) maxi = it;
	}
	return maxi;
}

int secondLargest(int arr[], int n) {
    if(n<2) return -1;
    
    int max1 = INT_MIN;
    int max2 = INT_MIN;
  
	for(int i=0; i<n; i++){
		if (arr[i]>max1){
			max2 = max1;
			max1 = arr[i];
		}else if (arr[i]>max2 && arr[i]!=max1){
			max2 = arr[i];
		}
	}
	if (max2 == INT_MIN) return -1;
	return max2;
}

int removeDupsInSortedArr(int arr[], int n){
	int ind = 0;
	for (int i=1; i<n; i++){
		if (arr[i]>arr[i-1]) arr[++ind] = arr[i];
	}
	return ind+1;
}

bool isSorted(int arr[], int n){
	for(int i=0; i<nums.size()-1, i++){
		if(nums[i]>nums[i+1]) return false;
	}
	return true;
}

void rotateArray(vector<int> &nums, int k){
	int n = nums.size();
    k = k%n;
    for(int i=0; i<(n-k)/2; i++){
        swap(nums[i], nums[n-k-1-i]);
    }

    for(int i=n-k; i<n-(k/2); i++){
        swap(nums[i], nums[2*n-i-k-1]);
    }

    for(int i=0; i<n/2; i++){
        swap(nums[i], nums[n-i-1]);
    }
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	

}


