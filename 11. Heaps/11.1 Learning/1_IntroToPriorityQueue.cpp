#include <bits/stdc++.h>
using namespace std;

int pop(vector<int> &arr)
{
    if(arr.empty())return -1;
    int ans=arr[0];
    int n=arr.size();

    arr[0]=arr[n-1];
    arr.pop_back();

    n=arr.size();
    if(n==0)return ans;//edge case
    int pos=0;
    
    while(true)
    {
        int l=2*pos+1;
        int r=2*pos+2;
        int lvalue=0,rvalue=0;

        //avoid out of bound
        if(l<n)lvalue=arr[l];
        if(r<n)rvalue=arr[r];

        if(arr[pos]>=lvalue &&
           arr[pos]>=rvalue)break;
        int replace = lvalue>=rvalue? l :r;
        swap(arr[pos],arr[replace]);
        pos=replace;
    }
    return ans;

}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }