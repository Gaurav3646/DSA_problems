class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // iss array mein hamein ye batana hai ki sabki frequency unique ho to true;
        // otherwise false;
       
        // map syntax;
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;// ye array mein padi value ko key banayega aur ++ karega
            
        }
        // e.g. arr[]={1,2,2,1,1,3};
       // to map mein store hoga 
        //<key,value> pair <1,3> kyun ki one teen bar aaya hai
        // <2,2> kyun ki 2 do baar aya hai
        // <3,1> kyun ki 3 ek baar aaya hai
        // map mein pade sabhi pair ki values different hain to yes
        // other wise no
        // traversal syntax of map;

        vector<int> vect;
      for(auto itr = mp.begin(); itr!=mp.end(); itr++){
         vect.push_back(itr->second);
          
      }
        sort(vect.begin(), vect.end());
        for(int i=1; i<vect.size(); i++){
            if(vect[i-1]==vect[i]){
                return false;
            }
        }
        return true;
        
        
        
    }
};