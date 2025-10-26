class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();

        for (int[] p : prerequisites) {
            int first = p[0];
            int sec = p[1];
            indegree[first]++;
            graph.computeIfAbsent(sec, k -> new ArrayList<>()).add(first);
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.offer(i);
        }

        ArrayList<Integer> res = new ArrayList<>();
        while (!q.isEmpty()) {
            int curr = q.poll();

            res.add(curr);
            for (int course : graph.getOrDefault(curr, new ArrayList<>())) {
                indegree[course]--;
                if (indegree[course] == 0) q.offer(course);
            }
        }

        if (res.size() != numCourses) return new int[0];
        int[] results = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            results[i] = res.get(i);
        }
        return results;
    }
}