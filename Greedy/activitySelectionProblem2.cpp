// When finish time is not sorted
#include<iostream>
using namespace std;
 
class Activity {
  public:
    int start, end;

    Activity() {
      start = end = 0;
    }

    Activity(int _start, int _end) {
      start = _start;
      end = _end;
    }
};

bool compare(Activity a, Activity b) {
  return a.end <= b.end;
}

int selectActivity(Activity arr[], int n) {
  
  if(n <= 0) return 0;

  sort(arr, arr + n, compare);

  int ans = 1; // first activity always get selected.
  int prev = 0;

  for(int curr = 1; curr < n; curr++) {
    if(arr[curr].start >= arr[prev].end) {
      ans++;
      prev = curr;
    }
  }

  return ans;
}
 
int main() {
  
  int n, start, end;
  cout<<"Enter total activities\n";
  cin>>n;

  Activity arr[n];

  for(int i=0; i<n; i++) {
    cout<<"Enter start and end time of activity "<<i+1<<endl;
    cin>>start>>end;
    arr[i].start = start;
    arr[i].end = end;
  }
  
  cout<<selectActivity(arr, n)<<endl;
  
  return 0;
}
  