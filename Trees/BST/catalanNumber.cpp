#include<iostream>
using namespace std;
 
int catlan(int n) {

  if(n <= 1) return 1;
  int result = 0;

  for(int i=0; i<n; i++) {
    result += catlan(i) * catlan(n - 1 - i);
  }
  return result;
}
 
int main() {
  
  int n, result = 0, j;
  cout<<"Enter a number"<<endl;
  cin>>n;
  
  for(int i=0; i<n; i++)
    cout<<catlan(i)<<" ";

  cout<<endl;
  
  return 0;
}
  