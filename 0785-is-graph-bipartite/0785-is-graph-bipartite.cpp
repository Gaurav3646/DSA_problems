class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,vector<int>&vis,int k)
    {
        vis[i]=k;
        for(auto it:graph[i])
        {
            if(vis[it]==-1)
            {
                if(dfs(graph,it,vis,-k)==false) return false;
            }
            else
            {
                if(vis[i]==vis[it])return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
               if(dfs(graph,i,vis,2)==false)return false;
            }
        }
       
        return true;
        
    }
};