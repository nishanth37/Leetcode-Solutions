class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int res = 0;
        for(String opt : operations) {
            if(opt.equals("--X") || opt.equals("X--")) res--;
            else res++;
        }
        return res;
    }
}