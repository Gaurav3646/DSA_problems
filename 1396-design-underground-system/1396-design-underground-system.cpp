class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mp;
    map<pair<string, string>, pair<double, int>> avg;
    
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
    string out = mp[id].first;
    int t2 = mp[id].second;
        if(avg.find({out, stationName})==avg.end()){
            avg[{out, stationName}] = {t-t2, 1};
        }
        else{
            double tt = avg[{out, stationName}].first+(t-t2);
            int fq = avg[{out, stationName}].second; 
            avg[{out, stationName}] = {tt, fq+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avg[{startStation, endStation}].first/avg[{startStation, endStation}].second;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */