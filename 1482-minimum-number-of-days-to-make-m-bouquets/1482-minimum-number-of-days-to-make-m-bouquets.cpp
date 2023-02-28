class Solution {
public:
    bool isPoss(vector<int>& bloomDay,int m, int &k, int &mid){
        int i = 0;
        for(auto &d:bloomDay){
            if(mid>=d){
                i++;
            }
            else{
                i=0;
            }
            if(i==k){
                m--;
                i=0;
            }
        }
        return m<=0?true:false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(bloomDay.size()<m*k) return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto & day : bloomDay){
             maxi = max(maxi, day);
            mini = min(mini, day);
        }
        int l = mini;
        int r = maxi;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isPoss(bloomDay, m, k, mid)){
                r= mid;
            }
            else{
                l = mid+1;
            }
        }
        return isPoss(bloomDay, m, k, l)?l:-1;
    }
};