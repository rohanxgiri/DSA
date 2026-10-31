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

int main()
{
    Solution sol;

    // Test cases
    string tests[] = {
        "(1+(2*3)+((8)/4))+1",
        "(1)+((2))+(((3)))",
        "()(())((()()))",
        "1+2*3",
        "((()))",
        "()"};

    int expected[] = {3, 3, 3, 0, 3, 1};

    for (int i = 0; i < 6; i++)
    {
        int result = sol.maxDepth(tests[i]);

        cout << "Test " << i + 1 << endl;
        cout << "Input: " << tests[i] << endl;
        cout << "Expected: " << expected[i] << endl;
        cout << "Output: " << result << endl;
        cout << (result == expected[i] ? "PASS" : "FAIL") << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}