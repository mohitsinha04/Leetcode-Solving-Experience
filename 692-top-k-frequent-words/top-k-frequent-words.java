class PairFreq {
    String word;
    int freq;
    PairFreq() {
        word = "";
        freq = 0;
    }
    PairFreq(String word, int freq) {
        this.freq = freq;
        this.word = word;
    }
}
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String w : words) {
            int curr = map.getOrDefault(w, 0);
            map.put(w, curr + 1);
        }
        // PriorityQueue<PairFreq> pq = new PriorityQueue<>(Comparator.comparing(p -> p.freq));
        PriorityQueue<PairFreq> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a.freq != b.freq) {
                    return a.freq - b.freq;
                }
                return b.word.compareTo(a.word); // reverse lex order
            }
        );
        for (String s : map.keySet()) {
            pq.add(new PairFreq(s, map.get(s)));
            if (pq.size() > k) pq.poll();
        }

        LinkedList<String> res = new LinkedList<>();
        while (!pq.isEmpty()) {
            res.addFirst(pq.poll().word);
        }
        // Collections.reverse(res);
        return res;
    }
}