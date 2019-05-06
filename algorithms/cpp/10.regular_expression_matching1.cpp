#include "global.h"

using namespace std;

class Solution {
public :
    bool isMatch1(string s, string p)
    {
        int m = s.length(),n = p.length();
//        bool dp[m+1][n+1];
        bool dp[9+1][9+1];
        dp[s.size()][p.size()] = true;

        for (int i = s.size(); i >= 0; i--)
        {
            for (int j = p.size() - 1; j >= 0; j--)
            {
                bool first_match = (i < s.size() &&
                                       (p[j] == s[i] ||
                                        p[j] == '.'));
                if (j + 1 < p.size() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }

    bool isMatch(string s, string p)
    {
        int m = s.length(),n = p.length();
        bool dp[9+1][9+1];
        dp[0][0] = true; //初始化第0行,除了[0][0]全为false，毋庸置疑，因为空串p只能匹配空串，其他都无能匹配
        for (int i = 1; i <= m; i++)
            dp[i][0] = false; //初始化第0列，只有X*能匹配空串，如果有*，它的真值一定和p[0][j-2]的相同（略过它之前的符号）
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];

                }
                else   //只有当前字符完全匹配，才有资格传递dp[i-1][j-1] 真值
                {
                    dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];

                }
            }
        }
        return dp[m][n];
    }


};

int isMatch1(int argc, const char *argv[])
{
    int target = 9;

    Solution solution;
    string s;
    string p;
    bool r;
    s = "bbab";
    p = "b*a*";
    r = solution.isMatch(s, p);
    fn_print(fn_format("Leetcode.isMatch(\"%s\", \"%s\")[1].return=%d !", s.c_str(), p.c_str(), r));

    s = "bbab";
    p = "b*a*b";
    r = solution.isMatch(s, p);
    fn_print(fn_format("Leetcode.isMatch(\"%s\", \"%s\")[1].return=%d !", s.c_str(), p.c_str(), r));

    s = "bcade";
    p = "b.ad*e";
    r = solution.isMatch(s, p);
    fn_print(fn_format("Leetcode.isMatch(\"%s\", \"%s\")[1].return=%d !", s.c_str(), p.c_str(), r));

    return TRUE;
}
int fn_isMatch1 = fn_add_case("isMatch1", isMatch1);
