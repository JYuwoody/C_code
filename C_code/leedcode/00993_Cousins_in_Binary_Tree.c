#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
/*993. Cousins in Binary Tree
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isCousins(struct TreeNode* root, int x, int y);
int getDepth(struct TreeNode* root, int target);
int getParent(struct TreeNode* root, int target);

void main()
{

    return; 
}

int getDepth(struct TreeNode* root, int target)
{
    if(root == NULL) return -1;
    if( root->val == target ) return 0;

    if( root->val != target )
    {
        int leftDepth  = getDepth(root->left, target);
        int rightDepth = getDepth(root->right, target);
        if(leftDepth != -1)
            return leftDepth + 1;
        if(rightDepth != -1)
            return rightDepth + 1;
    }
    return -1;
}

int getParent(struct TreeNode* root, int target)
{
    if(root == NULL) 
        return 0;

    if( root->left == NULL && root->right == NULL && root->val != target ) 
        return 0;

    if( root->left != NULL && root->left->val == target)
        return root->val;
    if( root->right != NULL && root->right->val == target)
        return root->val;

    int leftParent = getParent(root->left, target);
    int rightParent = getParent(root->right, target);

    if(leftParent != 0)
        return leftParent;
    if(rightParent != 0)
        return rightParent;

    return 0;
}


bool isCousins(struct TreeNode* root, int x, int y)
{
    int xDepth = getDepth(root, x);
    int yDepth = getDepth(root, y);
    int xParent = getParent(root, x);
    int yParent = getParent(root, y);

    return xDepth == yDepth && xParent != yParent;
}

//==================================================================
typedef struct{
    int depth;
    int parent;
}Info;

Info getParent1(struct TreeNode* root, int target, int parent)
{
    if(root == NULL) 
        return (Info) {-1, 0};

    if(  root->val == target ) 
        return (Info) {0, parent};

    Info left = getParent1(root->left, target, root->val);
    Info right = getParent1(root->right, target, root->val);

    if(left.parent != 0)
        return (Info) {left.depth+1, left.parent};
    if(right.parent != 0)
        return (Info) {right.depth+1, right.parent};

    return (Info) {-1, 0};
}

bool isCousins_beter(struct TreeNode* root, int x, int y)
{
    Info xInfo = getParent1(root, x, 0);
    Info yInfo = getParent1(root, y, 0);
    return xInfo.depth == yInfo.depth && xInfo.parent != yInfo.parent;
}
//==================================================================
