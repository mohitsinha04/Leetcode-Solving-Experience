class Solution {
public:
    int myAtoi(string str) {
        stringstream ss(str);
        str = "";
        ss >> str;
        int i = 0;
        int sign = 1;
        if(str[i] == '-' || str[i] == '+') {
            sign = (str[i++] == '-')? -1 : 1;
        }
        long long int res = 0;
        while('0'<= str[i] && str[i] <= '9') {
            res = res*10 + (str[i++]-'0');
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN;
        }
        return res * sign;
    }
};