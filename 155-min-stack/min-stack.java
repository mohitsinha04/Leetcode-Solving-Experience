class MinStack {
    Stack<Integer> stk;
    Stack<Integer> minStk;
    public MinStack() {
        stk = new Stack<>();
        minStk = new Stack<>();
        
    }
    
    public void push(int val) {
        stk.add(val);
        int minimumTillNow = val;
        if (!minStk.isEmpty()) {
            minimumTillNow = Math.min(val, minStk.peek());
        }
        minStk.add(minimumTillNow);
    }
    
    public void pop() {
        if (stk.isEmpty()) return;
        stk.pop();
        minStk.pop();
        
    }
    
    public int top() {
        if (!stk.empty()) return stk.peek();
        return -1;
    }
    
    public int getMin() {
        if (!stk.empty()) return minStk.peek();
        return -1;
        
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */