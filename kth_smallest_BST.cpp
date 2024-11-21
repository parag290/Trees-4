/**
 * Leetcode : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * 
 * https://www.youtube.com/watch?v=dWPqzURG9lA
 * 
 * 
*/

class Solution {
    int val = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return val;
    }

    void helper(TreeNode* root, int& k){
        if(root == nullptr) return;

        helper(root->left, k);
        k--;
        if(k == 0) {
            val = root->val;
            return;
        }
        helper(root->right, k);

    }

};