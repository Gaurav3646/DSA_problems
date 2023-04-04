class Solution {
public:
    int partitionString(string s) {
      vector<int> a(26, -1);
        int count = 1;
        int j =0;
        for(int i=0; i<s.size(); i++){
            if(a[s[i]-'a']>=j){
                count++;
                j = i;
            }
            a[s[i]-'a']=i;
        }
        return count;
    }
};