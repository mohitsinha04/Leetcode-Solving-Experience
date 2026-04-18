class Solution {
    // public int[] assignTasks(int[] servers, int[] tasks) {
        
    // }
    /**
     * Assign tasks to servers.
     *
     * @param servers array of server weights where servers[i] is weight of server i
     * @param tasks array of task processing times where tasks[t] arrives at second t
     * @return array result where result[i] is the index of server assigned to task i
     */
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;
        int[] result = new int[m];

        // Free servers: ordered by (weight, index)
        PriorityQueue<int[]> free = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // Busy servers: ordered by (freeTime, weight, index)
        // Each entry: long freeTime stored in int[] as (int) may overflow, so store as long wrapper via Busy class
        PriorityQueue<Busy> busy = new PriorityQueue<>((a, b) -> {
            if (a.freeTime != b.freeTime) return Long.compare(a.freeTime, b.freeTime);
            if (a.weight != b.weight) return Integer.compare(a.weight, b.weight);
            return Integer.compare(a.index, b.index);
        });

        // Initialize free servers
        for (int i = 0; i < n; ++i) {
            free.offer(new int[]{servers[i], i});
        }

        long currTime = 0;
        for (int i = 0; i < m; ++i) {
            currTime = Math.max(currTime, i); // task i arrives at time i

            // Free up any servers that have completed by currTime
            while (!busy.isEmpty() && busy.peek().freeTime <= currTime) {
                Busy b = busy.poll();
                free.offer(new int[]{b.weight, b.index});
            }

            // If no free servers, fast-forward time to the next server free time
            if (free.isEmpty()) {
                Busy next = busy.poll();
                currTime = next.freeTime;
                // move this and any other servers free at this time back to free
                free.offer(new int[]{next.weight, next.index});
                while (!busy.isEmpty() && busy.peek().freeTime <= currTime) {
                    Busy b = busy.poll();
                    free.offer(new int[]{b.weight, b.index});
                }
            }

            // Assign the task to the best free server
            int[] server = free.poll();
            int weight = server[0];
            int idx = server[1];
            result[i] = idx;
            long finishTime = currTime + (long) tasks[i];
            busy.offer(new Busy(finishTime, weight, idx));
        }

        return result;
    }

    private static class Busy {
        long freeTime;
        int weight;
        int index;

        Busy(long freeTime, int weight, int index) {
            this.freeTime = freeTime;
            this.weight = weight;
            this.index = index;
        }
    }
}