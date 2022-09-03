class Solution {
public:
    set<int> ans;
    void BFS(int start, int n, int &k)
    {
        queue<int> q;
        q.push(start);
        n--;
        while(!q.empty())
        {
            queue<int> temp;
            while(!q.empty())
            {
                int num = q.front();
                q.pop();
                if(num%10+k<=9)
                temp.push(num*10+(num%10+k));
                if(num%10-k>=0)
                temp.push(num*10+(num%10-k));
            }
            n--;
            q=temp;
            if(n==0)
                break;
        }
        while(!q.empty())
        {
            ans.insert(q.front());
            q.pop();
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        BFS(i,n,k);
        vector<int> r;
        for(auto it:ans)
            r.push_back(it);
        return r;
    }
};