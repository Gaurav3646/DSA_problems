class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int w = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adjList[i].push_back({j, w});
                adjList[j].push_back({i, w});
            }
        }
        vector<int> minArray(n, INT_MAX);
        vector<bool> mst(n, false);
        minArray[0]= 0;
         int miniIndex;
        int  minDistance=0;
        do{
        int mini = INT_MAX;
         miniIndex = -1;
        for(int i=0; i<n; i++){
            if(minArray[i]<mini&&mst[i]==false){
                mini = minArray[i];
                miniIndex = i;
            }
        }
        if(miniIndex!=-1){
          mst[miniIndex] = true;
             minDistance +=  minArray[miniIndex];
        for(int i=0; i<adjList[miniIndex].size(); i++){
            if(minArray[adjList[miniIndex][i].first]>adjList[miniIndex][i].second&&mst[adjList[miniIndex][i].first]==false){
                minArray[adjList[miniIndex][i].first] = adjList[miniIndex][i].second;
            }
          }
        }     
     } while(miniIndex!=-1);
    
        return minDistance;
    }
};