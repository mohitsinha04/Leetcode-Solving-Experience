class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        string operators = "+-*/";
        for (string token : tokens) {
            if (operators.find(token) == string::npos) {
                stack.push(stoi(token));
                continue;
            }
            int number2 = stack.top();
            stack.pop();
            int number1 = stack.top();
            stack.pop();
            int result = 0;
            if (token == "+") {
                result = number1 + number2;
            } else if (token == "-") {
                result = number1 - number2;
            } else if (token == "*") {
                result = number1 * number2;
            } else if (token == "/") {
                result = number1 / number2;
            }
            stack.push(result);
        }
        return stack.top();
    }
};