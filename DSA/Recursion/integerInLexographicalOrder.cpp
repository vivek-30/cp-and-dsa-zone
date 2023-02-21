#include<iostream>
using namespace std;

void getLexographicalOrder(int num, int end) {

  if(num > end)
    return;
  
  if(num == end) {
    cout<<num<<endl;
    return;
  }

  if(num != 0)
    cout<<num<<endl;

  int start = num != 0 ? 0 : 1;

  for(int i = start; i <= 9; i++)
    getLexographicalOrder(((num * 10) + i), end);

}

int main() {

  int n;
  cout<<"Enter a number\n";
  cin>>n;

  cout<<"Output:\n";
  getLexographicalOrder(0, n);

  return 0;
}