// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int c[]={0,0,0};
        for(int i=0;i<n;i++)
        {
            c[a[i]]++;
        }
        int i=0;
        for(i=0;i<c[0];i++)
            a[i]=0;
        for(;i<c[0]+c[1];i++)
            a[i]=1;
        for(;i<c[0]+c[1]+c[2];i++)
            a[i]=2;
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends