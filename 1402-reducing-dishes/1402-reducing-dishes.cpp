class Solution {
public:
  
    int solve(vector<int>& satisfaction){
        int sum =0;
        int msum = 0;
        int mx = 0;
        for(int i=satisfaction.size()-1; i>=0; i--)
       {
            
                sum += satisfaction[i];
               if(msum<msum+sum){
                msum += sum;  
                }
            else{
                break;
                
          }
                
       }
        return msum;
        
         
}
    
    
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};