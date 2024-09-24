class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 1;
        int pos = -1;
        for(int i = 0;i<target.size();i++){
            if(source.find(target[i])==-1)
                return -1;
            pos= source.find(target[i],pos+1);
            if(pos ==-1){
                count++;
                pos = source.find(target[i]);
            }
        }
        return count;
    }
};