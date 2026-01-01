// T.C.: O(1) for all operations
// S.C.: O(n + n) = O(n) - size of both stacks
class MinStack {
    Stack<Integer> st;
    Stack<Integer> minSt;
    Integer minVal;
    public MinStack() {
        st = new Stack<>();
        minSt = new Stack<>();
        minSt.push(Integer.MAX_VALUE);
        minVal = Integer.MAX_VALUE;
    }
    
    public void push(int val) {
        st.push(val);
        minVal = Math.min(minVal, val);
        minSt.push(minVal);
    }
    
    public void pop() {
        st.pop();
        minSt.pop();
        minVal = minSt.peek();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minVal;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */