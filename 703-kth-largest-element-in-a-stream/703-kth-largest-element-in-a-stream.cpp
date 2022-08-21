class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int> > queue;
        
    KthLargest(int k, vector<int>& nums) {
        
       this -> k = k;
        
        if(nums.size() == 0)    return;
        
        for(auto it: nums)
            queue.push(it);
        
        while(queue.size()>k)
            queue.pop();
        
    }
    
    int add(int val) {
        
        queue.push(val);
        
        while(queue.size()!=k)
            queue.pop();
        
        return queue.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */