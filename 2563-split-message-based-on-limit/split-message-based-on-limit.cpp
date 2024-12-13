class Solution {
public:
//     https://www.youtube.com/watch?v=KB-ReEdu7_Y
    vector<string> splitMessage(string message, int limit) {
        for (int digit = 1; digit < 5; digit++) {
            vector<string> res = helper(message, limit, digit);
            if (res.empty()) continue;
            return res;
        }
        return {};
    }
    vector<string> helper(string message, int limit, int digit) {
        int part = 1, ind = 0;
        vector<string> res;
        
        string placeholder = "";
        for (int i = 0; i < digit; i++) placeholder += "-";
        
        while (ind < message.size()) {
            string suffix = "<" + to_string(part) + "/" + placeholder + ">";
            part++;
            
            string curr_string = "";
            int char_left = limit - suffix.size();
            if (char_left <= 0) return {};
            
            while (ind < message.size() && char_left > 0) {
                curr_string += message[ind];
                ind++;
                char_left--;
            }
            res.push_back(curr_string);
        }
        if (to_string(res.size()).size() != digit) return {};
        
        part = 1;
        for (string& s : res) {
            string suffix = "<" + to_string(part) + "/" + to_string(res.size()) + ">";
            s += suffix;
            part++;
        }
        return res;
        
    }
};