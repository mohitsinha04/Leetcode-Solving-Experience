class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;
        int[] res = new int[m];

        if (n == 0) {
            throw new IllegalArgumentException("servers array must contain at least one server");
        }

        // free servers: sorted by weight, then by index
        PriorityQueue<int[]> free = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // busy servers: sorted by freeTime, then by index
        // each element: {freeTime, serverIndex}
        PriorityQueue<long[]> busy = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Long.compare(a[0], b[0]);
            return Long.compare(a[1], b[1]);
        });

        // initialize free servers
        for (int i = 0; i < n; i++) {
            free.offer(new int[]{servers[i], i});
        }

        long currentTime = 0;
        for (int i = 0; i < m; i++) {
            // tasks arrive at time = i
            currentTime = Math.max(currentTime, i);

            // release any busy servers that have completed by currentTime
            while (!busy.isEmpty() && busy.peek()[0] <= currentTime) {
                long[] top = busy.poll();
                if (top == null) break; // defensive, though condition ensures non-null
                int serverId = (int) top[1];
                free.offer(new int[]{servers[serverId], serverId});
            }

            // if no free servers, advance time to the next free server completion
            if (free.isEmpty()) {
                if (busy.isEmpty()) {
                    throw new IllegalStateException("No servers available to assign task");
                }
                long[] top = busy.poll();
                if (top == null) {
                    throw new IllegalStateException("Unexpected null when polling busy servers");
                }
                currentTime = top[0];
                int serverId = (int) top[1];
                free.offer(new int[]{servers[serverId], serverId});

                // also release any other servers that finished at this new currentTime
                while (!busy.isEmpty() && busy.peek()[0] <= currentTime) {
                    long[] t = busy.poll();
                    if (t == null) break;
                    int sid = (int) t[1];
                    free.offer(new int[]{servers[sid], sid});
                }
            }

            // assign the smallest-weight free server to this task
            int[] serv = free.poll();
            if (serv == null) {
                throw new IllegalStateException("Expected a free server but found none");
            }
            int serverId = serv[1];
            res[i] = serverId;

            long finishTime = currentTime + (long) tasks[i];
            busy.offer(new long[]{finishTime, serverId});
        }

        return res;
    }
}