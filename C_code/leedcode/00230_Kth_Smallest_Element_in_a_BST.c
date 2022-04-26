#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/*
230. Kth Smallest Element in a BST
Medium

6931

128

Add to List

Share
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//return k  *size=tree size
int sreach(struct TreeNode* root, int k, int* size)
{
    int result;
    int leftSize = 0, rightSize = 0;
    if(root == NULL)
    {
        *size = 0;
        return -1;
    }

    
    result = sreach(root->left, k, &leftSize);

    if(k <= leftSize)
    {
        *size = leftSize;
        return result;
    }
    if(k == leftSize+1)
    {
        *size = leftSize + 1;
        return root->val;
    }
    result = sreach(root->right, k-(leftSize+1), &rightSize);
    *size = leftSize + 1 + rightSize;

    return result;
}
int kthSmallest(struct TreeNode* root, int k){
    int size;
    return sreach(root, k, &size);
}




/*
Runtime: 9 ms, faster than 81.36% of C online submissions for Kth Smallest Element in a BST.
Memory Usage: 10.3 MB, less than 68.74% of C online submissions for Kth Smallest Element in a BST.
*/
int getSize(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return getSize(root->left) + 1 + getSize(root->right);
}
int kthSmallest1(struct TreeNode* root, int k){
    int leftSize = getSize(root->left);

    if(k <= leftSize)
    {
        return kthSmallest1(root->left, k);
    }
    if(k == leftSize+1)
    {
        return root->val;
    }
    return kthSmallest1(root->right, k-(leftSize+1));
}
