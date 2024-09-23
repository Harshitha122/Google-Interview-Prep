class Solution {
public:
    int wateringPlants(vector<int>& p, int capacity) {
        int ans=0,c=capacity;
        for(int i=0;i<p.size();i++){
            if(c>=p[i])
                ans++;  // if you have enough water then water the plant and it will cost 1 step from previous plant.
            else{
                ans+=i; // if you don't have enough water then go back from previous plant and fill the container 
                ans+=i+1; // and come to the current plant.
                c=capacity;
            }
             c=c-p[i]; // water the plant and move to the next one.
        }
        return ans;
    }
};