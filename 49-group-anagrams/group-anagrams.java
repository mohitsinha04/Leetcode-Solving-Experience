class Solution {
    
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] charArray = s.toCharArray();
            int[] charMap = new int[26];
            for (char c : charArray) {
                charMap[c - 'a'] += 1;
            }
            String curr = Arrays.toString(charMap);
            map.computeIfAbsent(curr, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(map.values());
    }
}