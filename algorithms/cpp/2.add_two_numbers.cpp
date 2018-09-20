#include "global.h"

using namespace std;

///**
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {}
};
/**/

class SolutionHaoel {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * oLn1 = l1;
        ListNode * oLn2 = l2;
        int iValue1 = 0;
        int iValue2 = 0;
        int iCarry = 0;
        int iSum = 0;

        ListNode * r = NULL;
        ListNode ** ln_1 = &r;

        while (oLn1!=NULL || oLn2!=NULL)
        {
            iValue1 = getValueAndMoveNext(oLn1);
            iValue2 = getValueAndMoveNext(oLn2);

            iSum = iCarry + iValue1 + iValue2;

            ListNode * lnn = new ListNode(iSum%10);
            *ln_1 = lnn;
            ln_1 = (&lnn->next);

            iCarry = iSum/10;
        }

        if (iCarry == 1)
        {
            ListNode * lnn = new ListNode(iCarry);
            *ln_1 = lnn;
        }

        return r;
    }
private:
    int getValueAndMoveNext(ListNode* & ooLn)
    {
        int x = 0;
        if (ooLn != NULL)
        {
            x = ooLn->val;
            ooLn = ooLn->next;
        }
        return x;
    }

};

/**
 * ln_1 = & lnn->next;
 * @param pValue
 * @param iLength
 * @return
 */
ListNode * fn_createListNode(int * pValue, int iLength)
{
    ListNode * r = NULL;
    ListNode ** ln_1 = &r;
    for (int i = 0; i < iLength; ++i)
    {
        ListNode *lnn = new ListNode(*pValue++);
        *ln_1 = lnn;
        ln_1 = & lnn->next;
    }
    return r;
}

/**
 * tmp = a; a = b; b = tmp
 * @param pValue
 * @param iLength
 * @return
 */
ListNode * fn_createListNode2(int * pValue, int iLength)
{
    ListNode * ln_1 = iLength > 0 ? (new ListNode(*pValue++)) : NULL;
    ListNode * r = ln_1;
    for (int i = 1; i < iLength; ++i)
    {
        ListNode *lnn = new ListNode(*pValue++);
        ln_1->next = lnn;
        ln_1 = lnn;
    }
    return r;
}

//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
int test_addTwoNumbers1(int argc, const char * argv[])
{
    int nums1[] = {2, 4, 3};
    int nums2[] = {5, 6, 4};
    ListNode *l1 = fn_createListNode(nums1, sizeof(nums1) / sizeof(int));
    ListNode *l2 = fn_createListNode(nums2, sizeof(nums2) / sizeof(int));
    int iIndex = 0;
    // haoel
    SolutionHaoel solutionHaoel;
    ListNode *r = solutionHaoel.addTwoNumbers(l1, l2);
    fn_print("haoel.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    // oudream
    Solution solution;
    ListNode *r2 = solution.addTwoNumbers(l1, l2);
    fn_print("oudream.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r2; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    return TRUE;
}
int fn_test_addTwoNumbers1 = fn_add_case("addTwoNumbers1", test_addTwoNumbers1);

//
//Input: (9 -> 9 -> 9) + (9 -> 9 -> 9)
//Output: 1 -> 9 -> 9 -> 8
//Explanation: 999 + 999 = 1998.
int test_addTwoNumbers2(int argc, const char * argv[])
{
    int nums1[] = {9, 9, 9};
    int nums2[] = {9, 9, 9};
    ListNode *l1 = fn_createListNode(nums1, sizeof(nums1) / sizeof(int));
    ListNode *l2 = fn_createListNode(nums2, sizeof(nums2) / sizeof(int));
    int iIndex = 0;
    // haoel
    SolutionHaoel solutionHaoel;
    ListNode *r = solutionHaoel.addTwoNumbers(l1, l2);
    fn_print("haoel.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    // oudream
    Solution solution;
    ListNode *r2 = solution.addTwoNumbers(l1, l2);
    fn_print("oudream.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r2; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    return TRUE;
}
int fn_test_addTwoNumbers2 = fn_add_case("addTwoNumbers2", test_addTwoNumbers2);

//
//Input: (6 -> 1 -> 1) + ( 1 -> 9)
//Output: 6 -> 3 -> 0
//Explanation: 999 + 999 = 1998.
int test_addTwoNumbers3(int argc, const char * argv[])
{
    int nums1[] = {6, 1, 1};
    int nums2[] = {1, 9};
    ListNode *l1 = fn_createListNode(nums1, sizeof(nums1) / sizeof(int));
    ListNode *l2 = fn_createListNode(nums2, sizeof(nums2) / sizeof(int));
    int iIndex = 0;
    // haoel
    SolutionHaoel solutionHaoel;
    ListNode *r = solutionHaoel.addTwoNumbers(l1, l2);
    fn_print("haoel.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    // oudream
    Solution solution;
    ListNode *r2 = solution.addTwoNumbers(l1, l2);
    fn_print("oudream.addTwoNumbers.return, items:");
    iIndex = 0;
    for (ListNode * l = r2; l != NULL ; l = l->next)
    {
        fn_print(fn_format("index%d=%d", iIndex, l->val));
        iIndex++;
    }
    return TRUE;
}
int fn_test_addTwoNumbers3 = fn_add_case("addTwoNumbers3", test_addTwoNumbers3);
