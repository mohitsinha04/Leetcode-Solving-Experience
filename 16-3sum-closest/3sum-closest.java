class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        if (nums.length < 3) return 0;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length && res != 0; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(target - sum) < Math.abs(res)) {
                    res = target - sum;
                }
                if (sum < target) left++;
                else right--;
            }
        }
        return target - res;
    }
}