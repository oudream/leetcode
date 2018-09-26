#include "global.h"

using namespace std;

class SolutionHaoel {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return 0;
    }

};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        { // to ensure m<=n
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i])
            {
                iMin = i + 1; // i is too small
            }
            else if (i > iMin && nums1[i - 1] > nums2[j])
            {
                iMax = i - 1; // i is too big
            }
            else
            { // i is perfect
                int maxLeft = 0;
                if (i == 0)
                { maxLeft = nums2[j - 1]; }
                else if (j == 0)
                { maxLeft = nums1[i - 1]; }
                else
                { maxLeft = max(nums1[i - 1], nums2[j - 1]); }
                if ((m + n) % 2 == 1)
                { return maxLeft; }

                int minRight = 0;
                if (i == m)
                { minRight = nums2[j]; }
                else if (j == n)
                { minRight = nums1[i]; }
                else
                { minRight = min(nums2[j], nums1[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

};

int median_of_two_sorted_arrays1(int argc, const char *argv[])
{
    int nums3[] = {2, 7, 11, 15, 16, 17, 18};
    int nums4[] = {1, 3, 5, 9, 12, 13};

    // haoel
    SolutionHaoel solutionHaoel;
    vector<int> nums1(nums3, nums3 + sizeof(nums3) / sizeof(int));
    vector<int> nums2(nums4, nums4 + sizeof(nums4) / sizeof(int));
    double r1 = solutionHaoel.findMedianSortedArrays(nums1, nums2);
    fn_print(fn_format("haoel.findMedianSortedArrays.return=%f !", r1));

    // oudream
    Solution solution;
    double r2  = solution.findMedianSortedArrays(nums1, nums2);
    fn_print(fn_format("oudream.findMedianSortedArrays.return=%f !", r2));
    return TRUE;
}
int fn_median_of_two_sorted_arrays1 = fn_add_case("findMedianSortedArrays1", median_of_two_sorted_arrays1);
