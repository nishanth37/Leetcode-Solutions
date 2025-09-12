class Solution {
    public int largestUniqueNumber(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();

        for(int num: nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        int maxUnique = -1;

        for(int num : count.keySet()) {
            if (count.get(num) == 1) {
                maxUnique = Math.max(num, maxUnique);
            }
        }
        return maxUnique;
    }
}