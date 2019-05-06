#include "global.h"

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for(int i = 0;i < A.size();i++){
            auto maxPosition = max_element(A.begin(), A.end() - i);
            result.push_back(maxPosition  - A.begin() + 1);
            result.push_back(A.size() - i);
            reverse(A.begin(),maxPosition+1);
            reverse(A.begin(),A.end() - i);
        }
        return result;
    }

};

int test_pancakeSort1(int argc, const char *argv[])
{
    Solution solution;

    int arr1[] = {3,2,4,1};
    int arr2[] = {1, 3, 2};
    int arr3[] = {13, 14, 15, 33, 33, 33, 34, 34, 36, 78, 78, 78, 90, 90};
    int arr4[] = {13, 14, 15, 33, 34, 36, 78, 90};

    string sMessage;
    //
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> r1 = solution.pancakeSort(nums1);
    sMessage = "";
    for (int i = 0; i < r1.size(); ++i)
    {
        sMessage += fn_format(" %d", r1[i]);
    }
    fn_print(string("oudream.pancakeSort return: ") + sMessage);

    return TRUE;
}
int fn_test_pancakeSort1 = fn_add_case("pancakeSort1", test_pancakeSort1);
