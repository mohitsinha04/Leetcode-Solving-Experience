class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpressionstack(s, i);
    }
    int parseExpression(string& s, int& i) {
        //this vector is working like stack here!
        vector<int> nums;
        char op = '+';
        while (i < s.size() && op != ')') {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            long n = s[i] == '(' ? parseExpression(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                // case '*' : nums.back() *= n; break;
                // case '/' : nums.back() /= n; break;
            }            
            if (i < s.length())                 
                op = s[i];
            i++;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }

    int parseExpressionstack(string& s, int& i) {
        //this vector is working like stack here!
        stack<int> nums;
        char op = '+';
        while (i < s.size() && op != ')') {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            long n = s[i] == '(' ? parseExpression(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+' : nums.push(n); break;
                case '-' : nums.push(-n); break;
                // case '*' : nums.back() *= n; break;
                // case '/' : nums.back() /= n; break;
            }            
            if (i < s.length())                 
                op = s[i];
            i++;
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
        // return accumulate(nums.begin(), nums.end(), 0);
    }
    
    long parseNum(string& s, int& i) {           
        long n = 0;
        while(i < s.length() && isdigit(s[i]))
            n = s[i++] - '0' + 10 * n;
        return n;
    }
};