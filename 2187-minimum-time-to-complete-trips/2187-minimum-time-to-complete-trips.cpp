class Solution {
public:
    bool isPossible(vector<int> &time, int &tt, long long &m){
        long long trips = 0;
         
         for(auto &x:time){
            trips += m/x;
        }
        if(trips>=tt){
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int &totalTrips) {
        long long mini = INT_MAX;
        for(auto &x:time){
            long long y = x;
            mini = min(mini, y);
        }
        
        long long e = totalTrips*mini;
        long long s = 1;
        while(s<e){
            long long m  = s + (e-s)/2;
            if(isPossible(time, totalTrips, m)){
                 e = m; 
                cout<<e<<endl;
               
            }
            else{
                s = m+1;
            }
        }
        return s;
    }
};