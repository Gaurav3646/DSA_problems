class Solution {
public:
    
    double champagneTower(int p, int qr, int qg) {
           double ans[102][102]={0};
          ans[0][0] = p;
          for(int i=0; i<=qr; i++){
             for(int j=0; j<=i; j++){
                 double q = (ans[i][j]-1.0)/2.0;
                 if(q>0){
                     ans[i+1][j] += q;
                     ans[i+1][j+1] += q;
                 }
             }
          } 
        return min(1.0, ans[qr][qg]);
    }
};