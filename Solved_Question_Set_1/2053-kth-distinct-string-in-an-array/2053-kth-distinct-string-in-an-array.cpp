class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
         unordered_map<string,int> m;
        for (int i=0;i<arr.size();i++) {
            if (m.find(arr[i])!=m.end()) m[arr[i]]=-1;
            else m[arr[i]]=i;
        }
        for (int i=0;i<arr.size();i++) {
            if (m[arr[i]]!=-1) k--;
            if (k==0) return arr[i];
        }
        return "";
    }
};