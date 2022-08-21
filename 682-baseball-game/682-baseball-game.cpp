class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto it:ops)
        {
            if(it=="+")
            {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2);
                s.push(op1);
                s.push(op1+op2);
            }
            else if(it=="D")
            {
                int op1 = s.top();
                s.push(op1*2);
            }
            else if(it=="C")
            {
                s.pop();
            }
            else
            {
                int num = stoi(it);
                s.push(num);
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=(s.top());
            s.pop();
        }
        return sum;
    }
};