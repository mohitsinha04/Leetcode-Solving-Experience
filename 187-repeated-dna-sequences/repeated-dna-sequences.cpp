class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> hash;
        unordered_set<string> resu;
        vector<string> res;
        if(s.size() < 10) return res;
        for(int i = 0; i < s.size() - 10 + 1; i++) {
            string curr = s.substr(i, 10);
            if(hash.count(curr))
                resu.insert(curr);
            hash.insert(curr);
        }
        for(auto i : resu)
            res.push_back(i);
        return res;
    }
};