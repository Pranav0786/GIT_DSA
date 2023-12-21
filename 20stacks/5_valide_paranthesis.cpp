// leetcode 20

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st; 
        for (char c : s) 
        { 
            if (c == '(' || c == '{' || c == '[') 
            {  
                st.push(c); 
            } 
            else 
            { 
                if (  st.empty() || 
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')  ) 
                {
                    return false; 
                }
                
                st.pop(); 
            }
        }

        return st.empty(); 
    }
};
int main()
{

    return 0;
}