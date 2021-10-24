

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ceiling_soln2(vector<int> &nums, int target)
    {
        //Solution : Binary search

        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return nums[mid];
            else if(nums[mid]>target)
            {
                if(mid==0 || nums[mid-1]<target)
                    return nums[mid];
                else
                    end=mid-1;
            }
            else
                start=mid+1;
        }

        return -1;
    }

    int ceiling(vector<int> &nums, int target)
    {
        //If all nos are smaller than target
        if(nums[nums.size()-1]<target)
            return -1;         

        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }

       return start;
    } 

    int floor(vector<int> &nums, int target)
    {
        //If all nos are greater than target
        if(nums[0]>target)
            return -1;         

        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }

       return end;
    }  


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
};

int main()
{
    Solution s1;
    vector<int> nums={1,3,5,7,9,10};

    cout<<s1.ceilingEasy(nums,4);
    
    return 0;
}