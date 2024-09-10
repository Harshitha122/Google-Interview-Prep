    vector<bool>vis(n, false);

    long long int time=0;
    queue<int>q;
    q.push(headID);
    vis[headID]=true;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int u=q.front();
            q.pop();
            time+=informTime[u];

            int subTime=0;
            for(auto v: adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    subTime=max(subTime, informTime[v]);
                }
            }
            time+=subTime;
        }
    }
    return time;

}