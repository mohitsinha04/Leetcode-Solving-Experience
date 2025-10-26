class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
    int parseExpr(string& s, int& i) {
        //this vector is working like stack here!
        vector<int> nums;
        char operation = '+';
        while (i < s.size() && operation != ')') {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            // check bracket and number

            long n = parseNum(s, i);
            switch(operation) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                case '*' : nums.back() *= n; break;
                case '/' : nums.back() /= n; break;
            }            
            if (i < s.length())                 
                operation = s[i];
            i++;
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