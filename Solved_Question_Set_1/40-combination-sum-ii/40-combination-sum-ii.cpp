class Solution {
public:
    vector<vector<int>> v;
    void dfs(vector<int> &candidates, int id, int target, vector<int> &a, int n)
    {
        if(target == 0){
            v.push_back(a);
            return;
        }
        for(int i = id; i< candidates.size(); i++){
            if(candidates[i] > target) break;
            if(i  > id && candidates[i] == candidates[i-1])
                continue;
                
            a.push_back(candidates[i]);
            dfs(candidates, i+1, target-candidates[i], a,n); //call for next  index element
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> a;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,a,candidates.size());
        return v;
    }
};