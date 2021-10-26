// Problem link : https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;

        int peak;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            // cout << mid << " ";
            bool c1 = (mid == 0) ? 1 : (arr[mid - 1] < arr[mid]);
            bool c2 = (mid == arr.size() - 1) ? 1 : (arr[mid] > arr[mid + 1]);
            if (c1 && c2)
            {
                //peak of the mountain
                peak = mid;
                // cout << "Invoked 1";
                break;
            }
            else if (c1 && !c2)
            { 
                //increasing slope
                // cout << "Invoked 2";
                start = mid + 1;
            }
            else
            { 
                //descending slope and valley
                // cout << "Invoked 3";
                end = mid - 1;
            }
        }
        return peak;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {1, 2};
    cout << s1.findPeakElement(nums);

    return 0;
}