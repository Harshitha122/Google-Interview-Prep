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
            if(peaks[i][0] == peaks[i + 1][0]){
                size--;
            }
            while(i + 1 != peaks.size() && currEnd >= peaks[i + 1][1]) {
                i++;
            }
            i++; 
        }
        return size;
    }
};