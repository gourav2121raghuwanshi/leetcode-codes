class Solution {
    public long[] findMaxSum(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        long[] ans = new long[n];

        TreeMap<Integer, List<Integer>> indexMap = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            indexMap.computeIfAbsent(nums1[i], v -> new ArrayList<>()).add(i);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0;

        for (Map.Entry<Integer, List<Integer>> entry : indexMap.entrySet()) {
            List<Integer> indices = entry.getValue();

            for (int idx : indices) {
                ans[idx] = sum;
            }

            for (int idx : indices) {
                pq.add(nums2[idx]);
                sum += nums2[idx];

                if (pq.size() > k) {
                    sum -= pq.poll();
                }
            }
        }

        return ans;
    }
}