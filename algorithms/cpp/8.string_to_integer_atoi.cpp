#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    int myAtoi(string str)
    {
        const char *pointer = str.c_str();
        int multiplier = 1;
        int result = 0;
        while (*pointer != '\0')
        {
            if (*pointer >= '0' && *pointer <= '9')
                multiplier = multiplier * 10;

            pointer = pointer + 1;
        }

        multiplier = multiplier / 10;
        pointer = str.c_str();
        while (*pointer != '\0')
        {
            if (*pointer >= '0' && *pointer <= '9')
            {
                result = result + ((*pointer % 48) * multiplier);
                multiplier = multiplier / 10;
            }

            pointer = pointer + 1;
        }
        return result;
    };
};

class SolutionHaoel {
public:
    int myAtoi(string str)
    {
        const char *ps = str.c_str();
        if (ps == NULL || *ps == '\0')
        {
            return 0;
        }

        int ret = 0;

        for (; isspace(*ps); ps++);

        bool neg = false;
        if (*ps == '-' || *ps == '+')
        {
            neg = (*ps == '-');
            ps++;
        }

        for (; isdigit(*ps); ps++)
        {
            int digit = (*ps - '0');
            if (neg)
            {
                if (-ret < (INT_MIN + digit) / 10)
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (ret > (INT_MAX - digit) / 10)
                {
                    return INT_MAX;
                }
            }

            ret = 10 * ret + digit;
        }

        return neg ? -ret : ret;
    };
};

class Solution {
public:
    int myAtoi(string str)
    {
        int i, r = 0;
        bool bNegative = false;

        for (i = 0; isspace(str[i]); i++);

        if (str[i] == '-' || str[i] == '+')
        {
            bNegative = (str[i] == '-');
            ++i;
        }

        for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++)
        {
            int bn = str[i] - '0';

            if (bNegative)
            {
                if (-r < (INT_MIN + bn) / 10)
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (r > (INT_MAX - bn) / 10)
                {
                    return INT_MAX;
                }
            }
            r = r * 10 + str[i] - '0';
        }
        return bNegative ? -r : r;
    }
};

int test_myAtoi0(int argc, const char *argv[])
{
    string s = "42";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi0 = fn_add_case("myAtoi0", test_myAtoi0);

int test_myAtoi1(int argc, const char *argv[])
{
    string s = "words and 987";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi1 = fn_add_case("myAtoi1", test_myAtoi1);

int test_myAtoi2(int argc, const char *argv[])
{
    string s = "   -42";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi2 = fn_add_case("myAtoi2", test_myAtoi2);

int test_myAtoi3(int argc, const char *argv[])
{
    string s = "-91283472332";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi3 = fn_add_case("myAtoi3", test_myAtoi3);

int test_myAtoi4(int argc, const char *argv[])
{
    string s = "291283472332";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi4 = fn_add_case("myAtoi4", test_myAtoi4);

int test_myAtoi5(int argc, const char *argv[])
{
    string s = "+1";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi5 = fn_add_case("myAtoi5", test_myAtoi5);

int test_myAtoi6(int argc, const char *argv[])
{
    string s = "+-2";

    // Haoel
    SolutionHaoel solutionHaoel;
    int r = solutionHaoel.myAtoi(s);
    fn_print(fn_format("Haoel.myAtoi.return=%d !", r));

    // oudream
    Solution solution;
    int r2 = solution.myAtoi(s);
    fn_print(fn_format("oudream.myAtoi.return=%d !", r2));

    return TRUE;
}
int fn_test_myAtoi6 = fn_add_case("myAtoi6", test_myAtoi6);
