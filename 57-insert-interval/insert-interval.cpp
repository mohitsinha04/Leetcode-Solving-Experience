	class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> m;
        for(auto& p : intervals){
            ++m[p[0]];
            --m[p[1]];
        }
        ++m[newInterval[0]];
        --m[newInterval[1]];
        int count = 0;
        vector<vector<int>> ans;
        int start;
        for(auto& i : m){
            if(count==0){
                start = i.first;
            }
            count += i.second;
            if(count == 0){
                ans.push_back({start, i.first});
            }
        }
        return ans;
    }
};