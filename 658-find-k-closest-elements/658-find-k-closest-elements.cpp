class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        int f = 0;
        int mid = (l + r) / 2;
        vector<int> ans;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (arr[mid] == x)
            {

                f = 1;
                break;
            }
            else if (arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (f)
        {
            ans.push_back(x);
            k--;
            l = mid - 1, r = mid + 1;
            while (k > 0)
            {
                if (l >= 0 && r < n)
                {
                    if (abs(x - arr[l]) <= abs(x - arr[r]))
                    {
                        k--;
                        ans.push_back(arr[l]);
                        l--;
                    }
                    else
                    {
                        k--;
                        ans.push_back(arr[r]);
                        r++;
                    }
                }
                else if (l >= 0)
                {
                    k--;
                    ans.push_back(arr[l]);
                    l--;
                }
                else
                {
                    k--;
                    ans.push_back(arr[r]);
                    r++;
                }
            }
        }
        else
        {
            swap(l, r);
            while (k > 0)
            {
                if (l >= 0 && r < n)
                {
                    if (abs(x - arr[l]) <= abs(x - arr[r]))
                    {
                        k--;
                        ans.push_back(arr[l]);
                        l--;
                    }
                    else
                    {
                        k--;
                        ans.push_back(arr[r]);
                        r++;
                    }
                }
                else if (l >= 0)
                {
                    k--;
                    ans.push_back(arr[l]);
                    l--;
                }
                else
                {
                    k--;
                    ans.push_back(arr[r]);
                    r++;
                }
            }
        }
        cout << mid << endl;
        cout << l << " " << r << endl;

        sort(ans.begin(), ans.end());
        return ans;
    }
};