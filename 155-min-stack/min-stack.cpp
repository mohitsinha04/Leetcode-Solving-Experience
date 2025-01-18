class MinStack {
public:
    int min = INT_MAX;
    stack<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if (val <= min) {
            stack.push(min);
            min = val;
        }
        stack.push(val);
    }
    
    void pop() {
        int curr = stack.top();
        stack.pop();
        if (curr == min) {
            min = stack.top();
            stack.pop();
        }
        
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min;
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