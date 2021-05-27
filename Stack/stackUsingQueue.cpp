#include<iostream>
#include<queue>
using namespace std;

// Pop operation is coslty - O(N) and Push is constant O(1)
class MyStack {
public:
  
    queue<int> q;
    queue<int> helper;
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()) return -1;
      
        while(q.size() > 1) {
          helper.push(q.front());
          q.pop();
        }
      
        int value = q.front();
        q.pop();
      
        if(!helper.empty()) {
          q.swap(helper);
        }
      return value;
    }
    
    /** Get the top element. */
    int top() {
       if(empty())
         return -1;
      
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty())
          return true;
      
        return false;
    }
};

// Push operation is coslty - O(N) and Pop is constant O(1)
class MyStack {
public:
  
    queue<int> q;
    queue<int> helper;
    
    /** Push element x onto stack. */
    void push(int x) {
      helper.push(x);
      while(!q.empty()) {
        helper.push(q.front());
        q.pop();
      }
      
      helper.swap(q);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()) return -1;
      
        int value = q.front();
        q.pop();
        return value;
    }
    
    /** Get the top element. */
    int top() {
       if(empty())
         return -1;
      
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty())
          return true;
      
        return false;
    }
};
