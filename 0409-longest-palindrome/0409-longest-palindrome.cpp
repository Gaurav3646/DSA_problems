class Solution {
public:
   
    int longestPalindrome(string s) {
       map<int, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int ans = 0;
        int f = false;
        for(auto &it: mp){
           if(it.second%2==0){
               ans += it.second;
           }
            else{
                if(f==false){
                    ans += 1;
                    f = true;
                }
                ans += it.second-1;
            }
        }
        return ans;
    }
};