// Problem link :

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binary_search(vector<int> &arr, int target)
    {
        int start=0, end=arr.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }

        cout<<target<<" not found.\nEnd="<<end<<" , Start="<<start<<endl;
        return -1;
    }


    int test(vector<int> &arr, int target)
    {
        int start=0, end=arr.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]<=target)
                start=mid+1;
            else if(arr[mid]>target)
                end=mid-1;
        }

        cout<<"\nEnd="<<end<<" , Start="<<start<<endl;
        return -1;
    }

};

int main()
{
    Solution s1;
    vector<int> arr={1,3,5,7,9,10};

    cout<<s1.test(arr,5);
    
    return 0;
}