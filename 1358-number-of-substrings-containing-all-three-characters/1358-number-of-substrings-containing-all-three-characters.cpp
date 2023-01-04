class Solution {
public:
    int numberOfSubstrings(string s) {
        // O(N) time , O(1) space [because hasmap size is always 3]
        int left = 0 , right = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(right != s.size())
        {
            map[s[right]] += 1; // adding new element to window
            
            while(map['a'] and map['b'] and map['c']) // while(window is good)
            {
                
				// removing first element[means shrinking window from front to form new window]
                map[s[left]] -= 1; 
                left++;
            }
            right++;
            count+=left;
        }
        return count;
    }
};