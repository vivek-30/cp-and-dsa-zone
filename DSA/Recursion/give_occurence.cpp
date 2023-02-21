#include<iostream>
using namespace std;

void give_occurence(int arr[], int n, int target, pair<int, int> & pos) {
  
  if(n < 0)
    return;

  give_occurence(arr, n-1, target, pos);
  if(arr[n] == target) {
    if(pos.first != -1) {
      pos.second = n;
    }
    else {
      pos.first = pos.second = n;
    }
  }
}

int main() {

  pair<int, int> pos;
  pos.first = pos.second = -1;

  int n, target;
  cout<<"Enter array size\n";
  cin>>n;
  int arr[n];
  cout<<"Enter array elements\n";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  cout<<"Enter element to be searched\n";
  cin>>target;

  give_occurence(arr, n, target, pos);

  cout<<pos.first<<" "<<pos.second<<endl;

  return 0;
}