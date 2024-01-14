// LeetCode 225

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int> q1 , q2 ;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x) ;

        while( !q1.empty() )
        {
            q2.push( q1.front() );
            q1.pop() ;
        }

        while( !q2.empty() )
        {
            q1.push( q2.front() ) ;
            q2.pop() ;
        }
    }
    
    int pop() {
        int pop = q1.front() ;
        q1.pop() ;
        return pop ;
    }
    
    int top() {
        int peek = q1.front() ;
        return peek ;
    }
    
    bool empty() {
        return q1.empty() && q2.empty() ;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    return 0;
}