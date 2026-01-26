// T.C.: O(NlogN) - sort takes NlogN time - N = arr.length
// S.C.: O(logN) sort stack space is O(logN)
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int minDiff = Integer.MAX_VALUE;
        Arrays.sort(arr);
        for (int i = 0; i < arr.length-1; i++) {
            minDiff = Math.min(minDiff, Math.abs(arr[i+1] - arr[i]));
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < arr.length-1; i++) {
            if (minDiff == Math.abs(arr[i+1] - arr[i])) {
                res.add(Arrays.asList(arr[i], arr[i+1]));
            }
        }
        return res;
    }
}