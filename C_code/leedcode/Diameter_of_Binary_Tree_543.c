#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int MaxDepth(struct TreeNode* root)
{
    if(root == NULL) return 0;

    int leftMax = MaxDepth(root->left);
    int rightMax = MaxDepth(root->right);
    
    if(leftMax > rightMax)
    {
        return leftMax+1;
    }
    else
    {
        return rightMax+1;
    }
}
 
int diameterOfBinaryTree(struct TreeNode* root)
{
    if(root == NULL) return 0;

    int middle = MaxDepth(root->left) + MaxDepth(root->right) ;
    //all left
    int left = diameterOfBinaryTree(root->left);

    //all right
    int right = diameterOfBinaryTree(root->right);

    int max = middle;
    if(right > max)
        max = right;
    if(left > max)
        max = left;

    return max;
}

void main()
{   
    
    return; 
}
