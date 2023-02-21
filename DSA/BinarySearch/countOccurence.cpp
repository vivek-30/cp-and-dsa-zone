#include<bits/stdc++.h>
using namespace std;

#define mid(l, r) (l + (r - l) / 2)

int findOccurence(vector<int> &arr, int val, string choice) {
  int start = 0, end = arr.size() - 1, mid = 0, index = -1;

  while(start <= end) {

    mid = mid(start, end);

    if(arr[mid] == val) {
      index = mid;
      if(choice == "first")
        end = mid - 1;
      else start = mid + 1;
    }
    else if(arr[mid] > val) 
      end = mid - 1;
    else start = mid + 1;
  }

  return index;
}

int countOccurence(vector<int> &arr, int val) {
  
  int total = 0, first = -1, last = -1;

  first = findOccurence(arr, val, "first");
  last = findOccurence(arr, val, "last");

  if(first != -1 and last != -1)
    total = last - first + 1;

  return total;
}

int main() {
  vector<int> v {2,4,4,4,6,7,7,7,8,8,8,8,8,9,12};
  cout<<countOccurence(v, 2)<<endl;
  cout<<countOccurence(v, 8)<<endl;
  cout<<countOccurence(v, 7)<<endl;

  return 0;
}
