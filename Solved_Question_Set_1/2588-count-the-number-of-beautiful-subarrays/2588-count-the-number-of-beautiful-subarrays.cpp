class Solution {
public:
    long long beautifulSubarrays(vector<int>& arr) {
        long long ans = 0; // Initialize answer to be returned
 int n = arr.size();
    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];
 
    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;
 
    // Initialize first element of prefix array
    xorArr[0] = arr[0];
 
    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
 
    // Calculate the answer
    for (int i = 0; i < n; i++) {
       
        // Find XOR of current prefix with m.
        int tmp = 0 ^ xorArr[i];
 
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);
 
        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == 0)
            ans++;
 
        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }
 
    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
    }
};