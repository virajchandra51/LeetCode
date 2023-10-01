class Solution {
public:
    bool canReplace(string &target, string &stamp, int pos){
        for(int i=0;i<stamp.size();i++)
        {
            if(target[i+pos]!='?' && target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    void replace(string &target, int stampLength, int pos, int &count)
    {
        for(int i=0;i<stampLength;i++)
        {
            if(target[i+pos]!='?')
            {
                target[i+pos] = '?';
                count++;
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        vector<bool> visited(target.size(),false);
        vector<int> ans;
        while(count!=target.size())
        {
            bool didChange = false;
            for(int i=0;i<=target.size()-stamp.size();i++)
            {
                if(!visited[i] && canReplace(target,stamp,i))
                {
                    replace(target,stamp.size(),i,count);
                    visited[i]=true;
                    didChange = true;
                    ans.push_back(i);
                    if(count==target.size())
                        break;
                }
            }
            if(!didChange)
                return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};