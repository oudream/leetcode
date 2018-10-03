#include "global.h"

using namespace std;

class SolutionLeetcode {
public:
    int maxArea(vector<int>& height)
    {
        int maxarea = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxarea = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
    
};

int test_maxArea1(int argc, const char *argv[])
{
    int heights[] = {1,8,6,2,5,4,8,3,7};
    vector<int> height(heights, heights + (sizeof(heights) / sizeof(int)));
    // oudream
    Solution solution;
    int r1 = solution.maxArea(height);
    fn_print(fn_format("oudream.maxArea.return = %d !", r1));
    return TRUE;
}
int fn_test_maxArea1 = fn_add_case("maxArea1", test_maxArea1);
