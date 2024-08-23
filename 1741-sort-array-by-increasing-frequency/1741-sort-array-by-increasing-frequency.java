// T.C.: O(NlogN) N = length of input || Sorting takes NlogN T.C.
// S.C.: O(N) N = length of hash map to count the frequencies of each element
class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for(int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        // Java's Arrays.sort method doesn't directly support
        // sorting primitive arrays (int[]) with a lambda comparator.
        // We can convert the primitive int into Integer objects
        // to get around this limitation.
        Integer[] numsObj = new Integer[nums.length];
        for(int i = 0; i < nums.length; i++) {
            numsObj[i] = nums[i];
        }

        Arrays.sort(numsObj, (a, b) -> {
            if (count.get(a).equals(count.get(b))) {
                return Integer.compare(b, a);
            }
            return Integer.compare(count.get(a), count.get(b));
        });

        // Convert numsObj back to a primitive array to match return type.
        for (int i = 0; i < nums.length; i++) {
            nums[i] = numsObj[i];
        }
        return nums;
    }
}