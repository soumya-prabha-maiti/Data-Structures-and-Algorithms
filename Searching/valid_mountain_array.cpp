// Problem link : https://leetcode.com/problems/valid-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;

        bool increasing = 1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
                return false;

            if (increasing)
            {
                if (arr[i] > arr[i + 1])
                    increasing = false;
            }
            else
            {
                if (arr[i] < arr[i + 1])
                    return false;
            }

            if (!increasing && i == 0)
                return false;
            if (increasing && i == arr.size() - 2)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s1;

    return 0;
}