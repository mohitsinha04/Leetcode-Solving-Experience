class Solution {
public:
// https://leetcode.com/problems/the-latest-time-to-catch-a-bus/solutions/2259708/c-100-faster-explanation-beginner-friendly-easy-unordered-set-o-n
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int cap) {
        int n1 = b.size() , n2 = p.size() , j=0 , ans;
        unordered_set<int> u;
        sort(b.begin() , b.end());
        sort(p.begin() , p.end());
        
        for(int i=0 ; i<n1 ; i++){
            int c = 0;
            while(c<cap && j<n2 && p[j]<=b[i]){
                if(u.find(p[j]-1)==u.end()) ans = p[j]-1; 
                u.insert(p[j]);
                c++;
                j++;
            }
            if(c<cap && u.find(b[i])==u.end()) ans = b[i];
        }
        return ans;
    }
};