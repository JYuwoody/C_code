#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

//!
//?
//todo
//@param
//* 

/*226. Invert Binary Tree
Easy
Topics
Companies
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

// Runtime: 0ms, Beats: 100.00%
// Memory: 6.05MB, Beats: 12.27%

Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* MyinvertTree(struct TreeNode* root) {
    if( root == NULL)
        return NULL;
    struct TreeNode *temp = root->left;

    root->left = root->right;
    root->right = temp;
    MyinvertTree(root->left);
    MyinvertTree(root->right);

    return root;
}
 
struct TreeNode* invertTree(struct TreeNode* root) {
    return MyinvertTree(root);
}


// python3
// # Definition for a binary tree node.
// # class TreeNode:
// #     def __init__(self, val=0, left=None, right=None):
// #         self.val = val
// #         self.left = left
// #         self.right = right

// # 00226_Invert_Binary_Tree.py
// # Runtime: 40ms, Beats:21.79%
// # Memory: 16.46MB, Beats: 87.30%
// def invertTree(root):
//     if root == None:
//         return None
//     root.left, root.right = root.right, root.left
//     invertTree(root.left)
//     invertTree(root.right)
//     return root


// class Solution:
//     def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
//         return invertTree(root)
        