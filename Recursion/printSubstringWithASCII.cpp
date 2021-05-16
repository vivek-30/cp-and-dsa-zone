#include<iostream>
using namespace std;

void print_substrings_with_ascii(string str, string substr) {
  
  if(!str.length()) {
    cout<<substr<<endl;
    return;
  }

  char current = str[0];
  int ascii = (int)current;
  print_substrings_with_ascii(str.substr(1), substr);
  print_substrings_with_ascii(str.substr(1), (substr + current));
  print_substrings_with_ascii(str.substr(1), (substr + to_string(ascii)));
  
}

int main() {

  string str;
  cout<<"Enter a string\n";
  getline(cin, str);
  print_substrings_with_ascii(str, "");
  cout<<endl;

  return 0;
}
