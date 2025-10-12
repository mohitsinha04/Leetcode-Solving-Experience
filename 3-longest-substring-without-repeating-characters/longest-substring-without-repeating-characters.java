class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int winstart = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            while (map.containsKey(s.charAt(i))) {
                map.remove(s.charAt(winstart));
                winstart++;
            }
            maxLen = Math.max(maxLen, i - winstart + 1);
            map.put(s.charAt(i), 1);
        }
        return maxLen;
    }
}