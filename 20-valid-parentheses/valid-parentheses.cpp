class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        for (int i = 0; i < s.size(); i++) {
            if(top > 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                if(s[i] == ')' && s[top-1] == '('){
                    top--;
                } else if(s[i] == ']' && s[top-1] == '['){
                    top--;
                } else if(s[i] == '}' && s[top-1] == '{'){
                    top--;
                } else {
                    return false;
                }
            } else {
                s[top] = s[i];
                top++;
            }
        }

        return top == 0;
    }
};