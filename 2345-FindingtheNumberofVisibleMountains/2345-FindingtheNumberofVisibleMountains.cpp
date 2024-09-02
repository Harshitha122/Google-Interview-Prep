// Reference https://leetcode.com/problems/finding-the-number-of-visible-mountains/solutions/2335616/java-one-pass-no-extra-space/?orderBy=most_votes

class Solution {
    public:

    int visibleMountains(vector<vector<int>> peaks){
        for(int i = 0; i < peaks.size(); i ++){
            int temp = peaks[i][0];
            peaks[i][0] -= peaks[i][1];
            peaks[i][1] += temp;
        }
        sort(peaks.begin(), peaks.end());
        int size = 0;
        int i = 0;
        while(i < peaks.size()){
            size++;
            if(i == peaks.size() - 1){
                return size;
            } 
            int currEnd = peaks[i][1];
            // if start is same as of next mountain then current mountain is for sure to be overwhelmed.
            if(peaks[i][0] == peaks[i + 1][0]){
                size--;
            }
            // skip over overwhelmed mountains by current mountain
            while(i + 1 != peaks.size() && currEnd >= peaks[i + 1][1]) {
                i++;
            }
            i++; // move to next unvisited mountain
        }
        return size;
    }
};