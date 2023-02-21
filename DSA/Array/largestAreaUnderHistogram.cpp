#include<iostream>
#include<stack>
using namespace std;
 
// O(N) Time + O(N) Space.
int findMaxHistogramArea1(int heights[], int n) {

  if(n <= 0)
    return 0;

  if(n == 1)
    return heights[0];

  stack<int> s;

  int area = 0, width = 1;
  int leftMin[n], rightMin[n];

  // Find Smallest Block In Left for Each Block And Store Their Index.
  for(int i=0; i<n; i++) {
    while(!s.empty() and heights[s.top()] >= heights[i]) // Pops bigger and same value than current value.
      s.pop();

    if(s.empty())
      leftMin[i] = -1;  // Min is -1 in left. (i.e., Invalid index)
    else leftMin[i] = s.top();  
    
    s.push(i); // push current value at end.
  }

  while(!s.empty()) // Important to clear stack Before using it again.
    s.pop();
    
  // Find Smallest Block In Right for Each Block And Store Their Index.
  for(int i=n-1; i>=0; i--) {
    while(!s.empty() and heights[s.top()] >= heights[i])
      s.pop();

    if(s.empty())
      rightMin[i] = n;  // Min in right is n in right. (i.e., Invalid index).
    else rightMin[i] = s.top();  
    
    s.push(i); // push current value at end.
  }

  // Find Max Area Of Largest Histogram Rectangle.
  for(int i=0; i<n; i++) {
    width = rightMin[i] - leftMin[i] - 1;
    if(width * heights[i] > area)
      area = width * heights[i];
  }

  return area;
}
 
// O(N * N) Time + O(1) Space.
int findMaxHistogramArea2(int heights[], int n) {

  if(n <= 0)
    return 0;

  if(n == 1)
    return heights[0];

  int area = 0, i = 0, j = 0;
  for(i = 0; i < n; i++) {
    j = i;
    while(j < n and heights[i] <= heights[j]) {
      j++;
    }
    area = max(area, (j - i) * heights[i]); // j - i are the number of blocks i.e., total width
  }

  return area;
}

int main() {
  
  int n;
  cout<<"Enter total blocks"<<endl;
  cin>>n;
  int heights[n];
  cout<<"Enter Blocks Heights\n";
  for(int i=0; i<n; i++)
    cin>>heights[i];

  cout<<"Max Area is : "<<findMaxHistogramArea1(heights, n)<<endl;
  
  return 0;
}
  