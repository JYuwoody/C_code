#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;

    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    
    if(leftMax > rightMax)
    {
        return leftMax+1;
    }
    else
    {
        return rightMax+1;
    }

}

void main()
{   
    
    return; 
}