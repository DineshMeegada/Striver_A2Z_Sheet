#include <bits/stdc++.h>
using namespace std;


class minHeap {
public:
    vector<int> arr;
    int size, capacity;

    // Constructor for the class.
    minHeap(int cap) {
        // Initialize the 'size' variable to 0.
        arr.resize(cap+1);
        size = 0;
        capacity = cap;
    }

    void heapify(vector<int> &arr, int n, int i) {
        int parent = i;
        int child1 = 2 * i, child2 = 2 * i + 1;

        // Correct the comparison to find the smaller child, as this is a min-heap.
        if (child1 <= n && arr[child1] < arr[parent]) parent = child1;
        if (child2 <= n && arr[child2] < arr[parent]) parent = child2;

        if (parent != i) {
            // Swap the elements if necessary to maintain the min-heap property.
            swap(arr[i], arr[parent]);
            // Recursively call heapify on the affected child.
            heapify(arr, n, parent);
        }
    }

    // Implement the function to remove the minimum element.
    int extractMinElement() {
        if (size == 0) return -1;

        int ans = arr[1];
        // Replace the root with the last element in the heap.
        arr[1] = arr[size];
        size--;

        // Call heapify to restore the min-heap property.
        heapify(arr, size, 1);

        return ans;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if (ind > size) return;

        // Replace the element to be deleted with the last element.
        arr[ind + 1] = arr[size];
        size--;

        // Call heapify to restore the min-heap property.
        heapify(arr, size, ind + 1);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        if (size == capacity) return;
        arr[++size] = val;

        int curr = size;
        while (curr > 1) {
            int parent = curr / 2;

            // Correct the comparison to ensure the parent is smaller (min-heap).
            if (arr[parent] > arr[curr]) {
                // Swap if necessary to maintain the min-heap property.
                swap(arr[parent], arr[curr]);
                curr = parent;
            } else break;
        }
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;

    minHeap h(10);
    for (int i=0; i<t; i++) {
        int option;
        cin >> option;

        if (option == 0) {
            int value = h.extractMinElement();
            cout << value << endl;
        } else if (option == 1) {
            int index;
            cin >> index;
            h.deleteElement(index);
        } else {
            int val;
            cin >> val;
            h.insert(val);
        }
    }

    
    return 0;
}