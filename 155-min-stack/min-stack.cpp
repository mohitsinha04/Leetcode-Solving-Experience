class MinStack {
public:

    std::stack<int> stack;
    std::stack<pair<int, int>> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val < minStack.top().first) minStack.push({val, 1});

        else if (minStack.top().first == val) {
            minStack.top().second++;
        }
    }
    
    void pop() {
        int curr = stack.top();
        stack.pop();

        if (minStack.top().first == curr) {
            if (minStack.top().second > 1) minStack.top().second--;
            else minStack.pop();
        }
    }
    
    int top() {
        return stack.top();
        
    }
    
    int getMin() {
        return minStack.top().first;
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