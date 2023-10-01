class UndergroundSystem {
public:
    map<int,pair<string,int>> m1;
    map<string,vector<int>> m2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        m2[m1[id].first+"->"+stationName].push_back((t-m1[id].second));
        m1.erase(id);
    }
    
    double getAverageTime(string s1, string s2) {
        double s = 0.0;
        for(auto it: m2[s1+"->"+s2]) s+=it;
        return s/m2[s1+"->"+s2].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */