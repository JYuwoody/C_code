#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

//https://hackmd.io/@sysprog/c-linked-list
/*00021. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/
/*
Runtime: 267 ms, faster than 81.82% of C online submissions for Online Stock Span.
Memory Usage: 64 MB, less than 18.18% of C online submissions for Online Stock Span.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


/*
Runtime: 6 ms, faster than 45.62% of C online submissions for Merge Two Sorted Lists.
Memory Usage: 6.3 MB, less than 27.60% of C online submissions for Merge Two Sorted Lists.
*/

struct ListNode *mergeTwoLists1(struct ListNode *L1, struct ListNode *L2) {
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
untime: 5 ms, faster than 51.54% of C online submissions for Merge Two Sorted Lists.
Memory Usage: 6.1 MB, less than 70.58% of C online submissions for Merge Two Sorted Lists.
*/
struct ListNode *mergeTwoLists2(struct ListNode *L1, struct ListNode *L2) { 
    struct ListNode *head;
    struct ListNode **ptr = &head;
    for (; L1 && L2; ptr = &(*ptr)->next) {
        if (L1->val < L2->val) {
            *ptr = L1;
            L1 = L1->next;
        } else {
            *ptr = L2;
            L2 = L2->next;
        }
    }
    *ptr = (struct ListNode *)((uintptr_t) L1 | (uintptr_t) L2);
    return head;
}

/*best
Runtime: 5 ms, faster than 51.54% of C online submissions for Merge Two Sorted Lists.
Memory Usage: 6 MB, less than 96.34% of C online submissions for Merge Two Sorted Lists.
*/
struct ListNode *mergeTwoLists(struct ListNode *L1, struct ListNode *L2) {
    struct ListNode *head = NULL, **ptr = &head, **node;

    for (node = NULL; L1 && L2; *node = (*node)->next) {
        node = (L1->val < L2->val) ? &L1: &L2;
        *ptr = *node;
        ptr = &(*ptr)->next;
    }
    *ptr = (struct ListNode *)((uintptr_t) L1 | (uintptr_t) L2);
    return head;
}
