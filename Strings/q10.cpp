// 1614. Maximum Nesting Depth of the Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;

        int res = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                depth++;

                res = max(res, depth);
            }
            else if (ch == ')')
            {
                if (depth > 0)
                {
                    depth--;
                }
            }
        }

        return res;
    }
};