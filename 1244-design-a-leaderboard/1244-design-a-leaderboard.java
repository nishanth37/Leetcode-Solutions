// S.C.: O(N + K) where O(N) is used by scores HashMap and O(K) for the heap
class Leaderboard {
    private HashMap<Integer, Integer> scores;
    public Leaderboard() {
        scores = new HashMap<>();
    }

    // T.C.: O(1)
    public void addScore(int playerId, int score) {
        if (!scores.containsKey(playerId)) {
            scores.put(playerId, 0);
        }
        scores.put(playerId, scores.get(playerId) + score);
    }
    
    // T.C.: O(K) + O(NlogK). = O(NlogK). O(K) to contruct initial heap and then for the rest of the N−K elements, we perform the extractMin and add 
    // operations on the heap each of which take (logK) time.
    public int top(int K) {
        PriorityQueue<Map.Entry<Integer, Integer>> heap = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());

        for (Map.Entry<Integer, Integer> entry : scores.entrySet()) {
            heap.offer(entry);
            if (heap.size() > K) {
                heap.poll();
            }
        }
        int total = 0;
        while (!heap.isEmpty()) {
            total += heap.peek().getValue();
            heap.poll();
        }
        return total;
    }
    //T.C.: O(1)
    public void reset(int playerId) {
        scores.put(playerId, 0);
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */