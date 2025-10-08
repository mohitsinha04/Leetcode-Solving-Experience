class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    int parseExpr(string& s, int& i) {
        //this vector is working like stack here!
        vector<int> nums;
        char op = '+';
        for (; i < s.length() && op != ')'; i++) {
            if (s[i] == ' ') continue;
            long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
            switch(op) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                case '*' : nums.back() *= n; break;
                case '/' : nums.back() /= n; break;
            }            
            if (i < s.length())                 
                op = s[i];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
    
    long parseNum(string& s, int& i) {           
        long n = 0;
        while(i < s.length() && isdigit(s[i]))
            n = s[i++] - '0' + 10 * n;
        return n;
    }
};