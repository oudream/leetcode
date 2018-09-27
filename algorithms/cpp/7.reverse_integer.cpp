#include "global.h"

using namespace std;

class SolutionLeecode {
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

class Solution {
public:
    int reverse(int x)
    {
        bool bNeg = x < 0;
        if (bNeg) x = -x;
        int r = 0;
        while (x != 0)
        {
            int bn = x % 10;
            x /= 10;
            if (bNeg)
            {
                if (-r < (INT_MIN + bn) / 10)
                    return 0;
            }
            else
            {
                if (r > (INT_MAX - bn) / 10)
                    return 0;
            }
            r = r * 10 + bn;
        }
        return bNeg ? -r : r;
    }
};

int test_reverse1(int argc, const char *argv[])
{
    int n1 = 0;
    int n2 = -1;
    int n3 = 1;
    int n4 = INT_MIN;
    int n5 = INT_MAX;
    int n6 = 123;
    int n7 = -123;

    // oudream
    Solution solution;
    int r1 = solution.reverse(n1);
    fn_print(fn_format("oudream.reverse.return = %d !", r1));
    int r2 = solution.reverse(n2);
    fn_print(fn_format("oudream.reverse.return = %d !", r2));
    int r3 = solution.reverse(n3);
    fn_print(fn_format("oudream.reverse.return = %d !", r3));
    int r4 = solution.reverse(n4);
    fn_print(fn_format("oudream.reverse.return = %d !", r4));
    int r5 = solution.reverse(n5);
    fn_print(fn_format("oudream.reverse.return = %d !", r5));
    int r6 = solution.reverse(n6);
    fn_print(fn_format("oudream.reverse.return = %d !", r6));
    int r7 = solution.reverse(n7);
    fn_print(fn_format("oudream.reverse.return = %d !", r7));
    return TRUE;
}
int fn_test_reverse1 = fn_add_case("reverse1", test_reverse1);
