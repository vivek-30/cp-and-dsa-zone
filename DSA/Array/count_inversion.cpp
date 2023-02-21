#include<iostream>
using namespace std;

int countInversion(int arr[], int start, int mid, int end) {

  int i = start, j = mid + 1, inversions = 0, size = end - start + 1, k = 0;
  int temp[size];
  while(i <= mid and j <= end) {
    if(arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else {
      inversions += (mid - i + 1); // Remaning elements of left array + current element
      temp[k++] = arr[j++];
    }
  }

  while(i <= mid)
    temp[k++] = arr[i++];

  while(j <= end)
    temp[k++] = arr[j++];

  for(int i=0; i<size; i++)
    arr[start++] = temp[i];

  return inversions;
}
 
int divideArray(int arr[], int start, int end) {
  
  if(start >= end)
    return 0;
  
  int mid = (start + end) / 2;
  int inversions = 0;

  inversions += divideArray(arr, start, mid);

  inversions += divideArray(arr, mid + 1, end);
  
  inversions += countInversion(arr, start, mid, end);

  return inversions;
}
 
int main() {
  
  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements\n";

  for(int i=0; i<n; i++)
    cin>>arr[i];
  
  cout<<"Total Inversions are: "<<divideArray(arr, 0, n - 1)<<endl;

  return 0;
}
  