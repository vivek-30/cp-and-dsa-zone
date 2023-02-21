#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> m;
 
void countFreq(int arr[], int n) {
  if(n <= 0) return;

  for(int i=0;i<n;i++)
    m[arr[i]]++;
}

int freq(int num) {
  return m[num];
}
 
int main() {
  
  int arr[] = {2,4,5,6,1,3,3,32,3,4,3,3,2,9,0};
  countFreq(arr, sizeof(arr)/sizeof(arr[0]));
  cout<<"freq of 2 = "<<freq(2)<<endl;
  cout<<"freq of 1 = "<<freq(1)<<endl;
  cout<<"freq of 0 = "<<freq(0)<<endl;
  cout<<"freq of 7 = "<<freq(7)<<endl;
  cout<<"freq of 3 = "<<freq(3)<<endl;
  
  return 0;
}
  