#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

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