#include<iostream>
using namespace std;

void countSort(int arr[], int n) {

  if(n <= 0)
    return;

  int range = 0;
  for(int i = 0; i < n; i++)
    if(arr[i] > range)
      range = arr[i];

  int freq[range + 1], result[n];

  memset(freq, 0, sizeof(freq));

  for(int i = 0; i < n; i++)
    freq[arr[i]]++;

  for(int i = 1; i < range + 1; i++)
    freq[i] += freq[i - 1];

  for(int i = n - 1; i >= 0; i--) {
    result[freq[arr[i]] - 1] = arr[i];
    freq[arr[i]]--;
  }

  for(int i = 0; i < n; i++)
    arr[i] = result[i];
}

int main() {

  int n;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];

  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  countSort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
