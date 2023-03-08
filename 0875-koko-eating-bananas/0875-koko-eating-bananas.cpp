class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int m){
        long long neededHrs = 0;
        for(auto &p: piles){
           neededHrs += ceil((double)p/m); 
            if(neededHrs>h) return false;
        }
        return neededHrs<=h? true : false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana = 0;
        int totalBanana =0;
        
        for(auto &p:piles){
           maxBanana = max(maxBanana, p);
            totalBanana += p/h;
            
        }
        int l = totalBanana!=0? totalBanana:1;
        int r= maxBanana;
        while(l<r){
            int m = l + (r-l)/2;
            if(isPossible(piles, h, m)) 
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};