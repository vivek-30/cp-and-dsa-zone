#include<iostream>
using namespace std;

string remove_duplicates(string str) {

  if(!str.length())
    return "";

  char current = str[0];
  string result = remove_duplicates(str.substr(1));
  if(current == result[0])
    return result;
  else
    return (current + result);
}

int main() {

  string str;
  cout<<"Enter a string containing duplicate characters.\n";
  getline(cin, str);
  str = remove_duplicates(str);
  cout<<"Unique String is: "<<str<<endl;

  return 0;
}
