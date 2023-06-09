class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size();
        while(i<j){
            // cout<<i<<" "<<j<<endl;
            int m = (i+j)/2;
            if(letters[m]>target) j = m;
            else i = m+1;
            
        }
        return letters[i%letters.size()];
    }
};