class Solution {
    public int minMeetingRooms(int[][] intervals) {
        Map<Integer, Integer> line = new TreeMap<>();
        for (int[] interval : intervals) {
            int curr = line.getOrDefault(interval[0], 0);
            line.put(interval[0], curr + 1);

            curr = line.getOrDefault(interval[1], 0);
            line.put(interval[1], curr - 1);
        }

        int count = 0;
        int res = 0;

        for (Integer l : line.keySet()) {
            count += line.get(l);
            res = Math.max(count, res);
        }
        return res;
    }
}