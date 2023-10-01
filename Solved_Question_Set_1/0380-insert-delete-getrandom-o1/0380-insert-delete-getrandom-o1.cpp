class RandomizedSet {
public:
    
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        v.emplace_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int l = v.back();
        mp[l] = mp[val];
        v[mp[val]] = l;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
    private:
    unordered_map<int,int> mp;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */