#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
  
    void shiftElementsToHelper() {
      while(!st.empty()) {
        helper.push(st.top());
        st.pop();
      }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(helper.empty() and st.empty())
          return -1;
        
        int value;
      
        if(!helper.empty()) {
          value = helper.top();
          helper.pop();
        } else {
          shiftElementsToHelper();
          value = helper.top();
          helper.pop();
        }
      return value;
    }
    
    /** Get the front element. */
    int peek() {
        if(helper.empty() and st.empty())
          return -1;
        
        if(!helper.empty()) 
          return helper.top();
        else {
          shiftElementsToHelper();
          return helper.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       if(helper.empty() and st.empty())
         return true;
        
        return false;
    }
};
