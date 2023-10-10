class Solution {
public:
    bool isPalindrome(string &str, int i, int j){
        // int i = 0;
        // int j = str.length() - 1;
        while(i <= j){
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }

//     int solve(int ind, string s){
//         if(ind >= s.length()){
//            return  0;
//         }
//            int ans = INT_MAX;
//         for(int i=1;ind + i <= s.length();i++){
//             if(isPalindrome(s.substr(ind, i))){
//               ans = min(ans, solve(ind+i, s));
//             }
//         }
//         return ans+1;    }
    
    

    int minCut(string s) {
       // return solve(0, s)-1;
        vector<int> dp(s.length()+1, 0);
        for(int ind =s.length()-1; ind>=0; ind--){
            int ans = INT_MAX;
            for(int i=1;ind + i <= s.length();i++){
                if(isPalindrome(s, ind, ind+i-1)){
                  ans = min(ans, dp[ind+i]);
                }
            }
         dp[ind] = ans+1; 
            
        }
        return dp[0]-1;
    }
};