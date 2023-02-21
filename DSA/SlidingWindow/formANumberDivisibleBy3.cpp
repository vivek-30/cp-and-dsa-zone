#include<iostream>
using namespace std;

int countDigit(int num) {
  int count = 0;
  while(num) {
    count++;
    num /= 10;
  }
  return count;
}

// O(N) // onother approach can be check the sum of k elments are divisible by 3 or not as the sum of all digits of a number must also be divisible by its divisor. (Note => This is only true for number 3)
int formNumber(int arr[], int n, int k, int x) { // k = window size, x = number

  int i = 0, iNum, digit;

  if(k > n or k < 0) return -1;

  string sNum = "";

  for(; i<k; i++)
    sNum += to_string(arr[i]);

  iNum = stoi(sNum);
  if(iNum % x == 0) return iNum;

  for(; i<n; i++) {
    digit = countDigit(arr[i-k]);
    sNum = sNum.substr(digit);
    sNum += to_string(arr[i]);

    iNum = stoi(sNum);
    if(iNum % x == 0) return iNum;
  }

  return -1;
}
 
int main() {
  
  int arr[] = {84, 23, 45, 12, 56, 82};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<formNumber(arr, n, 3, 3)<<endl;
  
  return 0;
}
  