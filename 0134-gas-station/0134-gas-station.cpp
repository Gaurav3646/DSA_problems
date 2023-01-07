class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int yes=0;
      
        
        int sum = 0;
        int j=0;
        int sumback=0;
        for(int i=0; i<gas.size(); i++){
          sum += (gas[i]-cost[i]);
            if(sum<0){
               
                sum = 0;
               j = i+1; 
            }
          yes +=  (gas[i]-cost[i]);
}
        if(yes<0){
            return -1;
        }
   return j;
    }
};