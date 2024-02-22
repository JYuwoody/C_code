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

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* tempresult = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = head;
    struct ListNode* result = tempresult;

    while(curr != NULL)
    {
        if(curr->next != NULL && curr->val != curr->next->val)
        {
            // printf("%d %p\n", curr->val, tempresult);
            tempresult->next = newNode(curr->val);
            tempresult = tempresult->next;
            if(curr->next->next == NULL)
            {
                curr = curr->next;
                tempresult->next = newNode(curr->val);
                break;
            }
        }

        curr = curr->next;
        
    }

    result = result->next;

    return result;
}


//>>>
typedef struct Node{
    int num;
    struct Node *next;
}Node;

void insert(Node **list,int num)
{
    Node *head =(Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    head->num=num;
    head->next=NULL;
    
    if(*list==NULL)
    {
        *list=head;
    }
    else
    {
        Node *temp=*list;
        while(temp != NULL &&temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
    }
}

Node* deleteDuplicates(Node *list)
{
    if (list == NULL) {
        return NULL; // Return NULL if the list is empty
    }
    Node *temp=list;
    int problematic =-200;
    Node *newNode=NULL;
    while(temp!=NULL)
    {
        if (temp->next == NULL)
        {
            if (temp->num != problematic)
            {
                insert(&newNode, temp->num); // Insert the last non-duplicate node
            }
            break; // Exit the loop since we've reached the end of the list
        }
        else if( temp->num!=temp->next->num && temp->num!=problematic)
        {
            insert(&newNode,temp->num);
        }
        else
        {
            problematic=temp->num;
        }
        temp=temp->next;
    }
    return newNode;
}
//<<<
