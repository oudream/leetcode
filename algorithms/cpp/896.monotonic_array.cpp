#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 0;
        return r;
    }
    
};

class Solution1 {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) return true;
        int k;
        for (k = 1; k < A.size(); ++k)
            if (A[k] != A[k-1])
                break;
        bool c = A[k] > A[k-1];
        for (int i = k+1; i < A.size(); ++i)
            if (c != (A[i] > A[i-1]) && A[i] != A[i-1])
                return false;
        return true;
    }

};

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int store = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            int c = (A[i+1] - A[i]);
            if (c > 0)
                c = 1;
            else if (c < 0) c = -1;
            if (c != 0) {
                if (c != store && store != 0)
                    return false;
                store = c;
            }
        }

        return true;
    }

};

int test_isMonotonic1(int argc, const char *argv[])
{
    Solution solution;

    int arr1[] = {6, 5, 4, 4};
    int arr2[] = {1, 3, 2};
    int arr3[] = {13, 14, 15, 33, 33, 33, 34, 34, 36, 78, 78, 78, 90, 90};
    int arr4[] = {13, 14, 15, 33, 34, 36, 78, 90};

    int val1 = 36;

    //
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    bool r1 = solution.isMonotonic(nums1);
    fn_print(fn_format("oudream.isMonotonic return: %d",r1));
    //
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    bool r2 = solution.isMonotonic(nums2);
    fn_print(fn_format("oudream.isMonotonic return: %d",r2));
    //
    vector<int> nums3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    bool r3 = solution.isMonotonic(nums3);
    fn_print(fn_format("oudream.isMonotonic return: %d",r3));
    //
    vector<int> nums4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    bool r4 = solution.isMonotonic(nums4);
    fn_print(fn_format("oudream.isMonotonic return: %d",r4));

    return TRUE;
}
int fn_test_isMonotonic1 = fn_add_case("isMonotonic1", test_isMonotonic1);
