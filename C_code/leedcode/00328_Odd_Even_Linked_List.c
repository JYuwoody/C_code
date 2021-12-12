#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

n == number of nodes in the linked list
0 <= n <= 104
-106 <= Node.val <= 106
*/


#define INT_MIN -2147483647-1

struct ListNode* oddEvenList(struct ListNode* head);


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


void main()
{
    printf("woody\n");

    return; 
}


struct ListNode* oddEvenList(struct ListNode* head)
{
    
}



/*
Runtime: 4 ms, faster than 90.41% of C online submissions for Odd Even Linked List.
Memory Usage: 6.9 MB, less than 73.80% of C online submissions for Odd Even Linked List.
*/
struct ListNode* oddEvenList1(struct ListNode* head)
{
    if(head == NULL) return NULL;
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *even_head = head->next;

    while(even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = even_head;

    return head;
}