#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 0;
        return r;
    }
    
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[j] != nums[i])
                nums[++j] = nums[i];
        return j+1;
    }

};

int test_removeDuplicates1(int argc, const char *argv[])
{
    Solution solution;

    int arr1[] = {13, 14, 15, 33, 34, 36, 78, 78, 90, 90};
    int arr2[] = {13, 14, 14, 14, 15, 33, 34, 36, 78, 78, 90, 90};
    int arr3[] = {13, 14, 15, 33, 33, 33, 34, 34, 36, 78, 78, 78, 90, 90};
    int arr4[] = {13, 14, 15, 33, 34, 36, 78, 90};

    //
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    int r1 = solution.removeDuplicates(nums1);
    fn_print(fn_format("oudream.removeDuplicates new array size: %d",r1));
    //
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    int r2 = solution.removeDuplicates(nums2);
    fn_print(fn_format("oudream.removeDuplicates new array size: %d",r2));
    //
    vector<int> nums3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    int r3 = solution.removeDuplicates(nums3);
    fn_print(fn_format("oudream.removeDuplicates new array size: %d",r3));
    //
    vector<int> nums4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    int r4 = solution.removeDuplicates(nums4);
    fn_print(fn_format("oudream.removeDuplicates new array size: %d",r4));

    return TRUE;
}
int fn_test_removeDuplicates1 = fn_add_case("removeDuplicates1", test_removeDuplicates1);
