#include "global.h"

using namespace std;

class Solution {
public :
    string intToRoman(int n)
    {
        // Write your code here
        int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string letters[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        for (int i = 0; i < 13; i++)
        {
            if (n >= numbers[i])
            {
                int count = n / numbers[i];
                n = n % numbers[i];
                for (int j = 0; j < count; j++)
                {
                    res = res + letters[i];
                }
            }
        }
        return res;
    }
};

int intToRoman1(int argc, const char *argv[])
{
    int target = 9;

    Solution solution;
    string r;
    r = solution.intToRoman(1);
    fn_print(fn_format("Leetcode.intToRoman(1).return=%s !", r.c_str()));

    r = solution.intToRoman(4);
    fn_print(fn_format("Leetcode.intToRoman(4).return=%s !", r.c_str()));

    r = solution.intToRoman(9);
    fn_print(fn_format("Leetcode.intToRoman(9).return=%s !", r.c_str()));

    r = solution.intToRoman(44);
    fn_print(fn_format("Leetcode.intToRoman(44).return=%s !", r.c_str()));

    r = solution.intToRoman(89);
    fn_print(fn_format("Leetcode.intToRoman(89).return=%s !", r.c_str()));

    r = solution.intToRoman(98);
    fn_print(fn_format("Leetcode.intToRoman(98).return=%s !", r.c_str()));

    r = solution.intToRoman(3950);
    fn_print(fn_format("Leetcode.intToRoman(3950).return=%s !", r.c_str()));

    r = solution.intToRoman(3999);
    fn_print(fn_format("Leetcode.intToRoman(3999).return=%s !", r.c_str()));

    return TRUE;
}
int fn_intToRoman1 = fn_add_case("intToRoman1", intToRoman1);
