
#include <iostream>      // For cin and cout
#include <string>        // For using strings
#include <unordered_map> // For storing Roman numeral values
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        // STEP 1: Create a mapping of Roman numerals
        // to their corresponding integer values.
        //
        // We use unordered_map because it allows us
        // to quickly retrieve a value using its key.
        //
        // Example:
        // roman['I'] gives 1
        // roman['V'] gives 5
        // roman['X'] gives 10
        //
        // char = Roman symbol
        // int  = corresponding integer value

        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        // STEP 2: Get the length of the input string.
        //
        // Example: s = "XIV"
        // len = 3

        int len = s.size();

        // STEP 3: Initialize result to zero.
        //
        // We will add or subtract Roman numeral values
        // from this variable to calculate the final answer.

        int res = 0;

        // STEP 4: Traverse the string character by character.
        //
        // Example: s = "XIV"
        //
        // i = 0 -> X
        // i = 1 -> I
        // i = 2 -> V

        for (int i = 0; i < len; i++)
        {

            // STEP 5: Check whether to add or subtract.
            //
            // Roman numeral rule:
            //
            // If a smaller numeral appears before a larger
            // numeral, we subtract the smaller value.
            //
            // Example: IV = 5 - 1 = 4
            //          IX = 10 - 1 = 9
            //
            // Otherwise, we add the current numeral.
            //
            // Example: VI = 5 + 1 = 6
            //          XI = 10 + 1 = 11
            //
            // FIRST CONDITION: i + 1 < len
            //
            // Checks whether a next character exists.
            //
            // Example: s = "XIV", len = 3
            //
            // i = 1 -> i + 1 = 2 < 3 (valid)
            // i = 2 -> i + 1 = 3 < 3 (false)
            //
            // This prevents accessing a character
            // beyond the end of the string.
            //
            // SECOND CONDITION:
            // roman[s[i]] < roman[s[i + 1]]
            //
            // Compares the integer values of the
            // current and next Roman numerals.
            //
            // Example: s = "IV"
            //
            // roman['I'] = 1
            // roman['V'] = 5
            //
            // Since 1 < 5, subtract 1.

            if (i + 1 < len &&
                roman[s[i]] < roman[s[i + 1]])
            {

                // STEP 6: Subtract current value.
                //
                // Example: s = "IV"
                //
                // i = 0 -> I = 1
                // res = 0 - 1 = -1
                //
                // Next iteration:
                // i = 1 -> V = 5
                // res = -1 + 5 = 4

                res -= roman[s[i]];
            }
            else
            {

                // STEP 7: Add the current value.
                //
                // This happens when:
                //
                // 1. Current value >= next value.
                // 2. We are at the last character.
                //
                // Example: s = "VI"
                //
                // i = 0 -> V = 5
                // res = 0 + 5 = 5
                //
                // i = 1 -> I = 1
                // res = 5 + 1 = 6

                res += roman[s[i]];
            }
        }

        // STEP 8: Return the final integer value.
        //
        // Example:
        // XIV -> 10 - 1 + 5 = 14

        return res;
    }
};

int main()
{

    // Create an object of the Solution class.
    //
    // This lets us call the romanToInt() function.

    Solution sol;

    // Store Roman numeral test cases.
    //
    // Each input has a corresponding expected answer.

    string tests[] = {
        "III",
        "LVIII",
        "MCMXCIV",
        "IV",
        "IX",
        "XL",
        "XC",
        "CD",
        "CM",
        "XIV"};

    // Expected integer values of the test cases.
    //
    // The order must match the tests array.

    int expected[] = {
        3, 58, 1994, 4, 9,
        40, 90, 400, 900, 14};

    // Calculate the number of test cases.
    //
    // sizeof(tests) = total memory used by the array.
    // sizeof(tests[0]) = memory used by one element.
    //
    // Dividing gives the number of elements.

    int n = sizeof(tests) / sizeof(tests[0]);

    // Run all test cases one by one.

    for (int i = 0; i < n; i++)
    {

        // Call our function with the current input.
        // Store the returned integer in result.

        int result = sol.romanToInt(tests[i]);

        // Display the test case details.

        cout << "Test " << i + 1 << endl;
        cout << "Input: " << tests[i] << endl;
        cout << "Expected: " << expected[i] << endl;
        cout << "Output: " << result << endl;

        // Compare actual output with expected output.
        //
        // If they are equal -> PASS
        // Otherwise -> FAIL
        //
        // This uses the ternary operator:
        //
        // condition ? value_if_true : value_if_false

        cout << (result == expected[i] ? "PASS" : "FAIL")
             << endl;

        cout << "------------------------" << endl;
    }

    // STEP 9: Allow the user to test custom input.

    string s;

    cout << "\nEnter a Roman numeral: ";
    cin >> s;

    // Pass user input to our function
    // and display the converted integer.

    cout << "Integer value: " << sol.romanToInt(s)
         << endl;

    return 0;
}
