#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//https://hackmd.io/@sysprog/c-linked-list
/*00023. Merge k Sorted Lists   need 00021
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *ptr = head;
    while (L1 && L2) {
        if (L1->val < L2->val) {
            ptr->next = L1;
            L1 = L1->next;
        } else {
            ptr->next = L2;
            L2 = L2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = L1 ? L1 : L2;
    return head->next;
}

/*
Runtime: 260 ms, faster than 43.63% of C online submissions for Merge k Sorted Lists.
Memory Usage: 8.2 MB, less than 71.28% of C online submissions for Merge k Sorted Lists.
*/
struct ListNode *mergeKLists1(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    for (int i = 1; i < listsSize; i++)
        lists[0] = mergeTwoLists(lists[0], lists[i]);
    return lists[0];
}


/*
Runtime: 21 ms, faster than 77.99% of C online submissions for Merge k Sorted Lists.
Memory Usage: 8.3 MB, less than 58.39% of C online submissions for Merge k Sorted Lists.
*/

struct ListNode *mergeKLists2(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    
    while (listsSize > 1) {
       for (int i = 0, j = listsSize - 1; i < j; i++, j--)
           lists[i] = mergeTwoLists(lists[i], lists[j]);
        listsSize = (listsSize + 1) / 2;
    }
    
    return lists[0];
}

/*
Runtime: 27 ms, faster than 67.92% of C online submissions for Merge k Sorted Lists.
Memory Usage: 8.3 MB, less than 58.39% of C online submissions for Merge k Sorted Lists.
*/
struct ListNode *mergeKLists3(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    
    for (int interval = 1; interval < listsSize; interval *= 2) 
        for (int i = 0; i + interval < listsSize; i += interval * 2)
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
    
    return lists[0];
}

/*best
Runtime: 15 ms, faster than 93.69% of C online submissions for Merge k Sorted Lists.
Memory Usage: 8.1 MB, less than 71.28% of C online submissions for Merge k Sorted Lists.
*/
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (!listsSize)
        return NULL;
    if (listsSize <= 1)
        return *lists;

    int m = listsSize >> 1;
    struct ListNode *left = mergeKLists(lists, m);
    struct ListNode *right = mergeKLists(lists + m, listsSize - m);

    return mergeTwoLists(left, right);
}
