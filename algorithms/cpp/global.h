
#ifndef PROJECT_GLOBAL_H
#define PROJECT_GLOBAL_H

#include <stddef.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <signal.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include <typeinfo>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#ifndef    TRUE
#define    TRUE    1
#endif
#ifndef    FALSE
#define    FALSE 0
#endif
#ifndef    NULL
#define	   NULL 0
#endif

typedef int (*fn_case_t)(int argc, const char * argv[]);

extern int fn_add_case(const std::string & sCaseName , fn_case_t fn);

extern void fn_print(const std::string & sMsg);

extern std::string fn_input();

extern std::string fn_format(const char * sFormat, ...);

extern void fn_test_vector21();

#endif //PROJECT_GLOBAL_H
