// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int strictly_greater(vector<int> &nums, int target)
    {
        //If all nos are smaller than target
        if(nums[nums.size()-1]<=target)
            return -1;         

        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<=target)
                start=mid+1;
            else if(nums[mid]>target)
                end=mid-1;
        }

       return start;
    } 

    int strictly_smaller(vector<int> &nums, int target)
    {
        //If all nos are greater than target
        if(nums[0]>=target)
            return -1;         

        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]>=target)
                end=mid-1;
        }

       return end;
    }
    
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if(nums[0]>target || nums[nums.size()-1]<target)
        {
            vector<int> ans={-1,-1};
            return ans;
        }

        int low= strictly_smaller(nums,target);
        int high= strictly_greater(nums,target);

        if(low+1<nums.size() && nums[low+1]==target)
        {
            vector<int> ans;
            ans.push_back(low+1);
            if(high==-1)
                ans.push_back(nums.size()-1);
            else
                ans.push_back(high-1);
            return ans;
        }
        else
        {
            vector<int> ans={-1,-1};
            return ans;
        }


    }
};

int main()
{
    Solution s1;
    vector<int> nums={5,7,7,8,8,10},ans;
    ans=s1.searchRange(nums,8);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}