class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mapFreq = new HashMap<>();
        for (int i : nums) {
            int currFreq = mapFreq.getOrDefault(i, 0);
            mapFreq.put(i, currFreq + 1);
        }
        PriorityQueue<int[]> pq  = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int num : mapFreq.keySet()) {
            pq.add(new int[]{mapFreq.get(num), num});
            if (pq.size() > k) pq.poll();
        }
        int[] res = new int[k];
        int i = 0;
        while (!pq.isEmpty()) {
            res[i++] = pq.poll()[1]; 
        }
        return res;
    }
}