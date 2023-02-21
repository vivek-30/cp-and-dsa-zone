#include<iostream>
using namespace std;
 
int findTrappedWater(int heights[], int n) {

  if(n <= 2)
    return 0;

  int max = heights[0], result = 0;
  int leftMax[n], rightMax[n];

  // Find Biggest Building In Left for Each Building.
  for(int i=0; i<n; i++) {
    if(heights[i] > max)
      max = heights[i]; 
    leftMax[i] = max;
  }

  max = heights[n-1];
  // Find Biggest Building In Right for Each Building.
  for(int i=n-1; i>=0; i--) {
    if(heights[i] > max)
      max = heights[i];
    rightMax[i] = max;
  }

  // Find Trapped Water For Each Building.
  for(int i=0; i<n; i++) {
    result += min(leftMax[i], rightMax[i]) - heights[i];
  }

  return result;
}
 
int main() {
  
  int n;
  cout<<"Enter total buildings"<<endl;
  cin>>n;
  int heights[n];
  cout<<"Enter Building Heights\n";
  for(int i=0; i<n; i++)
    cin>>heights[i];

  cout<<"Trapped Water is : "<<findTrappedWater(heights, n)<<endl;
  
  return 0;
}
  