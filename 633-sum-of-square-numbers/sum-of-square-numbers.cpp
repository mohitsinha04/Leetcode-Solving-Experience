class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int) a * a;
            if (binarySearch(0, b, b)) return true;
        }
        return false;
    }
    bool binarySearch(long start, long end, int target) {
        if (start > end) return false;
        long mid = start + (end - start) / 2;

        if (mid * mid == target) return true;
        if (mid * mid > target) return binarySearch(start, mid - 1, target);
        return binarySearch (mid + 1, end, target);
    }
};