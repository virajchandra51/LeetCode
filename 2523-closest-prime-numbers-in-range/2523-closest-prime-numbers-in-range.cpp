class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    int primes(int low, int high, vector<int> &ans)
    {
        for (int i = low; i <= high; i++)
            if (isPrime(i))
                ans.push_back(i);
        return 0;
    }
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> ans;
        primes(left, right, ans);
        if (ans.size() <= 1)
            return {-1, -1};
        int nums1 = -1, nums2 = -1;
        int mn = INT_MAX;
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i + 1] - ans[i] == mn)
            {
                if (nums1 > ans[i])
                {
                    nums1 = ans[i];
                    nums2 = ans[i + 1];
                }
            }
            if (ans[i + 1] - ans[i] < mn)
            {
                nums1 = ans[i];
                nums2 = ans[i + 1];
                mn = ans[i + 1] - ans[i];
            }
        }
        return {nums1, nums2};
    }
};