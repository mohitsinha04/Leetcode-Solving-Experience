class Solution {
    // nums[i] + nums[j] = -nums[k];

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 3) return res;

        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, res);
            }
        }

        return res;
    }

    void twoSum(int[] nums, int i, List<List<Integer>> res) {
        int left = i + 1, right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                List<Integer> curr = Arrays.asList(nums[left], nums[right], nums[i]);
                res.add(curr);
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }

        }
    }
}