class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges(points.size(),vector<int>(points.size()));
        for(int i = 0;i<points.size();i++){
            for(int j = 0; j<points.size();j++){
                int x = abs(points[i][0]-points[j][0]);
                int y = abs(points[i][1]-points[j][1]);
                edges[i][j] = x+y;
            }
        }
        // for(auto x:edges){
        //     for(int y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> visited(points.size(),0); // visted nodes
        pq.push({edges[0][0],0}); // push the first node/index to the priority queue
        int ans = 0;
        // do until the priority queue is empty
        while(!pq.empty()){
            // if the top one is already visited i dont need to recompute its sub nodes
            while(!pq.empty() && visited[pq.top().second]==1){
                pq.pop();
            }
            // if all the priorit queue is empty then break;
            if(pq.empty()) break;
            pair<int,int> top = pq.top();
            ans+=top.first; // calculate the operation for this node
            for(int i = 0 ; i<edges.size();i++){
                if(visited[i]==0 && i!=top.second){
                    pq.push({edges[top.second][i],i});
                }
            }
            visited[top.second] = 1;
        }
        return ans;
    }
};