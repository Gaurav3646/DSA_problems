class Solution {
public:
   int dfs(int n, int k, int root){
       if(n==1) return root;
       int leafs = pow(2, n-1);
       if(k<=leafs/2){
           return dfs(n-1, k, root==1?1:0);
       }
       else{
            return dfs(n-1, k-leafs/2, root==0?1:0);
       }
       return -1;
   }
    int kthGrammar(int n, int k) {
      return dfs(n, k, 0);
    }
};