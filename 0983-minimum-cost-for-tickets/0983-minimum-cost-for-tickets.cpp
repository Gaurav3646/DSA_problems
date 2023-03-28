class Solution {
public: 
    // int move(vector<int>& days, int i,int j){
              
//             int daymove;
//      if(j==0){
//          daymove = 1;
//      }
//     else if(j==1){
//         daymove = 7;
//     }
//     else{
//         daymove = 30;
//     }
        
//              int a = days[i] + daymove-1;
//             while(days[i]<=a){
//                 i++;
//                if(i==days.size()){
//                    return i;
//                }
//             } 
//     return i;
// }
//         int solve(vector<int>& days, vector<int>& costs, int i,  vector<int> &dp){
//             if(i>=days.size()){
//                 return 0;
//             }
//             if(dp[i]!=-1){
//                 return dp[i];
//             }
//             int mn = INT_MAX;
//             int j = move(days,i,0);
//              mn = min(mn,costs[0] + solve(days, costs, j, dp));
//             int k = move(days,i,1);
//              mn = min(mn,costs[1] + solve(days, costs, k, dp));
//             int l = move(days,i,2);
//              mn = min(mn, costs[2] + solve(days, costs, l, dp));
//             dp[i] = mn;
//             return dp[i];
            
        // }
    // int solveTab(vector<int>& days, vector<int>& costs){
    //     vector<int> dp(days.size()+1, INT_MAX);
    //     dp[days.size()]=0;
    //     for(int i=days.size()-1; i>=0; i--){
    //          int mn = INT_MAX;
    //         int j = move(days,i,0);
    //         if()
    //          mn = min(mn,costs[0] + dp[j]);
    //         int k = move(days,i,1);
    //          mn = min(mn,costs[1] + dp[k]);
    //         int l = move(days,i,2);
    //          mn = min(mn, costs[2] + dp[l]);
    //         dp[i] = mn;
    //     }
    //     return dp[0];
    // }
  int solveOp(vector<int>& days, vector<int>& costs){
      
      queue<pair<int,int>> month;
      queue<pair<int,int>> week;
      int ans = 0;
      for(int &day: days){
             while(!month.empty()&&month.front().first+30<=day){
                 month.pop();
             }
          while(!week.empty()&&week.front().first+7<=day){
                 week.pop();
             }
         month.push({day,ans+costs[2]});
          week.push({day, ans+costs[1]});
          ans = min(ans+costs[0],min(month.front().second, week.front().second));
          
      }
      return ans;
  }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(), -1);
        // return solve(days, costs, 0, dp);
        // return solveTab(days, costs);
        return solveOp(days, costs);
    }
};