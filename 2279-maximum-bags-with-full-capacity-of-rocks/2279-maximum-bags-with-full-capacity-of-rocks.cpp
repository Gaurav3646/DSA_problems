class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addRock) {      
        vector<int> cpr;
        for(int i=0; i<rocks.size(); i++){
          cpr.push_back(capacity[i]-rocks[i]);
        }
        sort(cpr.begin(), cpr.end());
        int i = 0;
        while(i<rocks.size() && cpr[i]<=addRock){
            addRock -= cpr[i];
              i++;
        }
        return i;
        
    }
};