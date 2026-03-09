class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> map;
        int b = 0, c = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                b++;
            } else {
                map[secret[i]]++;
            }
        }
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && map[guess[i]]) {
                c++;
                map[guess[i]]--;
                if (map[guess[i]] == 0) map.erase(guess[i]);
            }
        }

        string res = to_string(b) + 'A' + to_string(c) + 'B';
        return res;
    }
};