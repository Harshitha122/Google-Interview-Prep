public class Solution {
    public int minGroups(int[][] intervals) {
        // Sort the intervals by start time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // Priority queue (min-heap) to track the earliest end times
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Process each interval
        for (int[] interval : intervals) {
            // If the current interval's start is after or equal to the smallest end time, we can merge
            if (!pq.isEmpty() && pq.peek() < interval[0]) {
                pq.poll(); // Remove the group that ends earliest
            }
            // Add the current interval's end time to the heap
            pq.offer(interval[1]);
        }

        // The number of elements in the priority queue is the number of groups needed
        return pq.size();
    }
}