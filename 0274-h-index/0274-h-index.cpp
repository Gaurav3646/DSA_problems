class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end());
        int k=1;
        for(int i=citations.size()-1; i>=0; i--){
            if(citations[i]>=k){
                k++;
            }
            else{
                return k-1;
            }
        }
        return k-1;
    }
};