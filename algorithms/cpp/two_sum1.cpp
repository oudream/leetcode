//
// Created by oudream on 2018/9/20.
//

#include "global.h"

using namespace std;

/**
 * haoel
 * @param numbers
 * @param target
 * @return
 */
vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, int> m;
    vector<int> result;
    for(int i=0; i<numbers.size(); i++){
        // not found the second one
        if (m.find(numbers[i])==m.end() ) {
            // store the first one poisition into the second one's key
            m[target - numbers[i]] = i;
        }else {
            // found the second one
            result.push_back(m[numbers[i]]+1);
            result.push_back(i+1);
            break;
        }
    }
    return result;
}

/**
 * oudream
 * @param numbers
 * @param target
 * @return
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            // not found the second one
            int a = nums[i];
            map<int, int>::const_iterator it = m.find(a);
            if (it != m.end())
            {
                int iPos2 = i;
                int iPos1 = it->second;
                result.push_back(iPos1);
                result.push_back(iPos2);
                break;
            }
            else
            {
                m[target-a] = i;
            }
        }
        return result;
    }
};

int test_twoSum1(int argc, const char * argv[])
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums2 (nums, nums + sizeof(nums) / sizeof(int) );
    vector<int> r = twoSum(nums2, target);
    fn_print(fn_format("haoel.twoSum.return.size=%d, items:", r.size()));
    for (int i = 0; i < r.size(); ++i)
    {
        fn_print(fn_format("%d", r[i]));
    }
    Solution solution;
    vector<int> r2 = solution.twoSum(nums2, target);
    fn_print(fn_format("oudream.twoSum.return.size=%d, items:", r2.size()));
    for (int i = 0; i < r2.size(); ++i)
    {
        fn_print(fn_format("%d", r2[i]));
    }
    return TRUE;
}
int fn_test_twoSum1 = fn_add_case("twoSum1", test_twoSum1);

int test_twoSum2(int argc, const char * argv[])
{
    int nums[] = {20, 1 , 11, 12, 15, 45, 63, 3, 32, 23};
    int target = 34;
    vector<int> nums2 (nums, nums + sizeof(nums) / sizeof(int) );
    vector<int> r = twoSum(nums2, target);
    fn_print(fn_format("haoel.twoSum.return.size=%d, items:", r.size()));
    for (int i = 0; i < r.size(); ++i)
    {
        fn_print(fn_format("%d", r[i]));
    }
    Solution solution;
    vector<int> r2 = solution.twoSum(nums2, target);
    fn_print(fn_format("oudream.twoSum.return.size=%d, items:", r2.size()));
    for (int i = 0; i < r2.size(); ++i)
    {
        fn_print(fn_format("%d", r2[i]));
    }
    return TRUE;
}
int fn_test_twoSum2 = fn_add_case("twoSum2", test_twoSum2);

