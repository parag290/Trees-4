
/***
 * 
 * Leetcode : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * 
 * https://www.youtube.com/watch?v=dWPqzURG9lA
 * 
*/


/**
 * Apporach 1 : Using backtracing
 * path to both nodes are stored and then two vectors will be used to find the LCA
 * 
*/


class Solution {
    vector<TreeNode*>pPath;
    vector<TreeNode*>qPath;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path;
        helper(root, p, q, path);
        int i = 0;
        while(i < pPath.size() && i < qPath.size()){
            if(pPath[i] != qPath[i]) break;
            i++;
        }
        return pPath[i-1];
            
    }

    void helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>&path){
        if(root == nullptr) return;
        path.push_back(root);
        if(root == p){
            vector<TreeNode*>temp(path);
            pPath = temp;
        } else if (root == q){
            vector<TreeNode*>temp(path);
            qPath = temp;
        }
        helper(root->left, p, q, path);
        helper(root->right, p, q, path);
        path.pop_back();
    }
};



/**
 * 
 * Apporach 2 : Optimized solution 
 * 
 * 
 * 
 * 
*/


class Solution {
    vector<TreeNode*>pPath;
    vector<TreeNode*>qPath;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr && right == nullptr) return nullptr;
        else if(left!= nullptr && right == nullptr) return left;
        else if(left == nullptr && right != nullptr) return right;
        return root;
            
    }
};