class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]); 
    }
    void unionn(int u, int v){
        u= findPar(u);
        v= findPar(v);
   
        if(rank[u]<rank[v]) 
            parent[u]=v; 
        else if(rank[v]<rank[u])
            parent[v]=u;  
        else {
            parent[v]=u;
            rank[v]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()< n-1) return -1; 
        for(int i=0;i<n;i++)
            parent.push_back(i), rank.push_back(0);
        
        for(auto &it: conn)
            unionn(it[0], it[1]);

        int differentComponents= 0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) differentComponents++;

        return differentComponents-1;
    }
};