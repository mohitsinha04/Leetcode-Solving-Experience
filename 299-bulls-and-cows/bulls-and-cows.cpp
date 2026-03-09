class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> map;
        int b = 0, c = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                b++;
            } else {
                if (map[secret[i]] < 0) {
                    c++;
                }
                if (map[guess[i]] > 0) {
                    c++;
                }
                map[secret[i]]++;
                map[guess[i]]--;
            }
        }

        string res = to_string(b) + 'A' + to_string(c) + 'B';
        return res;
    }
};

// 1123

// 0111

// map[1]++ = 1 < 0 ? no 
// map[1]-- = 0 > 0 