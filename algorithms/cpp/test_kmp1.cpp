#include "global.h"
#define N 100

using namespace std;


int fn_add_case(const std::string & sCaseName , fn_case_t fn)
{
    return TRUE;
}

int iCount = 0;

void cal_next( char * str, int * next, int len ) {
    int i, j;
    next[0] = -1;
    for( i = 1; i < len; i++ )
    {
        j = next[ i - 1 ];
        while( str[ j + 1 ] != str[ i ] && ( j >= 0 ) )
            j = next[ j ];
        if( str[ i ] == str[ j + 1 ] )
            next[ i ] = j + 1;
        else
            next[ i ] = -1;
    }
}
int KMP( char * str, int slen, char * ptr, int plen, int * next ) {
    int s_i = 0, p_i = 0;

    iCount = 0;

    while( s_i < slen && p_i < plen )
    {
        ++iCount;
        if( str[ s_i ] == ptr[ p_i ] )
        {
            s_i++;
            p_i++;
        }
        else
        {
            if( p_i == 0 )
                s_i++;
            else
                p_i = next[ p_i - 1 ] + 1;
        }
    }
    return ( p_i == plen ) ? ( s_i - plen ) : -1;
}


int main(int argc, const char * argv[])
{
    char str[ N ] = {0};
    char ptr[ N ] = {0};
    int slen, plen;
    int next[ N ];

    char * pc = "";
    char * pm = "";

    pc = "bebebeaboy";
    pm = "aabbaabbeeffaabbaabb";
    memcpy(str, pc, strlen(pc));
    memcpy(ptr, pm, strlen(pm));
    slen = strlen( str );
    plen = strlen( ptr );
    cal_next( ptr, next, plen );
    printf( "%d\n", KMP( str, slen, ptr, plen, next ) );
    printf( "iCount = %d\n", iCount );

    pc = "abcadefgabcadefabcadeabcadabcadeaba12345";
    pm = "cadeaba1";
    memcpy(str, pc, strlen(pc));
    memcpy(ptr, pm, strlen(pm));
    slen = strlen( str );
    plen = strlen( ptr );
    cal_next( ptr, next, plen );
    printf( "%d\n", KMP( str, slen, ptr, plen, next ) );
    printf( "iCount = %d\n", iCount );

    pc = "abcdefgabcdefabcdeabcdabcaba12345";
    pm = "a1234";
    memcpy(str, pc, strlen(pc));
    memcpy(ptr, pm, strlen(pm));
    slen = strlen( str );
    plen = strlen( ptr );
    cal_next( ptr, next, plen );
    printf( "%d\n", KMP( str, slen, ptr, plen, next ) );
    printf( "iCount = %d\n", iCount );

    while( scanf( "%s%s", str, ptr ) )
    {
        slen = strlen( str );
        plen = strlen( ptr );
        cal_next( ptr, next, plen );
        printf( "%d\n", KMP( str, slen, ptr, plen, next ) );
        printf( "iCount = %d\n", iCount );
    }
    return 0;
}
