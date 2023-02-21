#include<iostream>
using namespace std;
 
int selectActivity(int start[], int end[], int n) {
  
  if(n <= 0) return 0;

  int ans = 1; // first activity always get selected.
  int prev = 0;

  for(int curr = 1; curr < n; curr++) {
    if(start[curr] >= end[prev]) {
      ans++;
      prev = curr;
    }
  }

  return ans;
}
 
int main() {
  
  int n;
  int start[] = {1, 3, 0, 5, 8, 5};
  int end[] = {2, 4, 6, 7, 9, 9}; // note if finish time is not given in sorted order we have to sort them (ascending order as to select activity that consumes less time) according to their finsh time using a class or structure of start and end time.

  n = sizeof(start)/sizeof(start[0]);
  
  cout<<selectActivity(start, end, n)<<endl;
  
  return 0;
}
  