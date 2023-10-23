/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** allPossibleFBT(int n, int* returnSize){
    if(n % 2 == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    if(n == 1) {
        struct TreeNode* root = malloc(sizeof(struct TreeNode));
        root->val = 0;
        root->left = NULL;
        root->right = NULL;
        
        struct TreeNode** result = malloc(sizeof(struct TreeNode*));
        result[0] = root;
        
        *returnSize = 1;
        return result;
    }
    
    int totalSize = 0;
    struct TreeNode** result = NULL;
    
    for(int i = 1; i < n; i+=2) {
        int leftSize, rightSize;
        struct TreeNode** leftTrees = allPossibleFBT(i, &leftSize);
        struct TreeNode** rightTrees = allPossibleFBT(n-i-1, &rightSize);
        
        totalSize += leftSize * rightSize;
        result = realloc(result, totalSize * sizeof(struct TreeNode*));
        
        for(int l = 0; l < leftSize; l++) {
            for(int r = 0; r < rightSize; r++) {
                struct TreeNode* root = malloc(sizeof(struct TreeNode));
                root->val = 0;
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                
                result[totalSize - leftSize*rightSize + l*rightSize + r] = root;
            }
        }
        
        free(leftTrees);
        free(rightTrees);
    }
    
    *returnSize = totalSize;
    return result;
}
