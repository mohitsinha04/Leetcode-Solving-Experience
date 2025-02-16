class MaxStack {
public:
    set<pair<int, int>> stack;
    set<pair<int, int>> values;
    int count;
    MaxStack() {
        count = 0;
    }
    
    // logn
    void push(int x) {
        stack.insert({count, x});
        values.insert({x, count});
        count++;
    }
    // o(1) + o(logn)
    int pop() {
        auto p = *stack.rbegin();
        stack.erase(p);
        values.erase({p.second, p.first});
        return p.second;
    }
    
    // o(1)
    int top() {
        return stack.rbegin()->second;
    }
    
    // o(1)
    int peekMax() {
        return values.rbegin()->first;
    }
    
    // o(1) + o(logn)
    int popMax() {
        auto p = *values.rbegin();
        values.erase(p);
        stack.erase({p.second, p.first});
        return p.first;
        
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */