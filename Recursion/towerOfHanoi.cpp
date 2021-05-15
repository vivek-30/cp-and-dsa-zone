#include<iostream>
using namespace std;

void printHanoi(int rings, char source, char destination, char helper) {

  if(rings<=0)
    return;

  printHanoi(rings-1, source, helper, destination);
  cout<<"Move from "<<source<<" to "<<destination<<endl;
  printHanoi(rings-1, helper, destination, source);

}

int main() {

  int total_rings;
  cout<<"Enter total no of rings\n";
  cin>>total_rings;
  printHanoi(total_rings, 'L', 'R', 'M');

  return 0;
}
