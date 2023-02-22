class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int maxLoad){
        int needDays = 1;
        int currLoad = 0;
        // cout<<maxLoad<<endl;
        for(int i=0; i<weights.size(); i++){
            if(currLoad+weights[i]>maxLoad){
                currLoad = 0;
                // cout<<needDays<<currLoad<<endl;
                needDays++;
            }
           currLoad += weights[i];    
        }
         // cout<<needDays<<endl;
        if(needDays<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 0;
        int maxWeight = 0;
        for(int i=0; i<weights.size(); i++){
           totalWeight += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }
        int l = maxWeight;
        int r = totalWeight;
        while(l<r){
            int mid = l + (r-l)/2;
            if(isPossible(weights, days, mid)){
                r = mid;
            }
            else{
               l = mid+1; 
            }
        }
        return l;
        
    }
};