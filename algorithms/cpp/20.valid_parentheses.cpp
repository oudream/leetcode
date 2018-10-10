#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    bool isValid(string s)
    {

    }
};

class Solution {
public:
    bool isValid(string s)
    {
        const unsigned char CL = '~';

        unsigned char mappings[256];
        memset(mappings, 0, sizeof(mappings) / sizeof(char));
        mappings['('] = CL;
        mappings['{'] = CL;
        mappings['['] = CL;
        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';

        // Initialize a stack to be used in the algorithm.
        stack<unsigned char> st;

        for (size_t i = 0; i < s.size(); i++)
        {
            unsigned char c = s[i];
            unsigned char h = mappings[c];
            if (h)
            {
                if (h == CL)
                {
                    // If it was an opening bracket, push to the stack.
                    st.push(c);
                }
                else // If the current character is a closing bracket.
                {
                    // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
                    char topElement = st.empty() ? '#' : st.top();

                    // If the mapping for this bracket doesn't match the stack's top element, return false.
                    if (topElement != h)
                    {
                        return false;
                    }

                    st.pop();
                }
            }
        }

        // If the stack still contains elements, then it is an invalid expression.
        return st.empty();
    }

};

int test_validParentheses1(int argc, const char *argv[])
{
    Solution solution;

    string str1 = "((({(([]()))})))";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str1.c_str(), solution.isValid(str1)));
    string str2 = "()()()()";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str2.c_str(), solution.isValid(str2)));
    string str3 = "(((((((()";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str3.c_str(), solution.isValid(str3)));
    string str4 = "((()[()]))";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str4.c_str(), solution.isValid(str4)));
    string str5 = "(((a-b)[(adfasdfa) * 3]))";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str5.c_str(), solution.isValid(str5)));
    string str6 = "((()[(1+2]))";
    fn_print(fn_format("oudream.validParentheses('%s') = %d !",str6.c_str(), solution.isValid(str6)));
    return TRUE;
}
int fn_test_validParentheses1 = fn_add_case("validParentheses1", test_validParentheses1);
