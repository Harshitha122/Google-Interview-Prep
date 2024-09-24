class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> in(n+1,0);
        vector<int> res;
        vector<vector<int>> rev(n);
        queue<int> q;
        vector<int> safe(n+1,-1);
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                rev[x].push_back(i);
            }
            in[i]=graph[i].size();
            if(graph[i].size()==0){
                in[i]=0;
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=1;
            for(auto x:rev[node]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]==1){
                res.push_back(i);
            }
        }
        return res;
    }
};