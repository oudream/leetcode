#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    string convert(string s, int nRows)
    {
        if (nRows == 1) return s;

        vector<string> rows(min(nRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == nRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }

};

class SolutionLeetcode2 {
public:
    // 按照与逐行读取 Z 字形图案相同的顺序访问字符串。
    string convert(string s, int nRows)
    {
        if (nRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * nRows - 2;

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                ret += s[j + i];
                if (i != 0 && i != nRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }

};

class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int iCycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += iCycleLen)
            {
                // rowBegin rowEnd rowMid.First
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + iCycleLen - i < n)
                    // rowMid.Second
                    ret += s[j + iCycleLen - i];
            }
        }
        return ret;
    }

};

int zigzag_conversion1(int argc, const char *argv[])
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;

    // Leetcode
    SolutionLeetcode solutionLeetcode;
    string r = solutionLeetcode.convert("PAYPALISHIRING", 3);
    fn_print(fn_format("Leetcode.convert.return=%s !", r.c_str()));

    // Leetcode
    SolutionLeetcode2 solutionLeetcode2;
    string r2 = solutionLeetcode2.convert("PAYPALISHIRING", 3);
    fn_print(fn_format("Leetcode2.convert.return=%s !", r.c_str()));

    // oudream
    Solution solution;
    string r3 = solution.convert("PAYPALISHIRING", 3);
    fn_print(fn_format("oudream.convert.return=%s !", r3.c_str()));
    return TRUE;
}
int fn_zigzag_conversion1 = fn_add_case("convert1", zigzag_conversion1);
