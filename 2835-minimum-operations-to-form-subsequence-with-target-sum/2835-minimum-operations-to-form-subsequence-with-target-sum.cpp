
class Solution {
public:
    int minOperations(std::vector<int>& nums, int target) {
       vector<int> count(32, 0);
        int j = 32;
        int ans = 0;
        for(auto &n:nums){
            count[(int)log2(n)]++;
        }
        for(int i=0; i<31; i++){
            if(target&(1<<i)){
                  // cout<<count[i]<<endl;
                if(count[i]){
                    count[i]--;
                }
                else{
                  j = min(i, j);  
                    // cout<<j<<endl;
                }
            }
            
            if(count[i] && j<i){
                count[i]--;
                cout<<i-j<<endl;
                ans += i-j;
                j = 32;
            }
            count[i+1] += count[i]/2;
        }
        return  j<32 ? -1:ans;
    }
};


