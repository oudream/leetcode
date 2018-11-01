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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }

};

int test_removeElement1(int argc, const char *argv[])
{
    Solution solution;

    int arr1[] = {13, 14, 15, 33, 34, 36, 78, 78, 90, 90};
    int arr2[] = {13, 14, 14, 14, 15, 33, 34, 36, 78, 78, 90, 90};
    int arr3[] = {13, 14, 15, 33, 33, 33, 34, 34, 36, 78, 78, 78, 90, 90};
    int arr4[] = {13, 14, 15, 33, 34, 36, 78, 90};

    int val1 = 36;

    //
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    int r1 = solution.removeElement(nums1, val1);
    fn_print(fn_format("oudream.removeElement new array size: %d",r1));
    //
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    int r2 = solution.removeElement(nums2, val1);
    fn_print(fn_format("oudream.removeElement new array size: %d",r2));
    //
    vector<int> nums3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    int r3 = solution.removeElement(nums3, val1);
    fn_print(fn_format("oudream.removeElement new array size: %d",r3));
    //
    vector<int> nums4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    int r4 = solution.removeElement(nums4, val1);
    fn_print(fn_format("oudream.removeElement new array size: %d",r4));

    return TRUE;
}
int fn_test_removeElement1 = fn_add_case("removeElement1", test_removeElement1);
