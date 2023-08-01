class Solution {
public:
     vector<vector<int>> ans ;
    void solve(int n,  int &k, vector<int> &vect, int i=1){
        if(i>n){
           if(vect.size()==k) {
               ans.push_back(vect);
           } 
            return ;
        }
        vect.push_back(i);
        solve(n, k, vect , i+1);
        vect.pop_back();
        solve(n,  k, vect, i+1);
    }
    vector<vector<int>> combine(int n, int k) {
         vector<int> vect;
        solve(n, k, vect);
        return ans;
    }
};