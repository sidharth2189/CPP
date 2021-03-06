/*

DIAMETER OF A BINARY TREE

Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Get height of a node
    int heightofNode(TreeNode* node) {
        if (node == NULL) {return -1;}
        int left_height, right_height;
        left_height = heightofNode(node->left);
        right_height = heightofNode(node->right);
        return max(left_height, right_height)+1;
    }
    
    // Loop through nodes and get diameter at each node
    int findFullNode(TreeNode *node) 
    { 
        int dia_left = 0, dia_right = 0;
        if (node != NULL) 
        { 
            int dia_left_temp = findFullNode(node->left); 
            dia_left = heightofNode(node->left) + 1 + heightofNode(node->right) + 1;
            if (dia_left_temp > dia_left) {dia_left = dia_left_temp;}
            int dia_right_temp = findFullNode(node->right);
            dia_right = heightofNode(node->left) + 1 + heightofNode(node->right) + 1;
            if (dia_right_temp > dia_right) {dia_right = dia_right_temp;}
        }
        return max(dia_left, dia_right);
    }
    
    // Get diameter of binary search tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0, temp;
        if (root != NULL)
        {
            diameter = findFullNode(root);
        }
        return diameter;
    }
};