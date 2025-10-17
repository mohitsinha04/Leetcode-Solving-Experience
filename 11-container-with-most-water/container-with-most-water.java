class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        int left = 0, right = height.length - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                int area = (right - left) * height[left];
                res = Math.max(res, area);
                left++;
            } else {
                int area = (right - left) * height[right];
                res = Math.max(res, area);
                right--;
            }
        }
        return res;
    }
}