class Solution {
public:
    
    int maxJump(vector<int>& stones) {
       int n = stones.size();
       vector<int>v;
       vector<int>res;
       int l = stones[0], h = stones[n-1];
       for(int i = 1;i<n-1;i++)
       {
            v.push_back(stones[i]);
       }
       sort(v.begin(),v.end());
       int l1=l,l2=l;
       if(stones.size()==2)
            return (h-l);
       for(int i=0;i<v.size();i=i+2)
       {
            res.push_back(v[i]-l1);
            l1=v[i];
       }
       res.push_back(h-l1);
       for(int i=1;i<v.size();i=i+2)
       {
            res.push_back(v[i]-l2);
            l2=v[i];
       }
       res.push_back(h-l2);
       sort(res.begin(),res.end());
       return res[res.size()-1];

    }
};