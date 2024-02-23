#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
 
/*82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
 */


struct ListNode {
    int val;
    struct ListNode *next;
};



// case 1 >>>
// Runtime: 4 ms, Beats: 56.91%
// Memory: 6.52 MB, Beats: 50.69%

// Function to create a new node
void newNode(struct ListNode** list,int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if(*list==NULL)
    {
        *list=node;
    }
    else
    {
        struct ListNode* temp=*list;
        while(temp != NULL &&temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
    }
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* result = NULL;    
    struct ListNode* curr = head;
    int tempvaule = -200;

    while(curr != NULL)
    {
        if(curr->next == NULL && curr->val != tempvaule)
        {
            newNode(&result, curr->val);
            break;
        }
        else if((curr->next != NULL && curr->val != curr->next->val) && tempvaule != curr->val)
        {
            // printf("%d %p\n", curr->val, tempresult);
            newNode(&result, curr->val);
        }
        else
        {
            tempvaule = curr->val;
        }

        curr = curr->next;
    }

    return result;
}
// case 1 <<<

// case 2 >>>
// Runtime: 6 ms, Beats: 47.23%
// Memory: 6.65 MB, Beats: 49.31%
void newNode(struct ListNode** list, int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if (*list == NULL) {
        *list = node;
    } else {
        struct ListNode* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* result = NULL;
    struct ListNode* curr = head;
    int prevValue = -200;

    while (curr != NULL) {
        if (curr->val != prevValue && (curr->next == NULL || curr->next->val != curr->val)) {
            newNode(&result, curr->val);
        }
        prevValue = curr->val;
        curr = curr->next;
    }

    return result;
}
// case 2 <<<

// case 3 >>>
// Runtime: 3 ms, Beats: 77.65%
// Memory: 6.61 MB, Beats: 49.31%
void insert(struct ListNode** list, int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if (*list == NULL) {
        *list = node;
    } else {
        struct ListNode* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode* result = NULL;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    while (curr != NULL) {
        int val = curr->val;
        if ((curr->next == NULL || curr->next->val != val) && (prev == NULL || prev->val != val)) {
            insert(&result, val);
        }
        prev = curr;
        curr = curr->next;
    }

    return result;
}
// case 3 <<<
