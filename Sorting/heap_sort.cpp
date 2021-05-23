#include<iostream>
using namespace std;

#define left 2 * parent + 1
#define right 2 * parent + 2

void heapify(int arr[], int parent, int n) {

  int max = parent;
  
  if(left <= n and arr[left] > arr[max])
    max = left;

  if(right <= n and arr[right] > arr[max])
    max = right;

  if(max != parent) {
    swap(arr[max], arr[parent]);
    heapify(arr, max, n);
  }
}

void heapSort(int arr[], int n) {

  if(n <= 0)
    return;

  for(int i = (n / 2) - 1; i >= 0; i--) {
    heapify(arr, i, n); // Build heap from array starting from internal nodes.
  }

  for(int i = n; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, 0, i - 1); // Extract max element from top and heapify it;
  }

}

int main() {

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  heapSort(arr, n - 1);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
