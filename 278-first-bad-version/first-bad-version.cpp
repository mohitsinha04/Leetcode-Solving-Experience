class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;        // mid is a candidate, keep it in range
            } else {
                left = mid + 1;     // mid is good, skip it
            }
        }
        return left;  // or right — they are equal
    }
};