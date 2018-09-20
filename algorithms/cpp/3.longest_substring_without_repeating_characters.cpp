
#include "global.h"

using namespace std;

class SolutionHaoel {
public:
    int lengthOfLongestSubstring1(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }

    //don't use <map>
    int lengthOfLongestSubstring(string s) {
        const int MAX_CHARS = 256;
        int m[MAX_CHARS];
        memset(m, -1, sizeof(m));

        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        const int MAX_CHARS = 256;
        int m[MAX_CHARS];
        memset(m, -1, sizeof(m));

        int iMaxLen = 0;
        int iLastRepeatPos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            unsigned char c = s[i];
            if (m[c]!=-1 && iLastRepeatPos < m[c]) {
                iLastRepeatPos = m[c];
            }
            if (i - iLastRepeatPos > iMaxLen)
            {
                iMaxLen = i - iLastRepeatPos;
            }
            m[c] = i;
        }
        return iMaxLen;
    }
};


//Example 1:
//
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
int test_lengthOfLongestSubstring1(int argc, const char * argv[])
{
    string sInput = "abcabcbb";
    int iMax = 0;
    // oudream
    Solution solution;
    iMax = solution.lengthOfLongestSubstring(sInput);
    fn_print(fn_format("oudream.lengthOfLongestSubstring.return : %d", iMax));
    return TRUE;
}
int fn_test_lengthOfLongestSubstring1 = fn_add_case("lengthOfLongestSubstring1", test_lengthOfLongestSubstring1);


//Example 2:
//
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
int test_lengthOfLongestSubstring2(int argc, const char * argv[])
{
    string sInput = "bbbbb";
    int iMax = 0;
    // oudream
    Solution solution;
    iMax = solution.lengthOfLongestSubstring(sInput);
    fn_print(fn_format("oudream.lengthOfLongestSubstring.return : %d", iMax));
    return TRUE;
}
int fn_test_lengthOfLongestSubstring2 = fn_add_case("lengthOfLongestSubstring2", test_lengthOfLongestSubstring2);

//Example 3:
//
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
int test_lengthOfLongestSubstring3(int argc, const char * argv[])
{
    string sInput = "pwwkew";
    int iMax = 0;
    // oudream
    Solution solution;
    iMax = solution.lengthOfLongestSubstring(sInput);
    fn_print(fn_format("oudream.lengthOfLongestSubstring.return : %d", iMax));
    return TRUE;
}
int fn_test_lengthOfLongestSubstring3 = fn_add_case("lengthOfLongestSubstring3", test_lengthOfLongestSubstring3);

//Example 4:
//
//Input: "pwabcwkabcdewusfiuopyzodabcefg"
//Output: 4
//Explanation: The answer is "wke", with the length of 4.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
int test_lengthOfLongestSubstring4(int argc, const char * argv[])
{
    string sInput = "pwabcwkabcdewusfiuopyzodabcefg";
    int iMax = 0;
    // haoel
    SolutionHaoel solutionHaoel;
    iMax = solutionHaoel.lengthOfLongestSubstring(sInput);
    fn_print(fn_format("haoel.lengthOfLongestSubstring.return : %d", iMax));
    // oudream
    Solution solution;
    iMax = solution.lengthOfLongestSubstring(sInput);
    fn_print(fn_format("oudream.lengthOfLongestSubstring.return : %d", iMax));
    return TRUE;
}
int fn_test_lengthOfLongestSubstring4 = fn_add_case("lengthOfLongestSubstring4", test_lengthOfLongestSubstring4);

