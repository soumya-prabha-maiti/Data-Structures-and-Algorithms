// Problem link :

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &arr, int target)
    {
        //Solution : Binary search

        int left=0, right=arr.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(arr[mid]>=target)
            {
                if(arr[mid]==target || arr[mid]>target && arr[mid-1]<target)
            }
            else
            {
                left=mid+1;
            }
        }
    }
};

int main()
{
    Solution s1;

    return 0;
}