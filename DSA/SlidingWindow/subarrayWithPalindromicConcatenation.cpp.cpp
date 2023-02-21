#include<iostream>
using namespace std;

bool checkPalindrome(string str) {
  int i = 0, j = str.length() - 1;
  while(i <= j)
    if(str[i++] != str[j--])
      return false;

  return true;
}

int countDigit(int num) {
  int count = 0;
  while(num) {
    count++;
    num /= 10;
  }
  return count;
}

string formPalindrome(int arr[], int n, int k) {

  int i = 0, digit;

  if(k > n or k < 0 or n < 0) return "";

  string str = "";

  for(; i<k; i++)
    str += to_string(arr[i]);

  if(checkPalindrome(str)) return str;

  for(; i<n; i++) {
    
    digit = countDigit(arr[i-k]);
    str = str.substr(digit);
    str += to_string(arr[i]);

    if(checkPalindrome(str)) return str;
  }

  return "";
}
 
int main() {
  
  int arr[] = {1, 5, 3, 2, 3, 5, 4};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout<<formPalindrome(arr, n, 5)<<endl;
  
  return 0;
}
  