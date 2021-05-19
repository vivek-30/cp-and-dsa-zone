#include<iostream>
using namespace std;

int freq[256];

char find_max_occured_char(string str, int& max) {
  
  int len = str.length(), pos = -1, digit;
  if(!len)
    return -1;

  char element;

  for(int i=0; i<len; i++) {
    digit = str[i];
    freq[digit]++;

    if(freq[digit] > max) {
      max = freq[digit];
      pos = digit;
    }
  }

  element = pos;

  return element;
}

int main() {

  string str;
  int total = 0;
  cout<<"Enter a string\n";
  getline(cin, str);
  for(int i=0; i<256; i++)
    freq[i] = 0;
  
  char element = find_max_occured_char(str, total);
  cout<<"Max occurence character is: "<<element<<" with total occurence "<<total<<endl;

  return 0;
}
