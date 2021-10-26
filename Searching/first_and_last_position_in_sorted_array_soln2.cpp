// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target, bool firstPosition)
    {
        int start = 0, end = nums.size() - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                //potential first or last position of target found
                ans = mid;

                if (firstPosition)
                    //if we intend to find the first position of target, we search in the left half
                    end = mid - 1;
                else
                    //if we intend to find the last position of target, we search in the right half
                    start = mid + 1;
            }
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return ans;
        //if target is not found, then ans will never be modified and -1 will be returned
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> soln(2, -1);
        soln[0] = search(nums, target, true);
        if (soln[0] != 1)
            soln[1] = search(nums, target, false);

        return soln;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {5, 7, 7, 8, 8, 10}, ans;

    ans = s1.searchRange(nums, 8);
    cout << ans[0] << " " << ans[1];
    return 0;
}