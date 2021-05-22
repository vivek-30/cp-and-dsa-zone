#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {

  int size = end - start + 1, i = start, j = mid + 1, k = 0;
  int temp[size];

  while(i <= mid and j <= end)
    if(arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else temp[k++] = arr[j++];

  if(i > mid)
    while(j <= end)
      temp[k++] = arr[j++];
  else
    while(i <= mid)
      temp[k++] = arr[i++];

  for(i = 0; i < size; i++)
    arr[start++] = temp[i];
}

void mergeSort(int arr[], int start, int end) {

  if(start >= end)
    return;

  int mid = (start + end) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);

  merge(arr, start, mid, end);
}

int main() {

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  mergeSort(arr, 0, n - 1);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
