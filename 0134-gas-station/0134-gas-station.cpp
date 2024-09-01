class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int loss=0;
        int profit=0;
        int res=0;
        for(int i=0;i<gas.size();i++){
            profit+=gas[i]-cost[i];
            
            if(profit<0){
                res=i+1;
                loss+=profit;
                profit=0;
            }
        }
        return (profit+loss)>=0 ? res :-1;
    }
};