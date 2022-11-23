class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> vect;
             vector<int> nVect;
             nVect.push_back(1);
             vect.push_back(nVect);
           if(n==0) return vect[0]; 
         
             nVect.push_back(1);
             vect.push_back(nVect); 
           if(n==1) return vect[1];
         
        for(int i=2; i<=n; i++){
            vector<int> v;
            v.push_back(1);
           for(int j=1; j<i; j++){
               v.push_back(vect[i-1][j]+vect[i-1][j-1]);
            }
            v.push_back(1);
            vect.push_back(v);
        }
        return vect[n];
    }
};