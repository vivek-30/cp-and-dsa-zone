#include<iostream>
using namespace std;

void print_substrings(string str, string substr) {
  
  if(!str.length()) {
    cout<<substr<<endl;
    return;
  }

  char current = str[0];
  print_substrings(str.substr(1), substr);
  print_substrings(str.substr(1), (substr+current));
  
}

int main() {

  string str;
  cout<<"Enter a string\n";
  getline(cin, str);
  print_substrings(str, "");
  cout<<endl;

  return 0;
}
