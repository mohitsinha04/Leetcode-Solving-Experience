class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b){
            
            return a[1] < b[1];  
        };
        // [[10,16],[2,8],[1,6],[7,12]]
        // [[1,6],[2,8],[7,12],[10,16]]
        sort(points.begin(), points.end(), cmp);
        
        int prev = points[0][1];
        // prev = 6;
        int minArrows = 1;
        
        for (int i = 1; i < points.size(); i++) {
            // 7 < 10
            if (prev < points[i][0]) {
                minArrows++;
                prev = points[i][1];
            }
        }
        return minArrows;
    }
};