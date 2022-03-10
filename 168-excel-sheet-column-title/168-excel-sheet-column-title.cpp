class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int rem = 0;
        while(columnNumber > 0) {
            columnNumber--;
            rem = columnNumber%26;
            res = (char)(rem + 'A') + res;
            columnNumber /= 26;
        }
        return res;
    }
};