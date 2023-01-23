class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
//         vector<unordered_set<int>> trusts(n+1);
//         for(int i=0; i<trust.size(); i++){
//             int u = trust[i][0];
//             int v = trust[i][1];
//           trusts[v].insert(u);
//         }
//       int judge = -1;
//         for(int i=1; i<=n; i++){
//             if(trusts[i].size()==n-1){
//                 int jd = true;
//                 for(int j=1; j<=n; j++){
//                     if(i!=j && trusts[j].count(i)){
//                         jd = false;
//                     }
//                 }
//                  if(jd) judge = i;  
//             }
           
        
//         }
//         return  judge;
        
        vector<int> inDegree(n+1);
        vector<int> outDegree(n+1);
        for(int i=0; i<trust.size(); i++){
            inDegree[trust[i][1]]++;
            outDegree[trust[i][0]]++;
            
        }
        for(int i=1; i<=n; i++){
            if(inDegree[i]==n-1 && outDegree[i]==0) return i;
        }
        return -1;
       
    }
};