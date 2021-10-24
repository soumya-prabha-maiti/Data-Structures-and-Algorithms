// Problem link : https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        //If all nos are smaller than target
        if (letters[letters.size() - 1] <= target)
            return letters[0];

        int start = 0, end = letters.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (letters[mid] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return letters[start];
    }
};

int main()
{
    Solution s1;
    vector<char> letters= {'c','f','j'}; 
    char target = 'c';

    cout<<s1.nextGreatestLetter(letters,target);
    return 0;
}