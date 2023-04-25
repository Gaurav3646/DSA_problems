class SmallestInfiniteSet {
private:
    
    vector<int> vect;
    set<int> p;
    int i;
public:
    SmallestInfiniteSet() {
       for(int i=1; i<=1000; i++){
           p.insert(i);
       }
    }
    
    int popSmallest() {
     int x = *(p.begin());
        p.erase(p.begin());
        return x;
    }
    
    void addBack(int num) {
       p.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */