// Link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> stk;
        for(int i=0;i<S.size();i++)
        {
            if((S[i]-'0')>=0 && (S[i]-'0')<=9)
                stk.push(S[i]-'0');
            else
            {
                int operand2=stk.top();
                stk.pop();
                int operand1=stk.top();
                stk.pop();
                
               switch(S[i])
               {
                   case '+':
                    stk.push(operand1+operand2);
                    break;
                
                    case '-':
                    stk.push(operand1-operand2);
                    break;
                    
                    case '*':
                    stk.push(operand1*operand2);
                    break;
                    
                    case '/':
                    stk.push(operand1/operand2);
                    break;
               }
            }
        }
        return stk.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends