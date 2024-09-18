class Solution {
    public void reverseWords(char[] s) {
        // reverse entire chars
        // reverse individual ones
        reverse(0, s.length - 1, s); // reverse entire chars from 0 to s.length - 1
        
        // reverse each word
        int left = 0;
        int right = left;
        while (left < s.length && right < s.length) {
            while (left < s.length && s[left] == ' ') left++;
            right = left;
            while (right < s.length && s[right] != ' ') right++;
            reverse(left, right - 1, s);
            left = right;
        }
    }
    
    private void reverse(int i, int j, char[] s) {
        while (i <= j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
}