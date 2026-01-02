class Solution {
    public int repeatedNTimes(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num: nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        for (int key: count.keySet()) {
            if (count.get(key) > 1)
                return key;
        }
        return 0;
    }
}