class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> vis = new HashSet<>();
        for (int i : nums) {
            vis.add(i);
        }
        int res = 0;
        for (int i : vis) {
            if (!vis.contains(i-1)) {
                int curr = i;
                int count = 0;
                while (vis.contains(curr)) {
                    count++;
                    curr = curr + 1;
                }
                res = Math.max(res, count);
            }
        }
        return res;

    }
}