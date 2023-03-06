class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            
            int m = (s+e)/2;
            if(arr[m]-m-1>=k){
                e = m;
            }
            else{
               s = m+1;
            }
        }
        cout<<arr[e]<<endl;
    if((k-(arr[e]-e-1))>0){
         return (k-(arr[e]-e-1)) +arr[e];
    }else{
       return (k-(arr[e]-e-1)) +arr[e]-1;
    }
        return -1;
    }
};