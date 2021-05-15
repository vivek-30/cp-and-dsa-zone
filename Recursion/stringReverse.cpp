#include<iostream>
using namespace std;

void reverse_string(string& str, int start, int end) {

  if(start >= end || start <0 || end <=0) 
    return;

  char temp = str[start];
  str[start] = str[end];
  str[end] = temp;
  reverse_string(str, start+1, end-1);
}

int main() {
  string str;
  cout<<"Enter the string to be reversed: ";
  getline(cin, str);
  reverse_string(str, 0, str.length()-1);
  cout<<"Reversed String is: "<<str<<"\n";
  return 0;
}
