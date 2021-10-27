class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else
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