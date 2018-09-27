#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    bool isPalindrome(int x)
    {
    };
};

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        // do:x<10
//        if (x < 10)
//        {
//            return true;
//        }
        int rev = 0;
        while (rev < x)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        // do:x<10
        return x == rev || x == rev / 10;
    }
};

int test_isPalindrome1(int argc, const char *argv[])
{
    int n1 = 0;
    int n2 = -1;
    int n3 = 9;
    int n4 = 10;
    int n5 = 121;
    int n6 = 125521;
    int n7 = 123;

    // oudream
    Solution solution;
    bool r1 = solution.isPalindrome(n1);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r1));
    bool r2 = solution.isPalindrome(n2);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r2));
    bool r3 = solution.isPalindrome(n3);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r3));
    bool r4 = solution.isPalindrome(n4);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r4));
    bool r5 = solution.isPalindrome(n5);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r5));
    bool r6 = solution.isPalindrome(n6);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r6));
    bool r7 = solution.isPalindrome(n7);
    fn_print(fn_format("oudream.isPalindrome.return = %d !", r7));
    return TRUE;
}
int fn_test_isPalindrome1 = fn_add_case("isPalindrome1", test_isPalindrome1);
