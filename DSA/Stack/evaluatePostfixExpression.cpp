#include<iostream>
#include<stack>
using namespace std;

int performOperation(char op, int opd1, int opd2) {
  if(op == '+') return opd1 + opd2;
  else if(op == '-') return opd1 - opd2;
  else if(op == '*') return opd1 * opd2;
  else if(op == '/') return opd1 / opd2;
  else return opd1 ^ opd2;
}
 
int evaluatePostfix(string str) {

  if(str.length() == 0) return INT_MAX;

  int opd1, opd2; // int is more convieninet than char 
  stack<int> s;

  for(char c: str) {
    if(c == '+' or c == '-' or c == '*' or c == '/' or c == '^') {
      opd2 = s.top();
      s.pop();
      opd1 = s.top();
      s.pop();

      s.push(performOperation(c, opd1, opd2));
    }
    else s.push(c - '0');
  }

  if(not s.empty())
    return s.top();
  
  return INT_MAX; 
}
 
int main() {
  
  string str;
  cout<<"Enter Postfix Expression\n";
  cin>>str;

  cout<<"Ans = "<<evaluatePostfix(str)<<endl;
  
  return 0;
}
  