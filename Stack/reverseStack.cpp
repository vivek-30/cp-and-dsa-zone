#include<iostream>
#include<stack>
using namespace std;

void reverseElements(stack<int>& s, int data) {

  if(s.empty()) {
    s.push(data);
    return;
  }

  int Top = s.top();
  s.pop();

  reverseElements(s, data);
  s.push(Top);
}
 
void reverseStack(stack<int>& s) {

  if(s.empty())
   return;

  int Top = s.top();
  s.pop();
  reverseStack(s);
  reverseElements(s, Top);
}
 
int main() {

  int n, item;
  stack<int> s;
  cout<<"Enter stack size"<<endl;
  cin>>n;

  cout<<"Enter stack elements\n";
  for(int i=0; i<n; i++) {
    cin>>item;
    s.push(item);
  }
  
  reverseStack(s);
  cout<<"Reversed Stack Is: ";
  while(!s.empty()) {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;

  return 0;
}
  