#include <climits>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    int minimum = INT_MAX;
    MinStack() {}
    
    void push(int val) {
        st.push(val); 
    }
    
    void pop() {
        st.pop(); 
    }
    
    int top() {
        return st.top(); 
    }
    
    int getMin() {
        stack<int> tmp;
        int minimum = st.top();

        while(st.size()){
            minimum = min(minimum, st.top());
            tmp.push(st.top());
            st.pop();
        }

        while(tmp.size()){
            st.push(tmp.top());
            tmp.pop();
        }

        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
