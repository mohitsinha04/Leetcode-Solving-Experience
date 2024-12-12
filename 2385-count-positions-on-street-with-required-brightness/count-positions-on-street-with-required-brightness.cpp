class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> line(n + 1, 0);
        
        for (auto l : lights) {
            line[max(0, l[0]-l[1])]++;
            line[min(n, l[1] + l[0] + 1)]--;
        }
        
        int count = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            count += line[i];
            if (count >= requirement[i]) res++;
        }
        
        return res;
    }
};