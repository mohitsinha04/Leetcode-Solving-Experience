class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited(deadends.begin(), deadends.end());
        //visited.insert("0000");
        
        queue<string> q;
        q.push("0000");
        int ans = -1;
        
        while(!q.empty()){
            ans += 1;
            auto size = q.size();
            for(auto i = 0; i < size; ++i){
                string s = q.front();
                q.pop();
                if(s == target)
                    return ans;
                if(visited.count(s))
                    continue;
                visited.insert(s);
                findnext(s, q);
            }
        }
        return -1;
    }
    void findnext(string s, queue<string>& q){
        for(int i = 0; i < 4; ++i){
            char c = s[i];
            s[i] = (c-'0'+1) % 10 + '0';
            q.push(s);
            s[i] = (c-'0'-1 + 10) % 10 + '0';
            q.push(s);
            s[i] = c;
        }
    }
};