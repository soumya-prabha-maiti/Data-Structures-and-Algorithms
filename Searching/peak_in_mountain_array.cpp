// Problem link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start=1,end=arr.size()-2;
        // start=0, end=arr.size()-1 will not work as in those edges mid-1 or mid+1 will be out of bound
        int peak;      
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            {
                //peak of the mountain
                peak=mid;
                break;
            }
            else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
                //increasing slope
                start=mid+1;
            else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
                //descending slope
                end=mid-1;
        }
        return peak;
    }
};

int main()
{
    Solution s1;
    vector<int> arr={3,5,3,2,0};
    cout<<s1.peakIndexInMountainArray(arr);
    return 0;
}