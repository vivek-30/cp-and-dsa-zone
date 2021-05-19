#include<iostream>
using namespace std;

int givePossibleWays(int start, int end) {

  if(start == end)
    return 1;

  if(start > end)
    return 0;

  return (givePossibleWays(start + 1, end) + givePossibleWays(start + 2, end)
  + givePossibleWays(start + 3, end) + givePossibleWays(start + 4, end)
  + givePossibleWays(start + 5, end) + givePossibleWays(start + 6, end));

}

int main() {
  
  int start, end;
  cout<<"Enter starting and ending point\n";
  cin>>start>>end;

  cout<<"Total Possible ways are: "<<givePossibleWays(start, end)<<endl;
  return 0;
}