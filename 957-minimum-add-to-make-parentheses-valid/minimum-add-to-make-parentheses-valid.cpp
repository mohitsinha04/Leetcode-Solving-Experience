class Solution {
public:
    int minAddToMakeValid(string s) {
        int invalidOpen = 0, invalidClose = 0;
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (open <= 0) invalidOpen++;
                else open--;
            }
        }

        int close = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                close++;
            } else {
                if (close <= 0) invalidClose++;
                else close--;
            }
        }
        return invalidOpen + invalidClose;
    }
};