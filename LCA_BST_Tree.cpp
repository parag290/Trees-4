/***
 * 
 * Leetcode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 
 * Explaination : video : https://www.youtube.com/watch?v=dWPqzURG9lA
 * 
 * Time Complexity : O(log n)               <------ due to binary traversal
 * Space complexity : O(height of tree)     <------ for stack depth
 * 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        } else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};