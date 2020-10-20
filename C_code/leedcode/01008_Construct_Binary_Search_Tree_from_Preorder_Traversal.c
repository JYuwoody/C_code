#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//1008. Construct Binary Search Tree from Preorder Traversal
/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize);
struct TreeNode* bstFromPreorderRange(int* preorder, int start, int end);

void main()
{


    return; 
}


struct TreeNode* bstFromPreorderRange(int* preorder, int start, int end)
{
    int i = 0;

    if (start >= end) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    int m = start;

    //preorder[i] = 10;
    //range [start,end)
    root->val = preorder[start];
    //search bigger than preorder[start] that is right tree sub root.

    while (m < end && preorder[m] <= root->val)
    {
        m++;
    } 

    //letf: preorder[1] ~ preorder[i-1]
    //right:preorder[i] ~ preorder[preorderSize]
    root->left = bstFromPreorderRange(preorder, start+1, m);
    root->right = bstFromPreorderRange(preorder, m, end);
    return root;

}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    // preorder [8,5,1,7,10,12] preorderSize = 6

    return bstFromPreorderRange(preorder, 0, preorderSize);
}