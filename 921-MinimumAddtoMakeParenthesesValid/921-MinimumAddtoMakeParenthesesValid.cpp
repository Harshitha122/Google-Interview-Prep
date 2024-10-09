class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftBalance = 0, rightBalance = 0;

    for (char c : s) {
        if (c == '(') {
            leftBalance++;
        } else if (c == ')') {
            if (leftBalance > 0) {
                leftBalance--;
            } else {
                rightBalance++;
            }
        }
    }

    return leftBalance + rightBalance;
    }
};