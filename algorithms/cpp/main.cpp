//
// Created by oudream on 2018/9/20.
//

#include "global.h"

using namespace std;

map<string, fn_case_t> fn_cases;

int fn_add_case(const std::string & sCaseName , fn_case_t fn)
{
    fn_cases[sCaseName] = fn;
    return TRUE;
}

int main(int argc, const char * argv[])
{
    fn_print("Begin algorithms:");

    for (std::map<string, fn_case_t>::const_iterator it = fn_cases.begin(); it != fn_cases.end(); ++it)
    {
        const string & sCaseName = it->first;
        fn_case_t fn = it->second;
        fn_print(fn_format("Begin run case - [ %s ] :", sCaseName.c_str()));
        clock_t dtStart = clock();
        fn(argc, argv);
        clock_t dtEnd=clock();
        fn_print(fn_format("End run case - [ %s ], cost clock = %lld !", sCaseName.c_str(), dtEnd-dtStart));
    }

    fn_print("End algorithms.");
    return TRUE;
}
