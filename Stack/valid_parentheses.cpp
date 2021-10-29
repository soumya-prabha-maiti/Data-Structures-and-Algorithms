// Problem link : https://leetcode.com/problems/valid-parentheses/
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(stk.empty())
                    return false;
                char ch=stk.top();
                stk.pop();
                if(!((ch=='(' && s[i]==')')||(ch=='{' && s[i]=='}')||(ch=='[' && s[i]==']')))
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s1;
    string s="[[]](){}";
    cout<<s1.isValid(s);
    return 0;
}