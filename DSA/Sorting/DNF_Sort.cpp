#include<iostream>
using namespace std;

void DNF_Sort(int arr[], int n) {

  if(n <= 0)
    return;

  int start = 0, mid = 0, end = n - 1, value;

  while(mid <= end) {
    value = arr[mid];
    if(value == 0)
      swap(arr[start++], arr[mid++]);
    else if(value == 2)
      swap(arr[mid], arr[end--]);
    else mid++;
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

  DNF_Sort(arr, n);
  cout<<"Sorted Array Is: \n";

  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;

  return 0;
}
