#include<iostream>
using namespace std;

int find_record_breaking_days(int arr[], int n) {

  if(n == 0 or n == 1)
    return n;

  int total_days = 0, max = arr[0];
  if(arr[0] > arr[1])
    total_days++;
    
  for(int i=1; i<n-1; i++) {

    if(arr[i] > max && arr[i] > arr[i+1]) {
      total_days++;
    }

    if(arr[i] > max)
      max = arr[i];
  }

  return total_days;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t = 1, curr = 1;

  cin>>t;
  while(t--) {
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
      cin>>arr[i];

    int total_days = find_record_breaking_days(arr, n);
    cout<<"#"<<curr++<<": "<<total_days<<endl;
  }
  return 0;
}
