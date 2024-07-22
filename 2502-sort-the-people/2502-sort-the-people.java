// N = length of heights Arrays
// T.C.: O(NlogN) - for sorting the heights array. 
// S.C.: O(N) - for hashmap
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        String[] result = new String[n];
        HashMap<Integer, String> map = new HashMap<>();
        for(int i = 0; i < n; i++) {
            map.put(heights[i], names[i]);
        }
        Arrays.sort(heights);

        for(int i = n-1; i >= 0; i--) {
            result[n-i-1] = map.get(heights[i]);
        }

        return result;
    }
}