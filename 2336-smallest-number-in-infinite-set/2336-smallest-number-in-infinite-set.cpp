class SmallestInfiniteSet {
private:

    set<int> p;
    int i = 1;
public:
    // SmallestInfiniteSet() {
    //    // for(int i=1; i<=1000; i++){
    //    //     p.insert(i);
    //    // }
    //     i=1;
    // }
    
    int popSmallest() {
        if(!p.empty()){
     int x = *(p.begin());
        p.erase(p.begin());
    
        return x;
        }
        return i++;
    }
    
    void addBack(int num) {
        if(num<i)
       p.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */