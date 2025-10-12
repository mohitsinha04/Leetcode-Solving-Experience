class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Character, Integer> map = new HashMap<>();
        int maxLen = 0, winstart = 0;
        int maxFreq = 0;

        for (int winend = 0; winend < s.length(); winend++) {
            int currFreq = map.getOrDefault(s.charAt(winend), 0);
            map.put(s.charAt(winend), currFreq + 1);

            maxFreq = Math.max(maxFreq, currFreq + 1);

            if (winend - winstart + 1 - maxFreq > k) {
                int currFreqStart = map.getOrDefault(s.charAt(winstart), 0);
                map.put(s.charAt(winstart), currFreqStart - 1);
                winstart = winstart + 1;
            }
            maxLen = Math.max(maxLen, winend - winstart + 1);
        }
        return maxLen;
    }
}