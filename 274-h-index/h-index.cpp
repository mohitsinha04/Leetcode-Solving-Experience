class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> h(size+ 1, 0);
        for (auto c : citations) {
            if (c >= size) h[size]++;
            else h[c]++;
        }
        int count = 0; 
        for (int i = size; i >= 0; i--) {
            count += h[i];
            if (count >= i) return i;
        }
        return 0;
    }
};