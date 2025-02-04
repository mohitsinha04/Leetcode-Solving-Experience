class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = INT_MIN;
        for (int pile : piles) {
            right = max(pile, right);
        }
        int left = 1;
        while (left < right) {
            int mid = left + (right - left)/2;
            int currh = 0;

            for (int pile : piles) {
                currh += (pile/mid) + (pile % mid != 0);
            }
            if (currh <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};