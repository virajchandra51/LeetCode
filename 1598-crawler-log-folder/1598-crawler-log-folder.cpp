class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(auto it:logs)
        {
            if(it.compare("../")==0 && !s.empty())
                s.pop();
            else if(it.compare("./")==0)
                continue;
            else if(it!="../" && it!="./")
                s.push(it);
        }
        
        return s.size();
    }
};