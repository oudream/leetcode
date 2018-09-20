
#include "global.h"

using namespace std;

void fn_print(const std::string & sMsg)
{
    std::cout << sMsg << std::endl;
}

std::string fn_input()
{
    std::string msg;
    std::cin >> msg;
    return msg;
}

string fn_format(const char *sFormat, ...)
{
    char buffer[4096];
    va_list args;
    va_start (args, sFormat);
// vsprintf (buffer, sFormat, args); // risk, todo
    vsnprintf(buffer, sizeof(buffer), sFormat, args);
//    perror (buffer);
    va_end (args);
    return buffer;
}

void fn_test_vector21()
{
    std::string str;
    do
    {
        str = fn_input();

        if (str[0] == 'C')
        {
            if (str[1] == 'B')
            {
                if (str[2] == '0')
                {

                }
            }
            else if (str[1] == 'E')
            {
            }
            else if (str[1] == 'T')
            {
            }
            else if (str[1] == 'R')
            {
            }
            else if (str[1] == 'C')
            {
                break;
            }
        }
        else
        {
        }
    } while (str != "CC");
}

