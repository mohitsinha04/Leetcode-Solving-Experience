class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;

        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left)/2;
            int midElem = matrix[mid / n][mid % n];
            if (target == midElem) return true;
            else if (target < midElem) {
                right = mid - 1;
            } else left = mid + 1;
        }
        return false;
    }
};