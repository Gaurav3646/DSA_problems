class Allocator {
    unordered_map<int, vector<pair<int, int>>> alloc;
    map<int, int> avail;
public:
    Allocator(int n) {
       avail[0]=n;
    }
    
    int allocate(int size, int mID) {
       for(auto it=avail.begin(); it!=avail.end(); it++){
           
           if(it->second>=size){
               int i = it->first;
               int  nSize =it->second-size;
               alloc[mID].push_back({i, size});
               avail.erase(it);
               if(nSize>0){
                   avail.insert({i+size, nSize});
                   
               }
               return i;
           }
       }
        return -1;
      
    }
    
    int free(int mID) {
       int res = 0;
        auto it = alloc.find(mID);
        if(it!=alloc.end()){
             for (auto [i, sz] : it->second) {
            auto ita = avail.insert({i, sz}).first;
                 if(ita!=avail.begin()){
                    auto itr1 = prev(ita);
                     if(itr1->first+itr1->second==ita->first){
                         itr1->second += sz;
                         avail.erase(ita);
                         ita = itr1;
                     } 
                 }
                 if(next(ita)!=avail.end()){
                    auto itr1 = next(ita);
                     if(i+sz==itr1->first){
                         ita->second += itr1->second;
                         avail.erase(itr1);
                     }  
                 }
                 res += sz;
        }
        alloc.erase(it);
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */