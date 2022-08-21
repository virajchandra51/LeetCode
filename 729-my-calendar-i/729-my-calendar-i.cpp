class MyCalendar {
public:
    int s,e; vector<pair<int,int>> v;
    MyCalendar() {
        s=0;e=0;
    }
    
    bool book(int start, int end) {
        s=start;
        e=end;
        int f=1;
        for(auto it:v)
        {
            if(s<it.second && s>it.first)
            {
                f=0;break;
            }
            if(e>it.first && e<it.second)
            {
                f=0;break;
            }
            if(s==it.first && e>it.second)
            {
                f=0;break;
            }
            if(e==it.second && s<it.first)
            {
                f=0;break;
            }
            if(e==it.second && s==it.first)
            {
                f=0;break;
            }
            if(e>it.second && s<it.first)
            {
                f=0;break;
            }
        }
        if(f)
            v.push_back({s,e});
        else
            return false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */