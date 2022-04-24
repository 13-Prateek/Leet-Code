class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap;
    unordered_map<string,pair<int,int>> checkOutMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& start=checkInMap[id];
        string route=start.first+"_"+stationName;
        checkOutMap[route].first+=t-start.second;
        checkOutMap[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"_"+endStation;
        auto& time=checkOutMap[route];
        return (double) time.first / time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */