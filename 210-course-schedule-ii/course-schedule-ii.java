class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();

        for (int[] prerequisite : prerequisites) {
            int first = prerequisite[0];
            int sec = prerequisite[1];
            indegree[first]++;
            graph.computeIfAbsent(sec, k -> new ArrayList<>()).add(first);
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) q.offer(i);
        }

        ArrayList<Integer> res = new ArrayList<>();

        while (!q.isEmpty()) {
            int curr = q.poll();
            res.add(curr);

            for (int next : graph.getOrDefault(curr, new ArrayList<>())) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        int[] intArray = new int[res.size()];

        // 3. Loop and copy (unboxing occurs automatically)
        for (int i = 0; i < res.size(); i++) {
            // Automatic unboxing converts Integer to int
            intArray[i] = res.get(i); 
        }
        if (res.size() != numCourses) {
            return new int[0];
        }   
        return intArray;

    }
}