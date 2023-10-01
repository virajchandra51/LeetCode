class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int a = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return a;
    }
    
    int top() {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int a = q1.front();
        q1.pop();
        q2.push(a);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return a;
    }
    
    bool empty() {
        if(q1.size()==0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */