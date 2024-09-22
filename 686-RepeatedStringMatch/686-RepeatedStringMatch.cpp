class Solution {
    public int repeatedStringMatch(String A, String B) {
        
        for (int i = 0; i < A.length(); i++) {
            if (A.charAt(i) == B.charAt(0)) {
                int count = 1;
                int j = 0;
                int startIx = i;
                while (j < B.length() && A.charAt(startIx) == B.charAt(j)) {
                    j++;
                    startIx++;
                    if (startIx >= A.length() && j < B.length()) {
                        startIx = startIx % A.length();
                        count++;
                    }
                }
                if (j == B.length()) return count;
            }
        }
        return -1;
    }
}```