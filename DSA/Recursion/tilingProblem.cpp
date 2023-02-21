#include<iostream>
using namespace std;

int getTotalWays(int n) {

  if(n <= 0)
    return 0;

  if(n == 1)
    return 1;

  int w1 = getTotalWays(n - 1); // Place Tile Vertically.
  int w2 = getTotalWays(n - 2); // Place Tile Horizontally.

  return (w1 + w2);
}

int main() {

  int n;
  cout<<"Enter total columns\n";
  cin>>n;

  cout<<"Total Ways are :\n"<<getTotalWays(n)<<endl;

  return 0;
}