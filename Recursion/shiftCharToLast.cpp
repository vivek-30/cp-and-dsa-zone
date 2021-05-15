#include<iostream>
using namespace std;

string shiftCharToLast(string str, char k) {
  if(!str.length())
    return "";

  char current = str[0];
  string result = shiftCharToLast(str.substr(1), k);
  if(current == k)
    return result + current;
  else 
    return current + result;

}

int main() {

  string str;
  char k;
  cout<<"Enter a string\n";
  getline(cin, str);
  cout<<"Enter the character you would like to shift to end\n";
  cin>>k;

  str = shiftCharToLast(str, k);
  cout<<"Modified String is: "<<str<<"\n";

  return 0;
}
