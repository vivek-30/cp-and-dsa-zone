#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {

  if(n <= 0)
    return;

  int temp, i, j;

  for(i = 0; i < n - 1; i++) {
    
    temp = arr[i + 1];
    
    for(j = i + 1; j > 0; j--) {
      if(temp <= arr[j - 1])
        arr[j] = arr[j - 1];  
      else break;
    }
    arr[j] = temp; 
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

  insertionSort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
