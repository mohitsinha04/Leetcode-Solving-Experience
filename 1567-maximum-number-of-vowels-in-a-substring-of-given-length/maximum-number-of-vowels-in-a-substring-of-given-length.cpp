class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> hash;
        hash.insert('a');
        hash.insert('e');
        hash.insert('i');
        hash.insert('o');
        hash.insert('u');
        int winstart = 0, max_len = 0, curr_len = 0;
        for(int winend = 0; winend < s.size(); winend++) {
            if(hash.count(s[winend])) {
                curr_len++;
            }
            if(winend - winstart + 1 == k) {
                max_len = max(curr_len, max_len);
                if(hash.count(s[winstart]))
                    curr_len--;
                winstart++;
            }
            //if(winend - winstart + 1 >= k) {
                
            //}
        }
        return max_len;
    }
};