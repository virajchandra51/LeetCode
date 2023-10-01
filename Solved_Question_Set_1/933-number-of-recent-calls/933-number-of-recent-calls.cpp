class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        vector<int> a;
        v=a;
    }
    
    int ping(int t) {
        v.push_back(t);
        int c=0;
        for(auto it:v)
        {
            if(it>=(t-3000) && it<=(t))
                c++;
        }
        return c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */