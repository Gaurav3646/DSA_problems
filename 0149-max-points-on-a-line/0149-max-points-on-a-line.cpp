class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      // sort(points.begin(), points.end());
        int maxi = 1;
        for(int i=0; i<points.size(); i++){
              unordered_map<double, int> mp;
            for(int j=0; j<points.size(); j++){
                if(j==i) continue;
             double m = (double)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);                  cout<<m<<endl;
                if(mp.find(m)!=mp.end()) mp[m]++;
                else mp[m] = 2;
                  maxi = max(mp[m], maxi);
            }
          
        }
        return maxi;
        
    }
};