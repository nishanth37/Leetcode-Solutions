// T.C.: O(n + mlogm) n - length of apple, m - length of capacity
// O(n) for iterating apple array, O(mlogm) for sorting capacity
// S.C.: O(1) or O(m)
// If the sort is in place, the space complexity is O(1). Otherwise, it is O(m)
class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int totalApples = 0;
        int count = 0;
        for (int i : apple) {
            totalApples += i;
        }
        Arrays.sort(capacity);
        int i = capacity.length-1;
        while (totalApples > 0) {
            totalApples -= capacity[i];
            i--;
            count++;
        }
        return count;
    }
}