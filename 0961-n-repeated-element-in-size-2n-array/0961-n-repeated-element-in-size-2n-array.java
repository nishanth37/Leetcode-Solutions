// T.C. - O(N) - N - size of nums
// S.C.: - O(N) - N - size of count hashmap
class Solution {
    public int repeatedNTimes(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num: nums) {
            if (count.containsKey(num))
                return num;
            else
                count.put(num, 1);
        }
        return 0;
    }
}