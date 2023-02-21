#include<iostream>
using namespace std;

void print_permutation(string str, int current) {

  if(!str.length())
    return;

  if(current == str.length()) {
    cout<<str<<endl;
    return;
  }

  for(int i=current; i<str.length(); i++) {
    swap(str[i], str[current]);
    print_permutation(str, current+1);
    swap(str[i], str[current]);
  }

}

int main() {

  string str;
  cout<<"Enter a string\n";
  cin>>str;

  cout<<"Permutations are:\n";
  print_permutation(str, 0);

  return 0;
}
