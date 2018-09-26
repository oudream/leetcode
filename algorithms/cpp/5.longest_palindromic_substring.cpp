#include "global.h"

using namespace std;

class SolutionHaoel {
public:
    string longestPalindrome(string s)
    {
        return string();
    }

};

class Solution {
private:
    char s[200001];
    char str[400008];
    int p[400008];

    int min(int a, int b)
    {
        return a < b ? a : b;
    }

    int pre()
    {
        int i, j = 0;
        str[j++] = '$';//加入字符串首部的字符串
        for (i = 0; s[i]; i++)
        {
            str[j++] = '#';  //分隔符
            str[j++] = s[i];
        }
        str[j++] = '#';
        str[j] = '\0';  //尾部加'\0'
        cout << str << endl;
        return j;
    }

    void manacher(int n)
    {
        int mx = 0, id, i;
        p[0] = 0;
        for (i = 1; i < n; i++)
        {
            if (mx > i)  //在这个之类可以借助前面算的一部分
                p[i] = min(mx - i, p[2 * id - i]); //p[2*id-i]表示j处的回文长度
            else  //如果i大于mx，则必须重新自己算
                p[i] = 1;
            while (str[i - p[i]] == str[i + p[i]])  //算出回文字符串的半径
                p[i]++;
            if (p[i] + i > mx)
            {  //记录目前回文字符串扩展最长的id
                mx = p[i] + i;
                id = i;
            }
        }
        int k = 0;
    }

public:
    Solution()
    {
        memset(s, 0, sizeof(s) / sizeof(char));
        memset(str, 0, sizeof(str) / sizeof(char));
        memset(p, 0, sizeof(p) / sizeof(int));
    }

    string longestPalindrome(string str)
    {
        memcpy(s, str.c_str(), str.size()+1);
        int n = pre();
        manacher(n);
        int pos = 0, ans = 0, i;
        for (i = 1; i < n; i++)
        {
            if (p[i] >= ans)
            {
                pos = i;
                ans = p[i];
            }
        }
        int iSize = ans - 1;
        int iPos = (pos - ans) / 2;
        return string(str.c_str() + iPos, iSize);
    }

};

class SolutionLeetcode {
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end + 1 - start);
    }

    int expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }

};

int test_longestPalindrome1(int argc, const char *argv[])
{
    // haoel
    SolutionHaoel solutionHaoel;

    // leetcode
    SolutionLeetcode solutionLeetcode;
    string r2 = solutionLeetcode.longestPalindrome("12343215123436634321575157");
    fn_print(fn_format("leetcode.longestPalindrome.return=%s !", r2.c_str()));

    // oudream
    Solution solution;
    string r = solution.longestPalindrome("12343215123436634321575157");
    fn_print(fn_format("oudream.longestPalindrome.return=%s !", r.c_str()));

    return TRUE;
}
int fn_test_longestPalindrome1 = fn_add_case("longestPalindrome1", test_longestPalindrome1);

int test_longestPalindrome2(int argc, const char *argv[])
{
    // haoel
    SolutionHaoel solutionHaoel;

    // leetcode
    SolutionLeetcode solutionLeetcode;
    string r2 = solutionLeetcode.longestPalindrome("babad");
    fn_print(fn_format("leetcode.longestPalindrome.return=%s !", r2.c_str()));

    // oudream
    Solution solution;
    string r = solution.longestPalindrome("babad");
    fn_print(fn_format("oudream.longestPalindrome.return=%s !", r.c_str()));

    return TRUE;
}
int fn_test_longestPalindrome2 = fn_add_case("longestPalindrome2", test_longestPalindrome2);
