#include "global.h"

using namespace std;

int fn_add_case(const std::string & sCaseName , fn_case_t fn)
{
    return TRUE;
}

#ifndef NOT_EXIST
#define NOT_EXIST (-1)
#endif

typedef struct {
    char**  seq;
    int*    code;
    int     size;
    int     max_size;
} Dictionary;

void insert_seq(Dictionary *dict, char *seq) {
    int i = dict->size;
    dict->seq[i] = (char*) (malloc(sizeof(char) * strlen(seq) + 1));
    dict->code[i] = i;
    dict->size++;
    strcpy(dict->seq[i], seq);
}

void init_dictionary(Dictionary* dict, int max_size) {
    dict->max_size = max_size;
    dict->size  = 0;
    dict->seq   = (char**) (malloc(sizeof(char*) * max_size));
    dict->code  = (int*) (malloc(sizeof(int) * max_size));

    insert_seq(dict, "#");
    char seq[2] = " ";
    for (int i = 0; i < 0x7F-' '; i++)
    {
        insert_seq(dict, seq);
        seq[0]++;
    }
}

void print_dictionary(Dictionary *dict) {
    printf("=====================\n");
    printf(" Code       Sequence\n");
    printf("=====================\n");
    for (int i = 0; i < dict->size; i++)
    {
        printf("%5d%7c", dict->code[i], ' ');
        printf("%s\n", dict->seq[i]);
    }
    printf("=====================\n");
}

int get_seq_code(Dictionary* dict, char* seq) {
    for (int i = 0; i < dict->size; i++)
    {
        if (strcmp(dict->seq[i], seq) == 0)
        {
            return dict->code[i];
        }
    }
    return NOT_EXIST;
}

void lzw_encode(char *text, Dictionary *dict)
{
    char current[1000];
    char next;
    int code;
    int i = 0;
    int iCount = 0;
    while (i < strlen(text))
    {
        ++iCount;
        sprintf(current, "%c", text[i]);
        next = text[i + 1];
        while (get_seq_code(dict, current) != NOT_EXIST)
        {
            sprintf(current, "%s%c", current, next);
            i++;
            next = text[i + 1];
        }
        current[strlen(current) - 1] = '\0';
        next = text[i];
        code = get_seq_code(dict, current);
        sprintf(current, "%s%c", current, next);
        insert_seq(dict, current);

        printf("%d %s\n", code, current);
    }
    printf("iCount=%d\n", iCount);
}

int main(int argc, const char * argv[])
{
    Dictionary dict;
    init_dictionary(&dict, 10000);
    print_dictionary(&dict);

//    lzw_encode("TOBEORNOTTOBEORTOBEORNOT", &dict);
    char s[] = "src=\"https://img3.doubanio.com/f/shire/72ced6df41d4d158420cebdd254f9562942464e3/js/jquery.min."\
               "\"https://img3.doubanio.com/f/shire/f010949d3f23dd7c972ad7cb40b800bf70723c93/js/douban."\
               "href=\"https://img3.doubanio.com/f/whitehole/d5b044b6e5cd8691f9c4a149edf21aa15bc58db5/css/topic.css\" rel=\"stylesheet\"/>\\n  <script type=\"text/javascript\" src=\"https://img3.doubanio.com/f/shire/77323ae72a612bba8b65f845491513ff3329b1bb/js/do.js\" data-cfg-autoload=\"false\"></script>\\n\\n    <style type=\"text/css\">\\n    .mod {\\n      width: auto;\\n      border: none;\\n      border-top: 1px dashed #E8E8E8;\\n      padding: 0;\\n      margin-top: 10px;\\n      box-shadow: none;\\n    }\\n    .mod dl,\\n    .mod .note-item,\\n    .mod .album-item {\\n        padding: 20px 0;\\n        margin: 0;\\n        border-bottom: 1px dashed #E8E8E8;\\n    }\\n    .album-item .meta,\\n    .note-item .meta {\\n        margin-top: 10px;\\n    }\\n  </style>\\n    <script></script>\\n\\n    <link rel=\"shortcut icon\" href=\"https://img3.doubanio.com/favicon.ico\" type=\"image/x-icon\">\\n</head>\\n\\n<body>\\n  \\n    <script type=\"text/javascript\">var _body_start = new Date();</script>\\n    \\n   \\n\\n\\n\\n    <link href=\"//img3.doubanio.com/dae/accounts/resources/984c231/shire/bundle.css\" rel=\"stylesheet\" type=\"text/css\">\\n\\n\\n\\n<div id=\"db-global-nav\" class=\"global-nav\">\\n  <div class=\"bd\">\\n    \\n<div class=\"top-nav-info\">\\n  <a href=\"https://www.douban.com/accounts/login?source=main\" class=\"nav-login\" rel=\"nofollow\">\\xe7\\x99\\xbb\\xe5\\xbd\\x95</a>\\n  <a href=\"https://www.douban.com/accounts/register?source=main\" class=\"nav-register\" rel=\"nofollow\">\\xe6\\xb3\\xa8\\xe5\\x86\\x8c</a>\\n</div>\\n\\n\\n    <div class=\"top-nav-doubanapp\">\\n  <a href=\"https://www.douban.com/doubanapp/app?channel=top-nav\" class=\"lnk-doubanapp\">\\xe4\\xb8\\x8b\\xe8\\xbd\\xbd\\xe8\\xb1\\x86\\xe7\\x93\\xa3\\xe5\\xae\\xa2\\xe6\\x88\\xb7\\xe7\\xab\\xaf</a>\\n  <div id=\"doubanapp-tip\">\\n    <a href=\"https://www.douban.com/doubanapp/app?channel=qipao\" class=\"tip-link\">\\xe8\\xb1\\x86\\xe7\\x93\\xa3 <span class=\"version\">6.0</span> \\xe5\\x85\\xa8\\xe6\\x96\\xb0\\xe5\\x8f\\x91\\xe5\\xb8\\x83</a>\\n    <a href=\"javascript: void 0;\" class=\"tip-close\">\\xc3\\x97</a>\\n  </div>\\n  <div id=\"top-nav-appintro\" class=\"more-items\">\\n    <p class=\"appintro-title\">\\xe8\\xb1\\x86\\xe7\\x93\\xa3</p>\\n    <p class=\"qrcode\">\\xe6\\x89\\xab\\xe7\\xa0\\x81\\xe7\\x9b\\xb4\\xe6\\x8e\\xa5\\xe4\\xb8\\x8b\\xe8\\xbd\\xbd</p>\\n    <div class=\"download\">\\n      <a href=\"https://www.douban.com/doubanapp/redirect?channel=top-nav&direct_dl=1&download=iOS\">iPhone</a>\\n      <span>\\xc2\\xb7</span>\\n      <a href=\"https://www.douban.com/doubanapp/redirect?channel=top-nav&direct_dl=1&download=Android\" class=\"download-android\">Android</a>\\n    </div>\\n  </div>\\n</div>\\n\\n    \\n\\n\\n<div class=\"global-nav-items\">\\n  <ul>\\n    <li class=\"on\">\\n      <a href=\"https://www.douban.com\"  data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-main&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe8\\xb1\\x86\\xe7\\x93\\xa3</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://book.douban.com\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-book&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe8\\xaf\\xbb\\xe4\\xb9\\xa6</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://movie.douban.com\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-movie&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe7\\x94\\xb5\\xe5\\xbd\\xb1</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://music.douban.com\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-music&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe9\\x9f\\xb3\\xe4\\xb9\\x90</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://www.douban.com/location\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-location&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe5\\x90\\x8c\\xe5\\x9f\\x8e</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://www.douban.com/group\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-group&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe5\\xb0\\x8f\\xe7\\xbb\\x84</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://read.douban.com&#47;?dcs=top-nav&amp;dcm=douban\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-read&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe9\\x98\\x85\\xe8\\xaf\\xbb</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://douban.fm&#47;?from_=shire_top_nav\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-fm&quot;,&quot;uid&quot;:&quot;0&quot;}\">FM</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://time.douban.com&#47;?dt_time_source=douban-web_top_nav\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-time&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe6\\x97\\xb6\\xe9\\x97\\xb4</a>\\n    </li>\\n    <li class=\"\">\\n      <a href=\"https://market.douban.com&#47;?utm_campaign=douban_top_nav&amp;utm_source=douban&amp;utm_medium=pc_web\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-market&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe8\\xb1\\x86\\xe5\\x93\\x81</a>\\n    </li>\\n    <li>\\n      <a href=\"#more\" class=\"bn-more\"><span>\\xe6\\x9b\\xb4\\xe5\\xa4\\x9a</span></a>\\n      <div class=\"more-items\">\\n        <table cellpadding=\"0\" cellspacing=\"0\">\\n          <tbody>\\n            <tr>\\n              <td>\\n                <a href=\"https://ypy.douban.com\" target=\"_blank\" data-moreurl-dict=\"{&quot;from&quot;:&quot;top-nav-click-ypy&quot;,&quot;uid&quot;:&quot;0&quot;}\">\\xe8\\xb1\\x86\\xe7\\x93\\xa3\\xe6\\x91\\x84\\xe5\\xbd\\xb1</a>\\n              </td>\\n            </tr>\\n          </tbody>\\n        </table>\\n      </div>\\n    </li>\\n  </ul>\\n</div>\\n\\n  </div>\\n</div>\\n<script>\\n  ;window._GLOBAL_NAV = {\\n    DOUBAN_URL: \"https://www.douban.com\",\\n    N_NEW_NOTIS: 0,\\n    N_NEW_DOUMAIL: 0\\n  };\\n</script>\\n\\n\\n\\n    <script src=\"//img3.doubanio.com/dae/accounts/resources/984c231/shire/bundle.js\" defer=\"defer\"></script>\\n\\n\\n\\n\\n      \\n    \\n\\n\\n\\n    <link href=\"//img3.doubanio.com/dae/accounts/resources/321e246/sns/bundle.css\" rel=\"stylesheet\" type=\"text/css\">\\n\\n\\n\\n<div id=\"db-nav-sns\" class=\"nav\">\\n  <div class=\"nav-wrap\">\\n    <div class=\"nav-primary\">\\n     \\n      <div class=\"nav-logo\">\\n        <a href=\"https://www.douban.com\">\\xe8\\xb1\\x86\\xe7\\x93\\xa3\\xe7\\xa4\\xbe\\xe5\\x8c\\xba</a>\\n      </div>\\n\\n      <div class=\"nav-search\">\\n  <form action=\"https://www.douban.com/search\" method=\"get\">\\n\\t<fieldset>\\n      <legend>\\xe6\\x90\\x9c\\xe7\\xb4\\xa2\\xef\\xbc\\x9a</legend>\\n\\t  <label for=\"inp-query\">\\xe6\\x90\\x9c\\xe7\\xb4\\xa2\\xe4\\xbd\\xa0\\xe6\\x84\\x9f\\xe5\\x85\\xb4\\xe8\\xb6\\xa3\\xe7\\x9a\\x84\\xe5\\x86\\x85\\xe5\\xae\\xb9\\xe5\\x92\\x8c\\xe4\\xba\\xba...</label>\\n\\t  <div class=\"inp\">\\n\\t    <input type=\"hidden\" name=\"source\" value=\"suggest\">\\n\\t\\t<input id=\"inp-query\" name=\"q\" size=\"22\" maxlength=\"60\" autocomplete=\"off\" value=\"\">\\n\\t  </div>\\n\\t  <div class=\"inp-btn\"><input type=\"submit\" value=\"\\xe6\\x90\\x9c\\xe7\\xb4\\xa2\"></div>\\n\\t</fieldset>\\n  </form>\\n</div>\\n\\n      \\n\\n<div class=\"nav-items\">\\n  <ul>\\n    <li><a href=\"https://www.douban.com\">\\xe9\\xa6\\x96\\xe9\\xa1\\xb5</a></li>\\n      <li>\\n        <a href=\"https://www.douban.com/explore\">\\n          \\xe6\\xb5\\x8f\\xe8\\xa7\\x88\\xe5\\x8f\\x91\\xe7\\x8e\\xb0\\n        </a>\\n      </li>\\n      <li>\\n        <a href=\"https://www.douban.com/gallery\">\\n          \\xe8\\xaf\\x9d\\xe9\\xa2\\x98\\xe5\\xb9\\xbf\\xe5\\x9c\\xba\\n          <img src=\"https://img3.doubanio.com/f/shire/e49eca1517424a941871a2667a8957fd6c72d632/pics/new_menu.gif\" alt=\"new\" style=\"position: absolute; top: -7px; right: -13px;\" />\\n        </a>\\n      </li>\\n  </ul>\\n</div>\\n\\n    </div>\\n  </div>\\n</div>\\n\\n\\n\\n    <script src=\"//img3.doubanio.com/dae/accounts/resources/321e246/sns/bundle.js\" defer=\"defer\"></script>\\n\\n\\n\\n\\n\\n\\n    <div id=\"wrapper\">\\n        \\n\\n        \\n<div id=\"content\">\\n    \\n    <h1>\\xe5\\x85\\xb3\\xe4\\xba\\x8e\\xe4\\xb8\\xaa\\xe4\\xba\\xba\\xe7\\xae\\xa1\\xe7\\x90\\x86\\xe7\\x9a\\x84\\xe4\\xb9\\xa6 (\\xe8\\xb1\\x86\\xe7\\x93\\xa3)</h1>\\n\\n    <div class=\"grid-16-8 clearfix\">\\n        \\n        \\n        <div class=\"article\">\\n               \\n  \\n\\n    <div class=\"mod book-list\">\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/25747597/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s27094272.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/25747597/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe4\\xb8\\x8d\\xe8\\x83\\xbd\\xe4\\xb8\\x8d\\xe5\\x8e\\xbb\\xe7\\x88\\xb1\\xe7\\x9a\\x84\\xe4\\xb8\\xa4\\xe4\\xbb\\xb6\\xe4\\xba\\x8b</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe6\\x97\\xa5]\\xe6\\x9d\\xbe\\xe6\\xb5\\xa6\\xe5\\xbc\\xa5\\xe5\\xa4\\xaa\\xe9\\x83\\x8e / \\xe5\\xbc\\xa0\\xe5\\xaf\\x8c\\xe7\\x8e\\xb2 / \\xe6\\xb5\\xa6\\xe7\\x9d\\xbf\\xe6\\x96\\x87\\xe5\\x8c\\x96\\xc2\\xb7\\xe6\\xb9\\x96\\xe5\\x8d\\x97\\xe4\\xba\\xba\\xe6\\xb0\\x91\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2013-11 / 32.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar35\"></span>\\n          <span class=\"rating_nums\">7.3</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/1775691/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s2144391.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/1775691/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe5\\xb0\\x91\\xe6\\x9c\\x89\\xe4\\xba\\xba\\xe8\\xb5\\xb0\\xe7\\x9a\\x84\\xe8\\xb7\\xaf</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] M\\xc2\\xb7\\xe6\\x96\\xaf\\xe7\\xa7\\x91\\xe7\\x89\\xb9\\xc2\\xb7\\xe6\\xb4\\xbe\\xe5\\x85\\x8b / \\xe4\\xba\\x8e\\xe6\\xb5\\xb7\\xe7\\x94\\x9f / \\xe5\\x90\\x89\\xe6\\x9e\\x97\\xe6\\x96\\x87\\xe5\\x8f\\xb2\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2007-1 / 26.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.4</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/1013208/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img1.doubanio.com/view/subject/l/public/s1670978.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/1013208/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe5\\xa6\\x82\\xe4\\xbd\\x95\\xe9\\x98\\x85\\xe8\\xaf\\xbb\\xe4\\xb8\\x80\\xe6\\x9c\\xac\\xe4\\xb9\\xa6</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe8\\x8e\\xab\\xe6\\x8f\\x90\\xe9\\xbb\\x98\\xc2\\xb7J. \\xe8\\x89\\xbe\\xe5\\xbe\\xb7\\xe5\\x8b\\x92 / \\xe6\\x9f\\xa5\\xe5\\xb0\\x94\\xe6\\x96\\xaf\\xc2\\xb7\\xe8\\x8c\\x83\\xe5\\xa4\\x9a\\xe4\\xbc\\xa6 / \\xe9\\x83\\x9d\\xe6\\x98\\x8e\\xe4\\xb9\\x89 / \\xe6\\x9c\\xb1\\xe8\\xa1\\xa3 / \\xe5\\x95\\x86\\xe5\\x8a\\xa1\\xe5\\x8d\\xb0\\xe4\\xb9\\xa6\\xe9\\xa6\\x86 / 2004-1 / 38.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.4</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/3533221/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img1.doubanio.com/view/subject/l/public/s9346487.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/3533221/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe9\\x9d\\x9e\\xe6\\x9a\\xb4\\xe5\\x8a\\x9b\\xe6\\xb2\\x9f\\xe9\\x80\\x9a</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe9\\xa9\\xac\\xe6\\xad\\x87\\xe5\\xb0\\x94\\xc2\\xb7\\xe5\\x8d\\xa2\\xe6\\xa3\\xae\\xe5\\xa0\\xa1 / \\xe9\\x98\\xae\\xe8\\x83\\xa4\\xe5\\x8d\\x8e / \\xe5\\x8d\\x8e\\xe5\\xa4\\x8f\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2009-1 / 29.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar45\"></span>\\n          <span class=\"rating_nums\">8.5</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/27608239/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s29643861.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/27608239/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe5\\x8e\\x9f\\xe5\\x88\\x99</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe7\\x91\\x9e\\xc2\\xb7\\xe8\\xbe\\xbe\\xe5\\x88\\xa9\\xe6\\xac\\xa7 / \\xe5\\x88\\x98\\xe6\\xb3\\xa2 / \\xe7\\xb6\\xa6\\xe7\\x9b\\xb8 / \\xe4\\xb8\\xad\\xe4\\xbf\\xa1\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2018-1 / CNY 98.00\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.4</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/10786473/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s10685385.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/10786473/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe8\\x87\\xaa\\xe6\\x8e\\xa7\\xe5\\x8a\\x9b</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e]  \\xe5\\x87\\xaf\\xe5\\x88\\xa9\\xc2\\xb7\\xe9\\xba\\xa6\\xe6\\xa0\\xbc\\xe5\\xb0\\xbc\\xe6\\xa0\\xbc\\xe5\\xb0\\x94 / \\xe7\\x8e\\x8b\\xe5\\xb2\\x91\\xe5\\x8d\\x89 / \\xe6\\x96\\x87\\xe5\\x8c\\x96\\xe5\\x8f\\x91\\xe5\\xb1\\x95\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe(\\xe5\\x8e\\x9f\\xe5\\x8d\\xb0\\xe5\\x88\\xb7\\xe5\\xb7\\xa5\\xe4\\xb8\\x9a\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe) / 2012-8 / 39.80\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.3</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/1786387/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s1657785.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/1786387/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe5\\xbd\\xb1\\xe5\\x93\\x8d\\xe5\\x8a\\x9b</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe7\\xbd\\x97\\xe4\\xbc\\xaf\\xe7\\x89\\xb9\\xc2\\xb7\\xe8\\xa5\\xbf\\xe5\\xa5\\xa5\\xe8\\xbf\\xaa\\xe5\\xb0\\xbc / \\xe9\\x99\\x88\\xe5\\x8f\\x99 / \\xe4\\xb8\\xad\\xe5\\x9b\\xbd\\xe4\\xba\\xba\\xe6\\xb0\\x91\\xe5\\xa4\\xa7\\xe5\\xad\\xa6\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2006-5 / 45.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar45\"></span>\\n          <span class=\"rating_nums\">8.6</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/30240074/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s29846566.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/30240074/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe6\\x88\\x91\\xe6\\xaf\\x8f\\xe5\\xa4\\xa9\\xe5\\x8f\\xaa\\xe5\\xb7\\xa5\\xe4\\xbd\\x9c3\\xe5\\xb0\\x8f\\xe6\\x97\\xb6</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe6\\x97\\xa5]\\xe6\\x8a\\xbc\\xe4\\xba\\x95\\xe5\\xae\\x88 / \\xe8\\xb0\\xa2\\xe6\\x89\\xbf\\xe7\\xbf\\xb0 / \\xe9\\xab\\x98\\xe8\\xa9\\xb9\\xe7\\x81\\xbf / \\xe5\\x90\\x8e\\xe6\\xb5\\xaa\\xe4\\xb8\\xa8\\xe5\\x9b\\x9b\\xe5\\xb7\\x9d\\xe4\\xba\\xba\\xe6\\xb0\\x91\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2018-10 / 49.80\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.0</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/26369699/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img1.doubanio.com/view/subject/l/public/s29237648.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/26369699/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe8\\xa2\\xab\\xe8\\xae\\xa8\\xe5\\x8e\\x8c\\xe7\\x9a\\x84\\xe5\\x8b\\x87\\xe6\\xb0\\x94</a>\\n        \\n      \\n      <div class=\"desc\">\\n        \\xe5\\xb2\\xb8\\xe8\\xa7\\x81\\xe4\\xb8\\x80\\xe9\\x83\\x8e / \\xe5\\x8f\\xa4\\xe8\\xb4\\xba\\xe5\\x8f\\xb2\\xe5\\x81\\xa5 / \\xe6\\xb8\\xa0\\xe6\\xb5\\xb7\\xe9\\x9c\\x9e / \\xe6\\x9c\\xba\\xe6\\xa2\\xb0\\xe5\\xb7\\xa5\\xe4\\xb8\\x9a\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2015-3-1 / 39.8\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar45\"></span>\\n          <span class=\"rating_nums\">8.5</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/1056295/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s27266511.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/1056295/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe4\\xba\\xba\\xe6\\x80\\xa7\\xe7\\x9a\\x84\\xe5\\xbc\\xb1\\xe7\\x82\\xb9\\xe5\\x85\\xa8\\xe9\\x9b\\x86</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe6\\x88\\xb4\\xe5\\xb0\\x94\\xc2\\xb7\\xe5\\x8d\\xa1\\xe8\\x80\\x90\\xe5\\x9f\\xba / \\xe8\\xa2\\x81\\xe7\\x8e\\xb2 / \\xe4\\xb8\\xad\\xe5\\x9b\\xbd\\xe5\\x8f\\x91\\xe5\\xb1\\x95\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2008-1 / 25.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.3</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/3609132/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s3778613.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/3609132/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe6\\x8a\\x8a\\xe6\\x97\\xb6\\xe9\\x97\\xb4\\xe5\\xbd\\x93\\xe4\\xbd\\x9c\\xe6\\x9c\\x8b\\xe5\\x8f\\x8b</a>\\n        \\n      \\n      <div class=\"desc\">\\n        \\xe6\\x9d\\x8e\\xe7\\xac\\x91\\xe6\\x9d\\xa5 / \\xe7\\x94\\xb5\\xe5\\xad\\x90\\xe5\\xb7\\xa5\\xe4\\xb8\\x9a\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2009-6 / 32.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar45\"></span>\\n          <span class=\"rating_nums\">8.5</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/30303991/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s29849450.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/30303991/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe8\\x87\\xaa\\xe6\\x88\\x91\\xe9\\xa9\\xb1\\xe5\\x8a\\xa8\\xe5\\xbf\\x83\\xe7\\x90\\x86\\xe5\\xad\\xa6</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe5\\x8f\\xb2\\xe8\\x92\\x82\\xe6\\x96\\x87\\xe2\\x80\\xa2\\xe8\\xb4\\x9d\\xe6\\xa0\\xbc\\xe6\\x8b\\x89\\xe6\\x96\\xaf / STEVEN BERGLAS / \\xe5\\xb7\\xa6\\xe5\\x80\\xa9 / \\xe5\\x90\\x8e\\xe6\\xb5\\xaa\\xe4\\xb8\\xa8\\xe6\\xb1\\x9f\\xe8\\xa5\\xbf\\xe4\\xba\\xba\\xe6\\xb0\\x91\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2018-9 / 42.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">7.8</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/1048007/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s1067863.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/1048007/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe9\\xab\\x98\\xe6\\x95\\x88\\xe8\\x83\\xbd\\xe4\\xba\\xba\\xe5\\xa3\\xab\\xe7\\x9a\\x84\\xe4\\xb8\\x83\\xe4\\xb8\\xaa\\xe4\\xb9\\xa0\\xe6\\x83\\xaf\\xef\\xbc\\x88\\xe7\\xb2\\xbe\\xe5\\x8d\\x8e\\xe7\\x89\\x88\\xef\\xbc\\x89</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe5\\x8f\\xb2\\xe8\\x92\\x82\\xe8\\x8a\\xac\\xc2\\xb7\\xe6\\x9f\\xaf\\xe7\\xbb\\xb4 / \\xe9\\xab\\x98\\xe6\\x96\\xb0\\xe5\\x8b\\x87 / \\xe7\\x8e\\x8b\\xe4\\xba\\xa6\\xe5\\x85\\xb5 / \\xe8\\x91\\x9b\\xe9\\x9b\\xaa\\xe8\\x95\\xbe / \\xe4\\xb8\\xad\\xe5\\x9b\\xbd\\xe9\\x9d\\x92\\xe5\\xb9\\xb4\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2011-6 / 29.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.2</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/10785583/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img1.doubanio.com/view/subject/l/public/s10345719.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/10785583/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe6\\x80\\x9d\\xe8\\x80\\x83\\xef\\xbc\\x8c\\xe5\\xbf\\xab\\xe4\\xb8\\x8e\\xe6\\x85\\xa2</a>\\n        \\n      \\n      <div class=\"desc\">\\n        [\\xe7\\xbe\\x8e] \\xe4\\xb8\\xb9\\xe5\\xb0\\xbc\\xe5\\xb0\\x94\\xc2\\xb7\\xe5\\x8d\\xa1\\xe5\\xb0\\xbc\\xe6\\x9b\\xbc / \\xe8\\x83\\xa1\\xe6\\x99\\x93\\xe5\\xa7\\xa3 / \\xe6\\x9d\\x8e\\xe7\\x88\\xb1\\xe6\\xb0\\x91 / \\xe4\\xbd\\x95\\xe6\\xa2\\xa6\\xe8\\x8e\\xb9 / \\xe4\\xb8\\xad\\xe4\\xbf\\xa1\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2012-7 / 69.00\\xe5\\x85\\x83\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar40\"></span>\\n          <span class=\"rating_nums\">8.2</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n          \\n  \\n  \\n  \\n  <dl>\\n    <dt>\\n      <a href=\"https://book.douban.com/subject/27094706/?from=tag_all\" target=\"_blank\">\\n        <img src=\"https://img3.doubanio.com/view/subject/l/public/s29500850.jpg\" />\\n      </a>\\n    </dt>\\n    <dd>\\n      <a href=\"https://book.douban.com/subject/27094706/?from=tag_all\" class=\"title\" target=\"_blank\">\\xe8\\xb4\\xa2\\xe5\\xaf\\x8c\\xe8\\x87\\xaa\\xe7\\x94\\xb1\\xe4\\xb9\\x8b\\xe8\\xb7\\xaf</a>\\n        \\n      \\n      <div class=\"desc\">\\n        \\xe6\\x9d\\x8e\\xe7\\xac\\x91\\xe6\\x9d\\xa5 / \\xe7\\x94\\xb5\\xe5\\xad\\x90\\xe5\\xb7\\xa5\\xe4\\xb8\\x9a\\xe5\\x87\\xba\\xe7\\x89\\x88\\xe7\\xa4\\xbe / 2017-8 / 79.00\\n      </div>\\n    \\n        <div class=\"rating\">\\n          <span class=\"allstar45\"></span>\\n          <span class=\"rating_nums\">8.9</span>\\n        </div>\\n    </dd>\\n  </dl>\\n\\n\\n\\n    </div>\\n\\n    \\n    \\n    \\n\\n    \\n        <div class=\"paginator\">\\n        <span class=\"prev\">\\n            &lt;\\xe5\\x89\\x8d\\xe9\\xa1\\xb5\\n        </span>\\n        \\n        \\n\\n                <span class=\"thispage\" data-total-page=\"9223372036854775807\">1</span>\\n                \\n            <a href=\"?start=15\" >2</a>\\n        \\n                \\n            <a href=\"?start=30\" >3</a>\\n        \\n                \\n            <a href=\"?start=45\" >4</a>\\n        \\n                \\n            <a href=\"?start=60\" >5</a>\\n        \\n                \\n            <a href=\"?start=75\" >6</a>\\n        \\n                \\n            <a href=\"?start=90\" >7</a>\\n        \\n                \\n            <a href=\"?start=105\" >8</a>\\n        \\n                \\n            <a href=\"?start=120\" >9</a>\\n        \\n            <span class=\"break\">...</span>\\n        <span class=\"next\">\\n            <link rel=\"next\" href=\"?start=15\"/>\\n            <a href=\"?start=15\" >\\xe5\\x90\\x8e\\xe9\\xa1\\xb5&gt;</a>\\n        </span>\\n\\n        </div>\\n\\n\\n\\n        </div>\\n        <div class=\"aside\">\\n                \\n  <p class=\"pl2\">&gt;&nbsp;<a href=\"https://www.douban.com/tag/%E4%B8%AA%E4%BA%BA%E7%AE%A1%E7%90%86/\">\\xe8\\xbf\\x94\\xe5\\x9b\\x9e \\xe4\\xb8\\xaa\\xe4\\xba\\xba\\xe7\\xae\\xa1\\xe7\\x90\\x86 \\xe6\\xa0\\x87\\xe7\\xad\\xbe</a></p>\\n\\n        </div>\\n        <div class=\"extra\">\\n            \\n        </div>\\n    </div>\\n</div>\\n\\n        \\n<div id=\"footer\">\\n    \\n<span id=\"icp\" class=\"fleft gray-link\">\\n    &copy; 2005\\xef\\xbc\\x8d2018 douban.com, all rights reserved \\xe5\\x8c\\x97\\xe4\\xba\\xac\\xe8\\xb1\\x86\\xe7\\xbd\\x91\\xe7\\xa7\\x91\\xe6\\x8a\\x80\\xe6\\x9c\\x89\\xe9\\x99\\x90\\xe5\\x85\\xac\\xe5\\x8f\\xb8\\n</span>\\n\\n<a href=\"https://www.douban.com/hnypt/variformcyst.py\" style=\"display: none;\"></a>\\n\\n<span class=\"fright\">\\n    <a href=\"https://www.douban.com/about\">\\xe5\\x85\\xb3\\xe4\\xba\\x8e\\xe8\\xb1\\x86\\xe7\\x93\\xa3</a>\\n    \\xc2\\xb7 <a href=\"https://www.douban.com/jobs\">\\xe5\\x9c\\xa8\\xe8\\xb1\\x86\\xe7\\x93\\xa3\\xe5\\xb7\\xa5\\xe4\\xbd\\x9c</a>\\n    \\xc2\\xb7 <a href=\"https://www.douban.com/about?topic=contactus\">\\xe8\\x81\\x94\\xe7\\xb3\\xbb\\xe6\\x88\\x91\\xe4\\xbb\\xac</a>\\n    \\xc2\\xb7 <a href=\"https://www.douban.com/about?policy=disclaimer\">\\xe5\\x85\\x8d\\xe8\\xb4\\xa3\\xe5\\xa3\\xb0\\xe6\\x98\\x8e</a>\\n    \\n    \\xc2\\xb7 <a href=\"https://help.douban.com/?app=main\" target=\"_blank\">\\xe5\\xb8\\xae\\xe5\\x8a\\xa9\\xe4\\xb8\\xad\\xe5\\xbf\\x83</a>\\n    \\xc2\\xb7 <a href=\"https://www.douban.com/doubanapp/\">\\xe7\\xa7\\xbb\\xe5\\x8a\\xa8\\xe5\\xba\\x94\\xe7\\x94\\xa8</a>\\n    ";

    lzw_encode(s, &dict);
    return 0;
}
