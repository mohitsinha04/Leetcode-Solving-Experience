class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];

        int left = 1;
        int right = nums.size() - 2;

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            else if (mid % 2 == 0 && nums[mid] == nums[mid + 1] || 
            (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return -1;
    }
};

// 0, 1] 2, 3], 4, 5] 6, 7]

// 1, 1, 2, 3, 3, 4, 4, 8, 8
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9


// mid = 8 + 0 / 2 = 4 = even? : if even, then curr == curr + 1 ? left = mid + 1 : right = mid - 1;
//                               if odd, then curr == curr - 1 ? left = mid + 1 : right = mid - 1 