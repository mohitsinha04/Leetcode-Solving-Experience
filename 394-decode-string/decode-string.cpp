class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string curr = "";
                while (st.top() != '[') {
                    curr = st.top() + curr;
                    st.pop();
                }

                st.pop();
                string number = "";

                while (!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }
                int n = stoi(number);
                while (n--) {
                    for (int p = 0; p < curr.size(); p++) {
                        st.push(curr[p]);
                    }
                }
            }
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};