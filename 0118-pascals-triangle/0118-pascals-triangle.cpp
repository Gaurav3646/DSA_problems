class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> vect(n);
             vect[0].push_back(1);
            for(int i=1; i<n; i++){
                vect[i].push_back(1);
                for(int j=0; j<vect[i-1].size()-1; j++){
                     vect[i].push_back(vect[i-1][j]+vect[i-1][j+1]);
                }
                 vect[i].push_back(1);
            }
        return vect;
            
    }
};