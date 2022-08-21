class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> arr(boxes.length(),0);
        for(int i=0;i<boxes.size();i++)
        {
            for(int j=0;j<boxes.size();j++)
            {
                if(boxes[j] == '1')
                {
                    arr[i] += abs(i-j);
                }
            }
        }
        return arr;
    }
};