#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        return r;
    }
    
};

class Solution {
public:
//#define printf void ();

    int getIndex()
    {
        static int i = 0;
        return i++;
    }

    void g(vector<string> & ls, string s, int l, int r, int max)
    {
        int iIndex = getIndex();
        if (s.size() == max*2)
        {
            ls.push_back(s);
            printf("--%d-- : ls.push [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            return;
        }
        if (l < max)
        {
            printf("--%d-- : l -> g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            g(ls, s + "(", l+1, r, max);
            printf("--%d-- : l <- g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
//            if (iIndex == 11)
//            {
//                printf("debug");
//            }
        }
//        if (r < max)
        // import import import
        // import import import
        // import import import
        if (r < l) // import import import
        {
            printf("--%d-- : r -> g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            g(ls, s + ")", l, r+1, max);
            printf("--%d-- : r <- g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
        }
    }

    void gAll(vector<string> & ls, string s, int l, int r, int max)
    {
        int iIndex = getIndex();
        if (s.size() == max*2)
        {
            ls.push_back(s);
            printf("--%d-- : ls.push [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            return;
        }
//        if (l < max)
        {
            printf("--%d-- : l -> g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            gAll(ls, s + "(", l+1, r, max);
            printf("--%d-- : l <- g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
//            if (iIndex == 11)
//            {
//                printf("debug");
//            }
        }
//        if (r < max)
        // import import import
        // import import import
        // import import import
//        if (r < l) // import import import
        {
            printf("--%d-- : r -> g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
            gAll(ls, s + ")", l, r+1, max);
            printf("--%d-- : r <- g [%d , %d, %s] %d \n", iIndex, l, r, s.c_str(), ls.size());
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> r;
//        g(r, "", 0, 0, n);
        gAll(r, "", 0, 0, n);
        return r;
    }

};

int test_generateParenthesis1(int argc, const char *argv[])
{
    Solution solution;

    vector<string> ls = solution.generateParenthesis(3);
    fn_print(fn_format("oudream.generateParenthesis count: %d",ls.size()));
    for (int i = 0; i < ls.size(); ++i)
    {
        const string & s = ls.at(i);
        fn_print(fn_format("%s",s.c_str()));
    }
    return TRUE;
}
int fn_test_generateParenthesis1 = fn_add_case("generateParenthesis1", test_generateParenthesis1);
