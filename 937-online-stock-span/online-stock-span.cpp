class StockSpanner {
public:
    stack<pair<int, int>> stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!stack.empty() && stack.top().first <= price) {
            res += stack.top().second;
            stack.pop();
        }
        stack.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */