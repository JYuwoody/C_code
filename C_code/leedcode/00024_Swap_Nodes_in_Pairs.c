#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Swap Nodes in Pairs.
Memory Usage: 5.7 MB, less than 83.81% of C online submissions for Swap Nodes in Pairs.
*/
struct ListNode* swapPairs(struct ListNode* head){
    for (struct ListNode **node = &head; *node && (*node)->next; node = &((*node)->next->next)) 
    {
        struct ListNode *tmp = *node;
        *node = (*node)->next;

        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
   return head;
}