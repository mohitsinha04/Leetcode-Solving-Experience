class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if (s.size() == 1) return false;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else {
                if (stk.empty()) return false;
                char curr = stk.top();
                stk.pop();
                if ((curr == '(' && c != ')') ||
                (curr == '{' && c != '}') || (curr == '[' && c != ']')) {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};