#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
    heap () {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index/2;
            if (arr[parent] < arr[index]){ 
                swap(arr[parent], arr[index]);
                index = parent;
            }else return ;
        }
    }

    void print() {
        for (int i=1; i<=size; i++) {
            cout << arr[i] << ' ' ;
        } cout << endl;
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Nothing to delete" ;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size) {
            int child1 = i*2, child2 = i*2+1;

            if (child1 < size && arr[i] < arr[child1]) {
                swap(arr[child1], arr[i]);
                i = child1;
            } else if (child2 < size && arr[i] < arr[child2]) {
                swap(arr[child2], arr[i]);
                i = child2;
            } else return;
        }
    }

};

void heapify(int arr[], int n, int i) {
    int parent = i;
    int child1 = i*2, child2 = i*2+1;

    if (child1 <= n && arr[child1] > arr[parent]) parent = child1;
    if (child2 <= n && arr[child2] > arr[parent]) parent = child2;

    if (parent != i) {
        swap(arr[parent], arr[i]);
        heapify(arr, n, parent);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while (size>1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteMax();
    h.print();
    h.deleteMax();
    h.print();    

    int n = 5;
    int arr[] = {-1, 54, 53, 55, 52, 50};

    for (int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    cout << endl << "Printing the heap : " << endl;
    for (int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }cout << endl;

    heapSort(arr, n);
    cout << endl << "Printing the sorted heap : " << endl;
    for (int i=1; i<=n; i++){
        cout << arr[i] << ' ';
    }cout << endl;
    
    return 0;
}