class Solution {
public:
    int findMin(vector<int>& nums) {
        // If the list has just one element then return that element.
        if (nums.size() == 1) {
            return nums[0];
        }

        // Initializing left and right pointers.
        int left = 0, right = nums.size() - 1;

        // If the last element is greater than the first element then there is
        // no rotation. E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array. Hence
        // the smallest element is first element. A[0]
        if (nums[right] > nums[0]) {
            return nums[0];
        }

        // Binary search way
        while (right >= left) {
            // Find the mid element
            int mid = left + (right - left) / 2;

            // If the mid element is greater than its next element then mid+1
            // element is the smallest This point would be the point of change.
            // From higher to lower value.
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // If the mid element is lesser than its previous element then mid
            // element is the smallest
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // If the mid elements value is greater than the 0th element this
            // means the least value is still somewhere to the right as we are
            // still dealing with elements greater than nums[0]
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                // If nums[0] is greater than the mid value then this means the
                // smallest value is somewhere to the left
                right = mid - 1;
            }
        }

        return -1;
    }
};