class Solution {
public:
    bool solve(vector<int>& arr, int start){
        if(start<0|| start>=arr.size() ||arr[start]==-1){
            return false;
        }
      if(arr[start]==0){
          return true;
      } 
        int x =  arr[start];
        arr[start] = -1;
        return solve(arr, start+x) | solve(arr, start-x);

    }
    bool canReach(vector<int>& arr, int start) {   
        return solve(arr, start);
    }
};