#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//https://hackmd.io/@sysprog/c-linked-list
/*02095. Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105
*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


/*
Runtime: 537 ms, faster than 55.63% of C online submissions for Delete the Middle Node of a Linked List.
Memory Usage: 78 MB, less than 17.36% of C online submissions for Delete the Middle Node of a Linked List.
*/
struct ListNode *deleteMiddle1(struct ListNode *head) {
    struct ListNode **indir = &head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next) 
        indir = &(*indir)->next;
    *indir = (*indir)->next;
    return head;
}

/*
Runtime: 742 ms, faster than 16.40% of C online submissions for Delete the Middle Node of a Linked List.
Memory Usage: 78 MB, less than 17.36% of C online submissions for Delete the Middle Node of a Linked List.
*/
struct ListNode *deleteMiddle2(struct ListNode *head) {
    if (!head->next) return NULL;
    
    struct ListNode **indir = &head, *prev = NULL;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next) {
        prev = *indir;
        indir = &(*indir)->next;
    }
    struct ListNode *next = (*indir)->next;
    free(*indir);
    prev->next = next; // *indir = next
    return head;
}

/*
Runtime: 491 ms, faster than 75.24% of C online submissions for Delete the Middle Node of a Linked List.
Memory Usage: 77.9 MB, less than 61.09% of C online submissions for Delete the Middle Node of a Linked List.
*/
struct ListNode *deleteMiddle3(struct ListNode *head) {
    struct ListNode **indir = &head;
    for (struct ListNode *fast = head; fast && fast->next; fast = fast->next->next)
        indir = &(*indir)->next;
    struct ListNode *del = *indir;
    *indir = (*indir)->next;
    free(del);
    return head;
}