
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        // Map Roman symbols to their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int len = s.size();
        int res = 0;

        for (int i = 0; i < len; i++)
        {

            // If current value is smaller than next,
            // subtract the current value
            if (i + 1 < len &&
                roman[s[i]] < roman[s[i + 1]])
            {

                res -= roman[s[i]];
            }
            else
            {

                // Otherwise add the current value
                res += roman[s[i]];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    // Test cases and expected answers
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

    int expected[] = {
        3, 58, 1994, 4, 9,
        40, 90, 400, 900, 14};

    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++)
    {
        int result = sol.romanToInt(tests[i]);

        cout << "Test " << i + 1 << endl;
        cout << "Input: " << tests[i] << endl;
        cout << "Expected: " << expected[i] << endl;
        cout << "Output: " << result << endl;

        cout << (result == expected[i] ? "PASS" : "FAIL")
             << endl;

        cout << "------------------------" << endl;
    }

    // Test your own Roman numeral
    string s;
    cout << "\nEnter a Roman numeral: ";
    cin >> s;

    cout << "Integer value: " << sol.romanToInt(s)
         << endl;

    return 0;
}
