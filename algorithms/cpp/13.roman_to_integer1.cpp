#include "global.h"

using namespace std;

class Solution {
public :
    int romanToInt(string s)
    {
        return romanToInt(s.c_str(), s.size());
    }

    int romanToInt(const char * s, int len)
    {
        // Write your code here
        int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const char * letters[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int r = 0;
        int i = 0, j = 0;
        while (i < 13)
        {
            size_t k = strlen(letters[i]);
            while (len - j >= k)
            {
                bool b = k == 1 ? letters[i][0] == s[j] : letters[i][0] == s[j] && letters[i][1] == s[j+1];
                if (b)
                {
                    r += numbers[i];
                    j += k;
                }
                else
                {
                    break;
                }
            }
            ++i;
        }
        return r;
    }
};

int romanToInt1(int argc, const char *argv[])
{
    int target = 9;

    Solution solution;
    int r; string s;
    s = "I";
    r = solution.romanToInt(s.c_str(), s.size());
    fn_print(fn_format("Leetcode.intToRoman(\"%s\")[1].return=%d !", s.c_str(), r));

    s = "XVIII";
    r = solution.romanToInt(s.c_str(), s.size());
    fn_print(fn_format("Leetcode.intToRoman(\"%s\")[18].return=%d !", s.c_str(), r));

    s = "XCIX";
    r = solution.romanToInt(s.c_str(), s.size());
    fn_print(fn_format("Leetcode.intToRoman(\"%s\")[99].return=%d !", s.c_str(), r));

    s = "MCDXXXVII";
    r = solution.romanToInt(s.c_str(), s.size());
    fn_print(fn_format("Leetcode.intToRoman(\"%s\")[1437].return=%d !", s.c_str(), r));

    s = "MMMCCCXXXIII";
    r = solution.romanToInt(s.c_str(), s.size());
    fn_print(fn_format("Leetcode.intToRoman(\"%s\")[3333].return=%d !", s.c_str(), r));

    return TRUE;
}
int fn_intToRoman1 = fn_add_case("romanToInt1", romanToInt1);
