// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    
    void swap(int &a,int &b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
       int pivot,fast,slow;
       
   
       pivot= l + rand()%(r-l+1);
       swap(arr[pivot],arr[r]);
       
       
       for(fast=0,slow=0;fast<r;fast++)
       {
           if(arr[fast]<arr[r])
            {
                swap(arr[fast],arr[slow]);
                slow++;
            }
            
       }
       swap(arr[r],arr[slow]);
       
       if(slow-l+1==k)
            return arr[slow];
        else if(slow-l+1>k)
            return kthSmallest(arr,l,slow-1,k);
        else
            return kthSmallest(arr,slow+1,r,k-(slow-l+1));
       
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends