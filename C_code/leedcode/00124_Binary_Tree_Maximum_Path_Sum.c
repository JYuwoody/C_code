#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//124. Binary Tree Maximum Path Sum
/*
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxPathSum(struct TreeNode* root);

void main()
{

    return; 
}

int max3 (int a, int b, int c)
{
    int max = a;
    if(b > max)
    {
        max = b;
    }
    if(c > max)
    {
        max = c;
    }

    return max;
}
//只能從root開始的最大路徑和(可以不選都不選為0)
int maxPathSumRoot(struct TreeNode* root)
{
    if(root == NULL) return 0;
    //root 
    // letf
    int left = maxPathSumRoot(root->left) + root->val;
    // right
    int right = maxPathSumRoot(root->right) + root->val;
    //no root
    int result = 0;

    return max3(result, left, right);
}

int maxPathSum(struct TreeNode* root)
{
    int result, left, right;

    if(root == NULL)  return INT_MIN;
    //經過中間的最大路徑
    result = root->val + maxPathSumRoot(root->left) + maxPathSumRoot(root->right);

    //不經過中間的最大路徑
    //max is left
    left = maxPathSum(root->left);

    //max is right
    right = maxPathSum(root->right);


    return max3(result, left, right);
}

