#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
//1008. Construct Binary Search Tree from Preorder Traversal

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize);

void main()
{


    return; 
}


struct TreeNode* bstFromPreorderRange(int* preorder, int start, int end)
{

}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    // preorder [8,5,1,7,10,12] preorderSize = 6

    // root 
    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = preorder[0];
    //preorder[i] = 10;
    //range [start,end)
    //letf: preorder[1] ~ preorder[i]
    //right:preorder[i] ~ preorder[preorderSize

    root->letf = bstFromPreorderRange();
    root->right = bstFromPreorderRange();



}
