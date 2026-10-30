// 1021. Remove Outermost Parentheses

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        // Tracks how many opening '(' are unmatched
        int depth = 0;

        // Stores parentheses that we want to keep
        string result = "";

        // Visit every character in the string
        for (char ch : s)
        {

            // CASE 1: Opening parenthesis '('
            if (ch == '(')
            {

                // If depth > 0, we are already
                // inside a primitive.
                // So this is NOT the outermost '('.
                if (depth > 0)
                {
                    result += ch;
                }

                // Increase depth AFTER checking
                depth++;
            }

            // CASE 2: Closing parenthesis ')'
            else
            {

                // Decrease depth BEFORE checking
                depth--;

                // If depth > 0, we are still
                // inside the primitive.
                // So keep this closing ')'.
                if (depth > 0)
                {
                    result += ch;
                }
            }
        }

        return result;
    }
};
