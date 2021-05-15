#include<iostream>
using namespace std;

void replacePI(string& str, int current) {

  int len = str.length()-1;

  if(len <= 0 || current == len)
    return;

  if(str[current] == 'p' and str[current+1] == 'i') {
    str.erase(current, 2); // Removes 2 chr. starting from postion == current
    str.insert(current, "3.14"); // Insert given string at position == current
  }

  replacePI(str, current+1);
}

int main() {

  string str;
  cout<<"Enter a string containing pi : "<<endl;
  getline(cin, str);
  replacePI(str, 0);
  cout<<"Replaced String is: "<<str<<endl;

  return 0;
}